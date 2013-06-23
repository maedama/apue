#include "apue.h"
#include <fcntl.h>
#include <utime.h>

int
main( int argc, char *argv[])
{
    int fd;
    char *path;
    struct stat buf;
    struct utimbuf current_utime;
    
    path = argv[1];
    
    if (argc != 2) {
        err_quit("usage: fig4-21 <file_to_truncate>");
    }

    if (stat(path, &buf) < 0 ) {
        /*err_sys(sprintf("failed to read file :%s", argv[1]));*/
        err_sys("failed to read file");
    }
    
    current_utime.actime  = buf.st_atime;
    current_utime.modtime = buf.st_mtime;
    if ( (fd = open(path, O_WRONLY | O_TRUNC)) < 0 ) {
        err_sys("failed to truncate");
    }
    close(fd);
    utime(path, &current_utime);
}
