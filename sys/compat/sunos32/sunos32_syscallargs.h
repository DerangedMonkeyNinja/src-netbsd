/* $NetBSD: sunos32_syscallargs.h,v 1.28 2015/03/07 16:41:54 christos Exp $ */

/*
 * System call argument lists.
 *
 * DO NOT EDIT-- this file is automatically generated.
 * created from;	NetBSD: syscalls.master,v 1.22 2013/11/07 19:37:19 njoly Exp
 */

#ifndef _SUNOS32_SYS_SYSCALLARGS_H_
#define	_SUNOS32_SYS_SYSCALLARGS_H_

#define	SUNOS32_SYS_MAXSYSARGS	8

#undef	syscallarg
#define	syscallarg(x)							\
	union {								\
		register32_t pad;						\
		struct { x datum; } le;					\
		struct { /* LINTED zero array dimension */		\
			int8_t pad[  /* CONSTCOND */			\
				(sizeof (register32_t) < sizeof (x))	\
				? 0					\
				: sizeof (register32_t) - sizeof (x)];	\
			x datum;					\
		} be;							\
	}

#undef check_syscall_args
#define check_syscall_args(call) /*LINTED*/ \
	typedef char call##_check_args[sizeof (struct call##_args) \
		<= SUNOS32_SYS_MAXSYSARGS * sizeof (register32_t) ? 1 : -1];

struct netbsd32_exit_args;

struct netbsd32_read_args;

struct netbsd32_write_args;

struct sunos32_sys_open_args {
	syscallarg(const netbsd32_charp) path;
	syscallarg(int) flags;
	syscallarg(int) mode;
};
check_syscall_args(sunos32_sys_open)

struct netbsd32_close_args;

struct sunos32_sys_wait4_args {
	syscallarg(int) pid;
	syscallarg(netbsd32_intp) status;
	syscallarg(int) options;
	syscallarg(netbsd32_rusagep_t) rusage;
};
check_syscall_args(sunos32_sys_wait4)

struct sunos32_sys_creat_args {
	syscallarg(const netbsd32_charp) path;
	syscallarg(int) mode;
};
check_syscall_args(sunos32_sys_creat)

struct netbsd32_link_args;

struct netbsd32_unlink_args;

struct sunos32_sys_execv_args {
	syscallarg(const netbsd32_charp) path;
	syscallarg(netbsd32_charpp) argp;
};
check_syscall_args(sunos32_sys_execv)

struct netbsd32_chdir_args;

struct sunos32_sys_mknod_args {
	syscallarg(const netbsd32_charp) path;
	syscallarg(int) mode;
	syscallarg(int) dev;
};
check_syscall_args(sunos32_sys_mknod)

struct netbsd32_chmod_args;

struct netbsd32_chown_args;

struct netbsd32_break_args;

struct compat_43_netbsd32_olseek_args;

struct netbsd32_setuid_args;

struct sunos32_sys_stime_args {
	syscallarg(sunos32_time_tp) tp;
};
check_syscall_args(sunos32_sys_stime)

struct sunos32_sys_ptrace_args {
	syscallarg(int) req;
	syscallarg(pid_t) pid;
	syscallarg(netbsd32_caddr_t) addr;
	syscallarg(int) data;
	syscallarg(netbsd32_charp) addr2;
};
check_syscall_args(sunos32_sys_ptrace)

struct sunos32_sys_access_args {
	syscallarg(const netbsd32_charp) path;
	syscallarg(int) flags;
};
check_syscall_args(sunos32_sys_access)

struct netbsd32_kill_args;

struct sunos32_sys_stat_args {
	syscallarg(const netbsd32_charp) path;
	syscallarg(netbsd32_stat43p_t) ub;
};
check_syscall_args(sunos32_sys_stat)

struct sunos32_sys_lstat_args {
	syscallarg(const netbsd32_charp) path;
	syscallarg(netbsd32_stat43p_t) ub;
};
check_syscall_args(sunos32_sys_lstat)

struct netbsd32_dup_args;

struct netbsd32_profil_args;

struct netbsd32_setgid_args;

struct netbsd32_acct_args;

