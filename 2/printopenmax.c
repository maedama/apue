#include "apue.h"
#include <errno.h>
#include <limits.h>

#ifdef OPEN_MAX
static long openmax = OPEN_MAX;
#else
static long openmax = 0;
#endif

#define OPEN_MAX_GUESS  256

long open_max(void);

int
main(int argc, char *argv[])
{
    printf("maximum open files %ld\n", open_max());
    printf("_SC_OPEN_MAX %d\n", _SC_OPEN_MAX);
}

long open_max(void)
{
    if (openmax == 0) {
        errno = 0;
        if ((openmax = sysconf(_SC_OPEN_MAX)) < 0) {
            if (errno == 0) {
                openmax = OPEN_MAX_GUESS;
            } else {
                err_sys("sysconf error for _SC_OPEN_MAX");
            }
        }
    }
    return openmax;
}
