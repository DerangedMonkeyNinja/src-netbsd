#include <sys/sysctl.h>

#include "rump_private.h"

/*
 * sysctl helper routine for hw.usermem and hw.usermem64. Values are
 * calculated on the fly based on the amount of total memory and
 * the amount of memory in use.
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
        ui = (rump_physmemlimit - rump_curphysmem);
        node.sysctl_data = &ui;
        break;
    case HW_USERMEM64:
        uq = (u_quad_t)(rump_physmemlimit - rump_curphysmem);
        node.sysctl_data = &uq;
        break;
    default:
        return (EINVAL);
    }

    return (sysctl_lookup(SYSCTLFN_CALL(&node)));
}

SYSCTL_SETUP(sysctl_rump_hw_setup, "sysctl hw tree setup for rump kernels")
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
    u = ((u_int)rump_physmemlimit > UINT_MAX) ? UINT_MAX : rump_physmemlimit;
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