struct sunos32_sys_mctl_args {
	syscallarg(netbsd32_voidp) addr;
	syscallarg(int) len;
	syscallarg(int) func;
	syscallarg(netbsd32_voidp) arg;
};
check_syscall_args(sunos32_sys_mctl)

struct sunos32_sys_ioctl_args {
	syscallarg(int) fd;
	syscallarg(netbsd32_u_long) com;
	syscallarg(netbsd32_caddr_t) data;
};
check_syscall_args(sunos32_sys_ioctl)

struct sunos32_sys_reboot_args {
	syscallarg(int) howto;
	syscallarg(netbsd32_charp) bootstr;
};
check_syscall_args(sunos32_sys_reboot)

struct netbsd32_symlink_args;

struct netbsd32_readlink_args;

struct sunos32_sys_execve_args {
	syscallarg(const netbsd32_charp) path;
	syscallarg(netbsd32_charpp) argp;
	syscallarg(netbsd32_charpp) envp;
};
check_syscall_args(sunos32_sys_execve)

struct netbsd32_umask_args;

struct netbsd32_chroot_args;

struct compat_43_netbsd32_fstat43_args;

struct sunos32_sys_omsync_args {
	syscallarg(netbsd32_caddr_t) addr;
	syscallarg(netbsd32_size_t) len;
	syscallarg(int) flags;
};
check_syscall_args(sunos32_sys_omsync)

struct netbsd32_sbrk_args;

struct netbsd32_sstk_args;

struct sunos32_sys_mmap_args {
	syscallarg(netbsd32_voidp) addr;
	syscallarg(netbsd32_size_t) len;
	syscallarg(int) prot;
	syscallarg(int) flags;
	syscallarg(int) fd;
	syscallarg(netbsd32_long) pos;
};
check_syscall_args(sunos32_sys_mmap)

struct netbsd32_ovadvise_args;

struct netbsd32_munmap_args;

struct netbsd32_mprotect_args;

struct netbsd32_madvise_args;

struct netbsd32_mincore_args;

struct netbsd32_getgroups_args;

struct netbsd32_setgroups_args;

struct sunos32_sys_setpgrp_args {
	syscallarg(int) pid;
	syscallarg(int) pgid;
};
check_syscall_args(sunos32_sys_setpgrp)

struct compat_50_netbsd32_setitimer_args;

struct compat_12_netbsd32_oswapon_args;

struct compat_50_netbsd32_getitimer_args;

struct compat_43_netbsd32_ogethostname_args;

struct compat_43_netbsd32_osethostname_args;

struct netbsd32_dup2_args;

struct sunos32_sys_fcntl_args {
	syscallarg(int) fd;
	syscallarg(int) cmd;
	syscallarg(netbsd32_voidp) arg;
};
check_syscall_args(sunos32_sys_fcntl)

struct compat_50_netbsd32_select_args;

struct netbsd32_fsync_args;

struct netbsd32_setpriority_args;

struct sunos32_sys_socket_args {
	syscallarg(int) domain;
	syscallarg(int) type;
	syscallarg(int) protocol;
};
check_syscall_args(sunos32_sys_socket)

struct netbsd32_connect_args;

struct compat_43_netbsd32_oaccept_args;

struct netbsd32_getpriority_args;

struct compat_43_netbsd32_osend_args;

struct compat_43_netbsd32_orecv_args;

struct netbsd32_bind_args;

struct sunos32_sys_setsockopt_args {
	syscallarg(int) s;
	syscallarg(int) level;
	syscallarg(int) name;
	syscallarg(netbsd32_caddr_t) val;
	syscallarg(int) valsize;
};
check_syscall_args(sunos32_sys_setsockopt)

struct netbsd32_listen_args;

struct sunos32_sys_sigvec_args {
	syscallarg(int) signum;
	syscallarg(netbsd32_sigvecp_t) nsv;
	syscallarg(netbsd32_sigvecp_t) osv;
};
check_syscall_args(sunos32_sys_sigvec)

struct compat_43_netbsd32_sigblock_args;

struct compat_43_netbsd32_sigsetmask_args;

struct sunos32_sys_sigsuspend_args {
	syscallarg(int) mask;
};
check_syscall_args(sunos32_sys_sigsuspend)

struct compat_43_netbsd32_osigstack_args;

