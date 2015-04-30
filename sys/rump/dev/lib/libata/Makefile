# $ NetBSD: Makefile, v 1.0 $
#

RUMPTOP=${TOPRUMP}

.PATH: \
	${RUMPTOP}/../dev/ata \
	${RUMPTOP}/../dev/ic \

LIB=		rumpdev_ata
IOCONF=	ATA.ioconf

SRCS=		ata_component.c
SRCS+=	wd.c ata.c \
	sata_subr.c satafis_subr.c satapmp_subr.c

CPPFLAGS+= \
	-I${.CURDIR}/opt \
	-I${RUMPTOP}/librump/rumpkern \
	-I${RUMPTOP}/librump/rumpvfs \
	-I${RUMPTOP}/../dev/ic

.include "${RUMPTOP}/Makefile.rump"
.include <bsd.lib.mk>
.include <bsd.klinks.mk>
