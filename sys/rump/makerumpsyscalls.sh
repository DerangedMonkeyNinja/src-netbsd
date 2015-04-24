#!/bin/sh
#
#	$NetBSD: makerumpsyscalls.sh,v 1.2 2014/04/27 16:28:21 pooka Exp $
#

#
# This utility generates component-specific initializers for the
# rump kernel syscall vector.
#
# Procedure is:
#   1) edit syscalls.master
#   2) run makesyscalls.sh
#   3) do a build in sys/rump
#   4) run this script
#   5) commit results
#

# default, override by giving argument
LIBDIR=/usr/lib

SYSCOMPONENT_librump=librump/rumpkern/rumpkern_syscalls.c
SYSCOMPONENT_librumpnet=librump/rumpnet/rumpnet_syscalls.c
SYSCOMPONENT_librumpvfs=librump/rumpvfs/rumpvfs_syscalls.c

die ()
{

	echo '>> ERROR:' $*
	exit 1
}

[ -f "./rump.sysmap" ] || die rump.sysmap not found
[ -f "./Makefile.rump" ] || die run script in src/sys/rump
[ -z "${1}" ] || LIBDIR=$1

#
# BEGIN
#

IFS=' '
AWKPROG='BEGIN {
	while ((getline < "rump.sysmap") == 1) {
		if ($2 != "sys_nomodule")
			syscalls[$2] = $1
	}
}

$5 == "GLOBAL" && $7 != "UND" {
	sub("rumpns_", "", $8)
	if (syscalls[$8] != 0)
		results[$8] = 1
}

END {
	for (res in results) {
		printf "%d %s\n", syscalls[res], res | "sort -n"
	}
}
'

SYSCOMP_HDR='/*	$NetBSD: makerumpsyscalls.sh,v 1.2 2014/04/27 16:28:21 pooka Exp $	*/

/* AUTOMATICALLY GENERATED BY makerumpsyscalls.sh */

#include <sys/cdefs.h>
__KERNEL_RCSID(0, "$NetBSD: makerumpsyscalls.sh,v 1.2 2014/04/27 16:28:21 pooka Exp $");

#include <sys/param.h>

#include "rump_private.h"
'

SYSCOMP_BODY='
RUMP_COMPONENT(RUMP_COMPONENT_SYSCALL)
{

	rump_syscall_boot_establish(mysys, __arraycount(mysys));
}'

makesyscomponent ()
{

	echo Generating $1
	exec 3>&1 >${1}

	echo "${SYSCOMP_HDR}"

	echo ${2} | awk '{printf "extern sy_call_t %s;\n", $2}'
	printf '\nstatic const struct rump_onesyscall mysys[] = {\n'
	echo ${2} | awk '{printf "\t{ %d,\t%s },\n", $1, $2}'
	printf '};\n'

	echo "${SYSCOMP_BODY}"

	exec 1>&3
}

sawlibrump=false
for file in ${LIBDIR}/librump*.a ; do
	b=$(basename ${file})
	b=${b%%.*}
	res=$(readelf -W --syms ${file} | awk "${AWKPROG}")
	if [ ! -z "${res}" ]; then
		eval outname=\${SYSCOMPONENT_${b}}
		[ -z "${outname}" ] && die Unknown syscall provider $b
		makesyscomponent $outname "$res"

		[ $b = "librump" ] && sawlibrump=true
	fi
done

${sawlibrump} || die Did not see librump.  Wrong directory?