struct compat_43_netbsd32_orecvmsg_args;

struct compat_43_netbsd32_osendmsg_args;

struct compat_50_netbsd32_gettimeofday_args;

struct compat_50_netbsd32_getrusage_args;

struct netbsd32_getsockopt_args;

struct netbsd32_readv_args;

struct netbsd32_writev_args;

struct compat_50_netbsd32_settimeofday_args;

struct netbsd32_fchown_args;

struct netbsd32_fchmod_args;

struct compat_43_netbsd32_orecvfrom_args;

struct netbsd32_setreuid_args;

struct netbsd32_setregid_args;

struct netbsd32_rename_args;

struct compat_43_netbsd32_otruncate_args;

struct compat_43_netbsd32_oftruncate_args;

struct netbsd32_flock_args;

struct netbsd32_sendto_args;

struct netbsd32_shutdown_args;

struct sunos32_sys_socketpair_args {
	syscallarg(int) domain;
	syscallarg(int) type;
	syscallarg(int) protocol;
	syscallarg(netbsd32_intp) rsv;
};
check_syscall_args(sunos32_sys_socketpair)

struct netbsd32_mkdir_args;

struct netbsd32_rmdir_args;

struct compat_50_netbsd32_utimes_args;

struct sunos32_sys_sigreturn_args {
	syscallarg(netbsd32_sigcontextp_t) sigcntxp;
};
check_syscall_args(sunos32_sys_sigreturn)

struct compat_50_netbsd32_adjtime_args;

struct compat_43_netbsd32_ogetpeername_args;

struct sunos32_sys_getrlimit_args {
	syscallarg(u_int) which;
	syscallarg(netbsd32_orlimitp_t) rlp;
};
check_syscall_args(sunos32_sys_getrlimit)

struct sunos32_sys_setrlimit_args {
	syscallarg(u_int) which;
	syscallarg(netbsd32_orlimitp_t) rlp;
};
check_syscall_args(sunos32_sys_setrlimit)

struct compat_43_netbsd32_killpg_args;

struct compat_43_netbsd32_ogetsockname_args;

struct netbsd32_poll_args;

struct compat_43_netbsd32_ogetdirentries_args;

struct sunos32_sys_statfs_args {
	syscallarg(const netbsd32_charp) path;
	syscallarg(sunos32_statfsp_t) buf;
};
check_syscall_args(sunos32_sys_statfs)

struct sunos32_sys_fstatfs_args {
	syscallarg(int) fd;
	syscallarg(sunos32_statfsp_t) buf;
};
check_syscall_args(sunos32_sys_fstatfs)

struct sunos32_sys_unmount_args {
	syscallarg(netbsd32_charp) path;
};
check_syscall_args(sunos32_sys_unmount)

struct compat_30_sys_getfh_args;

struct compat_09_netbsd32_ogetdomainname_args;

struct compat_09_netbsd32_osetdomainname_args;

struct sunos32_sys_quotactl_args {
	syscallarg(int) cmd;
	syscallarg(netbsd32_charp) special;
	syscallarg(int) uid;
	syscallarg(netbsd32_caddr_t) addr;
};
check_syscall_args(sunos32_sys_quotactl)

struct sunos32_sys_exportfs_args {
	syscallarg(netbsd32_charp) path;
	syscallarg(netbsd32_charp) ex;
};
check_syscall_args(sunos32_sys_exportfs)

struct sunos32_sys_mount_args {
	syscallarg(netbsd32_charp) type;
	syscallarg(netbsd32_charp) path;
	syscallarg(int) flags;
	syscallarg(netbsd32_caddr_t) data;
};
check_syscall_args(sunos32_sys_mount)

struct sunos32_sys_ustat_args {
	syscallarg(int) dev;
	syscallarg(sunos32_ustatp_t) buf;
};
check_syscall_args(sunos32_sys_ustat)
#ifdef SYSVSEM

struct compat_10_netbsd32_semsys_args;
#else
#endif
#ifdef SYSVMSG

struct compat_10_netbsd32_msgsys_args;
#else
#endif
#ifdef SYSVSHM

struct compat_10_netbsd32_shmsys_args;
#else
#endif

struct sunos32_sys_auditsys_args {
	syscallarg(netbsd32_charp) record;
};
check_syscall_args(sunos32_sys_auditsys)

