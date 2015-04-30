#include <sys/cdefs.h>

#include <sys/param.h>
#include <sys/conf.h>
#include <sys/device.h>
#include <sys/bus.h>
#include <sys/stat.h>

#include "ioconf.c"

#include "rump_private.h"
#include "rump_vfs_private.h"

RUMP_COMPONENT(RUMP_COMPONENT_DEV)
{
    extern struct bdevsw wd_bdevsw;
    extern struct cdevsw wd_cdevsw;
    devmajor_t bmaj, cmaj;

    config_init_component(cfdriver_ioconf_ata,
                          cfattach_ioconf_ata,
                          cfdata_ioconf_ata);

    bmaj = cmaj = -1;
    FLAWLESSCALL(devsw_attach("wd", &wd_bdevsw, &bmaj, &wd_cdevsw, &cmaj));

    FLAWLESSCALL(rump_vfs_makedevnodes(S_IFBLK, "/dev/wd0", 'a',
                                       bmaj, 0, 8));
    FLAWLESSCALL(rump_vfs_makedevnodes(S_IFCHR, "/dev/rwd0", 'a',
                                       cmaj, 0, 8));
}
