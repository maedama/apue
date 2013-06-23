#include "apue.h"
#include <fcntl.h>

int
main(int argc, char *argv[])
{
    char buf[] = "abcd";
    char buf2[] = "efgh";
    int fd;
    /* O_SYNC */
    if ( ( fd = open("./sync_write.txt", O_WRONLY | O_CREAT | O_TRUNC | O_SYNC, FILE_MODE)) < 0 ) {
       err_sys("unable to open file"); 
    }

    /* This overwrides since lseek is not set */
    if (write(fd, buf2, 4) != 4) {
        err_sys("buf write error");
    }
    /* lseek to write properly */
    if (lseek(fd, 4, SEEK_CUR) == -1) {
        err_sys("err on seek");
    }
    if (write(fd, buf, 4) != 4) {
        err_sys("buf write error");
    }


    /* Write With O_APPEND this is used for example in logging*/
    if ( ( fd = open("./o_append.txt", O_WRONLY | O_CREAT | O_TRUNC | O_APPEND, FILE_MODE)) < 0 ) {
       err_sys("unable to open file"); 
    }


    if (write(fd, buf, 4) != 4) {
        err_sys("buf write error");
    }
    if (write(fd, buf2, 4) != 4) {
        err_sys("buf write error");
    }
    exit(0);

}


    