struct sunos32_sys_getdents_args {
	syscallarg(int) fd;
	syscallarg(netbsd32_charp) buf;
	syscallarg(int) nbytes;
};
check_syscall_args(sunos32_sys_getdents)

struct netbsd32_fchdir_args;

struct netbsd32_fchroot_args;

struct sunos32_sys_sigpending_args {
	syscallarg(netbsd32_intp) mask;
};
check_syscall_args(sunos32_sys_sigpending)

struct netbsd32_setpgid_args;

struct netbsd32_pathconf_args;

struct netbsd32_fpathconf_args;

struct sunos32_sys_sysconf_args {
	syscallarg(int) name;
};
check_syscall_args(sunos32_sys_sysconf)

struct sunos32_sys_uname_args {
	syscallarg(sunos32_utsnamep_t) name;
};
check_syscall_args(sunos32_sys_uname)

/*
 * System call prototypes.
 */

int	sys_nosys(struct lwp *, const void *, register_t *);

int	netbsd32_exit(struct lwp *, const struct netbsd32_exit_args *, register_t *);

int	sys_fork(struct lwp *, const void *, register_t *);

int	netbsd32_read(struct lwp *, const struct netbsd32_read_args *, register_t *);

int	netbsd32_write(struct lwp *, const struct netbsd32_write_args *, register_t *);

int	sunos32_sys_open(struct lwp *, const struct sunos32_sys_open_args *, register_t *);

int	netbsd32_close(struct lwp *, const struct netbsd32_close_args *, register_t *);

int	sunos32_sys_wait4(struct lwp *, const struct sunos32_sys_wait4_args *, register_t *);

int	sunos32_sys_creat(struct lwp *, const struct sunos32_sys_creat_args *, register_t *);

int	netbsd32_link(struct lwp *, const struct netbsd32_link_args *, register_t *);

int	netbsd32_unlink(struct lwp *, const struct netbsd32_unlink_args *, register_t *);

int	sunos32_sys_execv(struct lwp *, const struct sunos32_sys_execv_args *, register_t *);

int	netbsd32_chdir(struct lwp *, const struct netbsd32_chdir_args *, register_t *);

int	sunos32_sys_mknod(struct lwp *, const struct sunos32_sys_mknod_args *, register_t *);

int	netbsd32_chmod(struct lwp *, const struct netbsd32_chmod_args *, register_t *);

int	netbsd32_chown(struct lwp *, const struct netbsd32_chown_args *, register_t *);

int	netbsd32_break(struct lwp *, const struct netbsd32_break_args *, register_t *);

int	compat_43_netbsd32_olseek(struct lwp *, const struct compat_43_netbsd32_olseek_args *, register_t *);

int	sys_getpid_with_ppid(struct lwp *, const void *, register_t *);

int	netbsd32_setuid(struct lwp *, const struct netbsd32_setuid_args *, register_t *);

int	sys_getuid_with_euid(struct lwp *, const void *, register_t *);

int	sunos32_sys_stime(struct lwp *, const struct sunos32_sys_stime_args *, register_t *);

int	sunos32_sys_ptrace(struct lwp *, const struct sunos32_sys_ptrace_args *, register_t *);

int	sunos32_sys_access(struct lwp *, const struct sunos32_sys_access_args *, register_t *);

int	sys_sync(struct lwp *, const void *, register_t *);

int	netbsd32_kill(struct lwp *, const struct netbsd32_kill_args *, register_t *);

int	sunos32_sys_stat(struct lwp *, const struct sunos32_sys_stat_args *, register_t *);

int	sunos32_sys_lstat(struct lwp *, const struct sunos32_sys_lstat_args *, register_t *);

int	netbsd32_dup(struct lwp *, const struct netbsd32_dup_args *, register_t *);

int	sys_pipe(struct lwp *, const void *, register_t *);

int	netbsd32_profil(struct lwp *, const struct netbsd32_profil_args *, register_t *);

int	netbsd32_setgid(struct lwp *, const struct netbsd32_setgid_args *, register_t *);

int	sys_getgid_with_egid(struct lwp *, const void *, register_t *);

