#include "apue.h"
#include <fcntl.h>


int
main(int argc, char *argv[])
{
    int flag;
    if (argc != 2) {
        err_quit("usage: getflag.c <fd>");
    }

    printf("acc mode should be 3 and is %d\n", O_ACCMODE);
    if ( (flag = fcntl(atoi(argv[1]), F_GETFL, 0))  < 0) {
        err_sys("fcntl error");
    }
    switch(flag & O_ACCMODE) {
        case O_WRONLY:
            printf("write only");
            break;
        case O_RDONLY:
            printf("read only");
            break;
        case O_RDWR:
            printf("read write");
            break;
        default:
            err_sys("invalid flag");
            break;
    }

    exit(0);
}

