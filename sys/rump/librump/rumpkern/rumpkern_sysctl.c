#include <sys/types.h>
#include <sys/msgbuf.h>
#include <sys/sysctl.h>

#include "rump_private.h"

static int dcopyout(struct lwp *, const void *, void *, size_t);

static int
dcopyout(struct lwp *l, const void *kaddr, void *uaddr, size_t len)
{
	int error;

	error = copyout(kaddr, uaddr, len);

	return error;
}

static int sysctl_hw_usermem(SYSCTLFN_ARGS);
static int sysctl_msgbuf(SYSCTLFN_ARGS);

SYSCTL_SETUP(sysctl_rump_kern_setup, "sysctl kern subtree setup for rump kernels")
{
    sysctl_createv(NULL, 0, NULL, NULL,
                   CTLFLAG_PERMANENT,
                   CTLTYPE_INT, "msgbufsize",
                   SYSCTL_DESCR("Size of the kernel message buffer"),
                   sysctl_msgbuf, 0, NULL, 0,
                   CTL_KERN, KERN_MSGBUFSIZE, CTL_EOL);

    sysctl_createv(clog, 0, NULL, NULL,
                   CTLFLAG_PERMANENT,
                   CTLTYPE_INT, "msgbuf",
                   SYSCTL_DESCR("Kernel message buffer"),
                   sysctl_msgbuf, 0, NULL, 0,
                   CTL_KERN, KERN_MSGBUF, CTL_EOL);
}

SYSCTL_SETUP(sysctl_rump_hw_setup, "sysctl hw subtree setup for rump kernels")
{
    u_int u;
    u_quad_t q;

    /* hw.ncpu */
    sysctl_createv(NULL, 0, NULL, NULL,
                   CTLFLAG_PERMANENT,
                   CTLTYPE_INT, "ncpu",
                   SYSCTL_DESCR("Number of CPUs configured"),
                   NULL, 0, &ncpu, 0,
                   CTL_HW, HW_NCPU, CTL_EOL);

    /* hw.physmem */
    u = (u_int)((rump_physmemlimit > UINT_MAX) ? UINT_MAX : rump_physmemlimit);
    sysctl_createv(NULL, 0, NULL, NULL,
                   CTLFLAG_PERMANENT|CTLFLAG_IMMEDIATE,
                   CTLTYPE_INT, "physmem",
                   SYSCTL_DESCR("Bytes of physical memory"),
                   NULL, u, NULL, 0,
                   CTL_HW, HW_PHYSMEM, CTL_EOL);

    /* hw.usermem */
    sysctl_createv(NULL, 0, NULL, NULL,
                   CTLFLAG_PERMANENT,
                   CTLTYPE_INT, "usermem",
                   SYSCTL_DESCR("Bytes of non-kernel memory"),
                   sysctl_hw_usermem, 0, NULL, 0,
                   CTL_HW, HW_USERMEM, CTL_EOL);

    /* hw.pagesize */
    sysctl_createv(NULL, 0, NULL, NULL,
                   CTLFLAG_PERMANENT|CTLFLAG_IMMEDIATE,
                   CTLTYPE_INT, "pagesize",
                   SYSCTL_DESCR("Software page size"),
                   NULL, PAGE_SIZE, NULL, 0,
                   CTL_HW, HW_PAGESIZE, CTL_EOL);

    /* hw.alignbytes */
    sysctl_createv(NULL, 0, NULL, NULL,
                   CTLFLAG_PERMANENT|CTLFLAG_IMMEDIATE,
                   CTLTYPE_INT, "alignbytes",
                   SYSCTL_DESCR("Alignment constraint for all possible "
                                "data types"),
                   NULL, ALIGNBYTES, NULL, 0,
                   CTL_HW, HW_ALIGNBYTES, CTL_EOL);

    /* hw.physmem64 */
    q = (u_quad_t)rump_physmemlimit;
    sysctl_createv(NULL, 0, NULL, NULL,
                   CTLFLAG_PERMANENT|CTLFLAG_IMMEDIATE,
                   CTLTYPE_QUAD, "physmem64",
                   SYSCTL_DESCR("Bytes of physical memory"),
                   NULL, q, NULL, 0,
                   CTL_HW, HW_PHYSMEM64, CTL_EOL);

    /* hw.usermem64 */
    sysctl_createv(NULL, 0, NULL, NULL,
                   CTLFLAG_PERMANENT,
                   CTLTYPE_QUAD, "usermem64",
                   SYSCTL_DESCR("Bytes of non-kernel memory"),
                   sysctl_hw_usermem, 0, NULL, 0,
                   CTL_HW, HW_USERMEM64, CTL_EOL);
}

/*
 * sysctl helper routine for kern.msgbufsize and kern.msgbuf. For the
 * former it merely checks the message buffer is set up. For the latter,
 * it also copies out the data if necessary.
 */
static int
sysctl_msgbuf(SYSCTLFN_ARGS)
{
	char *where = oldp;
	size_t len, maxlen;
	long beg, end;
	extern kmutex_t log_lock;

	int error;

	if (!msgbufenabled || msgbufp->msg_magic != MSG_MAGIC) {
		msgbufenabled = 0;
		return (ENXIO);
	}

	switch (rnode->sysctl_num) {
	case KERN_MSGBUFSIZE: {
		struct sysctlnode node = *rnode;
		int msg_bufs = (int)msgbufp->msg_bufs;
		node.sysctl_data = &msg_bufs;
		return (sysctl_lookup(SYSCTLFN_CALL(&node)));
	}
	case KERN_MSGBUF:
		break;
	default:
		return (EOPNOTSUPP);
	}

	if (newp != NULL)
		return (EPERM);

	if (oldp == NULL) {
		/* always return full buffer size */
		*oldlenp = msgbufp->msg_bufs;
		return (0);
	}

	sysctl_unlock();

	/*
	 * First, copy from the write pointer to the end of
	 * message buffer.
	 */
	error = 0;
	mutex_spin_enter(&log_lock);
	maxlen = MIN(msgbufp->msg_bufs, *oldlenp);
	beg = msgbufp->msg_bufx;
	end = msgbufp->msg_bufs;
	mutex_spin_exit(&log_lock);

	while (maxlen > 0) {
		len = MIN(end - beg, maxlen);
		if (len == 0)
			break;
		/* XXX unlocked, but hardly matters. */
		error = dcopyout(l, &msgbufp->msg_bufc[beg], where, len);
		if (error)
			break;
		where += len;
		maxlen -= len;

		/*
		 * ... then, copy from the beginning of message buffer to
		 * the write pointer.
		 */
		beg = 0;
		end = msgbufp->msg_bufx;
	}

	sysctl_relock();
	return (error);
}

/*
 * sysctl helper routine for hw.usermem and hw.usermem64. Values are
 * calculated on the fly based on the amount of memory in use.
 */
static int
sysctl_hw_usermem(SYSCTLFN_ARGS)
{
    u_int ui;
    u_quad_t uq;
    struct sysctlnode node;

    node = *rnode;
    switch (rnode->sysctl_num) {
    case HW_USERMEM:
        ui = (u_int)((rump_curphysmem > UINT_MAX) ? UINT_MAX : rump_curphysmem);
        node.sysctl_data = &ui;
        break;
    case HW_USERMEM64:
        uq = (u_quad_t)(rump_curphysmem);
        node.sysctl_data = &uq;
        break;
    default:
        return (EINVAL);
    }

    return (sysctl_lookup(SYSCTLFN_CALL(&node)));
}