int	netbsd32_acct(struct lwp *, const struct netbsd32_acct_args *, register_t *);

int	sunos32_sys_mctl(struct lwp *, const struct sunos32_sys_mctl_args *, register_t *);

int	sunos32_sys_ioctl(struct lwp *, const struct sunos32_sys_ioctl_args *, register_t *);

int	sunos32_sys_reboot(struct lwp *, const struct sunos32_sys_reboot_args *, register_t *);

int	netbsd32_symlink(struct lwp *, const struct netbsd32_symlink_args *, register_t *);

int	netbsd32_readlink(struct lwp *, const struct netbsd32_readlink_args *, register_t *);

int	sunos32_sys_execve(struct lwp *, const struct sunos32_sys_execve_args *, register_t *);

int	netbsd32_umask(struct lwp *, const struct netbsd32_umask_args *, register_t *);

int	netbsd32_chroot(struct lwp *, const struct netbsd32_chroot_args *, register_t *);

int	compat_43_netbsd32_fstat43(struct lwp *, const struct compat_43_netbsd32_fstat43_args *, register_t *);

int	compat_43_sys_getpagesize(struct lwp *, const void *, register_t *);

int	sunos32_sys_omsync(struct lwp *, const struct sunos32_sys_omsync_args *, register_t *);

int	sys_vfork(struct lwp *, const void *, register_t *);

int	netbsd32_sbrk(struct lwp *, const struct netbsd32_sbrk_args *, register_t *);

int	netbsd32_sstk(struct lwp *, const struct netbsd32_sstk_args *, register_t *);

int	sunos32_sys_mmap(struct lwp *, const struct sunos32_sys_mmap_args *, register_t *);

int	netbsd32_ovadvise(struct lwp *, const struct netbsd32_ovadvise_args *, register_t *);

int	netbsd32_munmap(struct lwp *, const struct netbsd32_munmap_args *, register_t *);

int	netbsd32_mprotect(struct lwp *, const struct netbsd32_mprotect_args *, register_t *);

int	netbsd32_madvise(struct lwp *, const struct netbsd32_madvise_args *, register_t *);

int	sunos32_sys_vhangup(struct lwp *, const void *, register_t *);

int	netbsd32_mincore(struct lwp *, const struct netbsd32_mincore_args *, register_t *);

int	netbsd32_getgroups(struct lwp *, const struct netbsd32_getgroups_args *, register_t *);

int	netbsd32_setgroups(struct lwp *, const struct netbsd32_setgroups_args *, register_t *);

int	sys_getpgrp(struct lwp *, const void *, register_t *);

int	sunos32_sys_setpgrp(struct lwp *, const struct sunos32_sys_setpgrp_args *, register_t *);

int	compat_50_netbsd32_setitimer(struct lwp *, const struct compat_50_netbsd32_setitimer_args *, register_t *);

int	compat_12_netbsd32_oswapon(struct lwp *, const struct compat_12_netbsd32_oswapon_args *, register_t *);

int	compat_50_netbsd32_getitimer(struct lwp *, const struct compat_50_netbsd32_getitimer_args *, register_t *);

int	compat_43_netbsd32_ogethostname(struct lwp *, const struct compat_43_netbsd32_ogethostname_args *, register_t *);

int	compat_43_netbsd32_osethostname(struct lwp *, const struct compat_43_netbsd32_osethostname_args *, register_t *);

int	compat_43_sys_getdtablesize(struct lwp *, const void *, register_t *);

int	netbsd32_dup2(struct lwp *, const struct netbsd32_dup2_args *, register_t *);

int	sunos32_sys_fcntl(struct lwp *, const struct sunos32_sys_fcntl_args *, register_t *);

int	compat_50_netbsd32_select(struct lwp *, const struct compat_50_netbsd32_select_args *, register_t *);

int	netbsd32_fsync(struct lwp *, const struct netbsd32_fsync_args *, register_t *);

int	netbsd32_setpriority(struct lwp *, const struct netbsd32_setpriority_args *, register_t *);

int	sunos32_sys_socket(struct lwp *, const struct sunos32_sys_socket_args *, register_t *);

int	netbsd32_connect(struct lwp *, const struct netbsd32_connect_args *, register_t *);

