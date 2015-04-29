#include <sys/sysctl.h>

#include <rump/rumpuser.h>

uint64_t tsc_freq = 0;

SYSCTL_SETUP(sysctl_machdep_setup, "sysctl machdep subtree setup")
{
    tsc_freq = rumpuser_cpu_frequency();

    sysctl_createv(NULL, 0, NULL, NULL,
                   CTLFLAG_PERMANENT,
                   CTLTYPE_NODE, "machdep", NULL,
                   NULL, 0, NULL, 0,
                   CTL_MACHDEP, CTL_EOL);

    sysctl_createv(NULL, 0, NULL, NULL,
                   CTLFLAG_PERMANENT,
                   CTLTYPE_QUAD, "tsc_freq", NULL,
                   NULL, 0, &tsc_freq, 0,
                   CTL_MACHDEP, CTL_CREATE, CTL_EOL);
}
