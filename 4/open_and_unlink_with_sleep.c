#include "apue.h"
#include <fntl.h>

int
main(int argc, char *argv[])
{
    int fd;
    char *path = "./tempfile";
    if ( (fd = open(path, O_RDRW)) < 0 ) {
        err_sys("error on opening a file");
    }
    if ( unlink(path) < 0 ) {
        err_sys("failed to unlink");
    }
    sleep(15); /* This Shoul keep the file data block from being removed */
    exit(0);
}