int	compat_43_netbsd32_oaccept(struct lwp *, const struct compat_43_netbsd32_oaccept_args *, register_t *);

int	netbsd32_getpriority(struct lwp *, const struct netbsd32_getpriority_args *, register_t *);

int	compat_43_netbsd32_osend(struct lwp *, const struct compat_43_netbsd32_osend_args *, register_t *);

int	compat_43_netbsd32_orecv(struct lwp *, const struct compat_43_netbsd32_orecv_args *, register_t *);

int	netbsd32_bind(struct lwp *, const struct netbsd32_bind_args *, register_t *);

int	sunos32_sys_setsockopt(struct lwp *, const struct sunos32_sys_setsockopt_args *, register_t *);

int	netbsd32_listen(struct lwp *, const struct netbsd32_listen_args *, register_t *);

int	sunos32_sys_sigvec(struct lwp *, const struct sunos32_sys_sigvec_args *, register_t *);

int	compat_43_netbsd32_sigblock(struct lwp *, const struct compat_43_netbsd32_sigblock_args *, register_t *);

int	compat_43_netbsd32_sigsetmask(struct lwp *, const struct compat_43_netbsd32_sigsetmask_args *, register_t *);

int	sunos32_sys_sigsuspend(struct lwp *, const struct sunos32_sys_sigsuspend_args *, register_t *);

int	compat_43_netbsd32_osigstack(struct lwp *, const struct compat_43_netbsd32_osigstack_args *, register_t *);

int	compat_43_netbsd32_orecvmsg(struct lwp *, const struct compat_43_netbsd32_orecvmsg_args *, register_t *);

int	compat_43_netbsd32_osendmsg(struct lwp *, const struct compat_43_netbsd32_osendmsg_args *, register_t *);

int	compat_50_netbsd32_gettimeofday(struct lwp *, const struct compat_50_netbsd32_gettimeofday_args *, register_t *);

int	compat_50_netbsd32_getrusage(struct lwp *, const struct compat_50_netbsd32_getrusage_args *, register_t *);

int	netbsd32_getsockopt(struct lwp *, const struct netbsd32_getsockopt_args *, register_t *);

int	netbsd32_readv(struct lwp *, const struct netbsd32_readv_args *, register_t *);

int	netbsd32_writev(struct lwp *, const struct netbsd32_writev_args *, register_t *);

int	compat_50_netbsd32_settimeofday(struct lwp *, const struct compat_50_netbsd32_settimeofday_args *, register_t *);

int	netbsd32_fchown(struct lwp *, const struct netbsd32_fchown_args *, register_t *);

int	netbsd32_fchmod(struct lwp *, const struct netbsd32_fchmod_args *, register_t *);

int	compat_43_netbsd32_orecvfrom(struct lwp *, const struct compat_43_netbsd32_orecvfrom_args *, register_t *);

int	netbsd32_setreuid(struct lwp *, const struct netbsd32_setreuid_args *, register_t *);

int	netbsd32_setregid(struct lwp *, const struct netbsd32_setregid_args *, register_t *);

int	netbsd32_rename(struct lwp *, const struct netbsd32_rename_args *, register_t *);

int	compat_43_netbsd32_otruncate(struct lwp *, const struct compat_43_netbsd32_otruncate_args *, register_t *);

int	compat_43_netbsd32_oftruncate(struct lwp *, const struct compat_43_netbsd32_oftruncate_args *, register_t *);

int	netbsd32_flock(struct lwp *, const struct netbsd32_flock_args *, register_t *);

int	netbsd32_sendto(struct lwp *, const struct netbsd32_sendto_args *, register_t *);

int	netbsd32_shutdown(struct lwp *, const struct netbsd32_shutdown_args *, register_t *);

int	sunos32_sys_socketpair(struct lwp *, const struct sunos32_sys_socketpair_args *, register_t *);

int	netbsd32_mkdir(struct lwp *, const struct netbsd32_mkdir_args *, register_t *);

int	netbsd32_rmdir(struct lwp *, const struct netbsd32_rmdir_args *, register_t *);

int	compat_50_netbsd32_utimes(struct lwp *, const struct compat_50_netbsd32_utimes_args *, register_t *);

