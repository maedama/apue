#include "apue.h"
#include <fcntl.h>

#define RWRWRW (S_IRUSR|S_IRUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH)

int
main(void)
{
    umask(0);
    if (creat("foo", RWRWRW) < 0) {
        err_sys("create error");
    }
    umask(S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
    if (creat("bar", RWRWRW) < 0 ) {
        err_sys("create error bar");
    }
    exit(0);
}

