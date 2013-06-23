#include "apue.h"
#include <stdio.h>
#include <fcntl.h>

FILE *mytmpfile(void);

int
main(void)
{
    FILE *fp;
    fp = mytmpfile();
}

FILE *mytmpfile(void) {
    FILE *fp;
    /*
        we should handle seed correctly,
        since this would return same file if we call twice
    */
    fp = fopen(tmpnam(NULL), "rw"); // tmpnam and fopen should be called in the same line to make it atomic
    unlink(tmpnam(NULL)); /* kernel would not removed i-node and data  until process finishes */
    return fp;
}