int	sunos32_sys_sigreturn(struct lwp *, const struct sunos32_sys_sigreturn_args *, register_t *);

int	compat_50_netbsd32_adjtime(struct lwp *, const struct compat_50_netbsd32_adjtime_args *, register_t *);

int	compat_43_netbsd32_ogetpeername(struct lwp *, const struct compat_43_netbsd32_ogetpeername_args *, register_t *);

int	compat_43_sys_gethostid(struct lwp *, const void *, register_t *);

int	sunos32_sys_getrlimit(struct lwp *, const struct sunos32_sys_getrlimit_args *, register_t *);

int	sunos32_sys_setrlimit(struct lwp *, const struct sunos32_sys_setrlimit_args *, register_t *);

int	compat_43_netbsd32_killpg(struct lwp *, const struct compat_43_netbsd32_killpg_args *, register_t *);

int	compat_43_netbsd32_ogetsockname(struct lwp *, const struct compat_43_netbsd32_ogetsockname_args *, register_t *);

int	netbsd32_poll(struct lwp *, const struct netbsd32_poll_args *, register_t *);

int	compat_43_netbsd32_ogetdirentries(struct lwp *, const struct compat_43_netbsd32_ogetdirentries_args *, register_t *);

int	sunos32_sys_statfs(struct lwp *, const struct sunos32_sys_statfs_args *, register_t *);

int	sunos32_sys_fstatfs(struct lwp *, const struct sunos32_sys_fstatfs_args *, register_t *);

int	sunos32_sys_unmount(struct lwp *, const struct sunos32_sys_unmount_args *, register_t *);

int	compat_30_sys_getfh(struct lwp *, const struct compat_30_sys_getfh_args *, register_t *);

int	compat_09_netbsd32_ogetdomainname(struct lwp *, const struct compat_09_netbsd32_ogetdomainname_args *, register_t *);

int	compat_09_netbsd32_osetdomainname(struct lwp *, const struct compat_09_netbsd32_osetdomainname_args *, register_t *);

int	sunos32_sys_quotactl(struct lwp *, const struct sunos32_sys_quotactl_args *, register_t *);

int	sunos32_sys_exportfs(struct lwp *, const struct sunos32_sys_exportfs_args *, register_t *);

int	sunos32_sys_mount(struct lwp *, const struct sunos32_sys_mount_args *, register_t *);

int	sunos32_sys_ustat(struct lwp *, const struct sunos32_sys_ustat_args *, register_t *);

#ifdef SYSVSEM
int	compat_10_netbsd32_semsys(struct lwp *, const struct compat_10_netbsd32_semsys_args *, register_t *);

#else
#endif
#ifdef SYSVMSG
int	compat_10_netbsd32_msgsys(struct lwp *, const struct compat_10_netbsd32_msgsys_args *, register_t *);

#else
#endif
#ifdef SYSVSHM
int	compat_10_netbsd32_shmsys(struct lwp *, const struct compat_10_netbsd32_shmsys_args *, register_t *);

#else
#endif
int	sunos32_sys_auditsys(struct lwp *, const struct sunos32_sys_auditsys_args *, register_t *);

int	sunos32_sys_getdents(struct lwp *, const struct sunos32_sys_getdents_args *, register_t *);

int	sys_setsid(struct lwp *, const void *, register_t *);

int	netbsd32_fchdir(struct lwp *, const struct netbsd32_fchdir_args *, register_t *);

int	netbsd32_fchroot(struct lwp *, const struct netbsd32_fchroot_args *, register_t *);

int	sunos32_sys_sigpending(struct lwp *, const struct sunos32_sys_sigpending_args *, register_t *);

int	netbsd32_setpgid(struct lwp *, const struct netbsd32_setpgid_args *, register_t *);

int	netbsd32_pathconf(struct lwp *, const struct netbsd32_pathconf_args *, register_t *);

int	netbsd32_fpathconf(struct lwp *, const struct netbsd32_fpathconf_args *, register_t *);

int	sunos32_sys_sysconf(struct lwp *, const struct sunos32_sys_sysconf_args *, register_t *);

int	sunos32_sys_uname(struct lwp *, const struct sunos32_sys_uname_args *, register_t *);

#endif /* _SUNOS32_SYS_SYSCALLARGS_H_ */
