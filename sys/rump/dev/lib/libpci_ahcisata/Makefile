# $ NetBSD: Makefile, v 1.0 $
#

RUMPTOP=${TOPRUMP}

.PATH: \
	${RUMPTOP}/../dev/ic \
	${RUMPTOP}/../dev/pci

LIB=		rumpdev_pci_ahcisata
IOCONF=	PCI_AHCISATA.ioconf

SRCS=		ahcisata_at_pci.c
SRCS+=	ahcisata_core.c ahcisata_pci.c

CPPFLAGS+= \
	-I${.CURDIR}/opt \
	-I${RUMPTOP}/librump/rumpkern \
	-I${RUMPTOP}/../dev/ic

.include "${RUMPTOP}/Makefile.rump"
.include <bsd.lib.mk>
.include <bsd.klinks.mk>
