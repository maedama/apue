#include "apue.h"
#include <fcntl.h>

int
main (int argc, char *argv[])
{
    char buf[] = "abcde";
    int fd;
    if ( (fd = open("./fsync.txt", O_WRONLY | O_CREAT | O_TRUNC, FILE_MODE )) < 0 ) {
        err_sys("unable to open file");
    }
    if (write(fd, buf, 5) != 5) {
        err_sys("unable to write");
    }

    if (fsync(fd) < 0 ){
        err_sys("unable to sync");
    }
}
