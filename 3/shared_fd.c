#include "apue.h"
#include <fcntl.h>

int
main(int argc, char *argv[])
{
    char buf[] = "abcd";
    char buf2[] = "efgh";
    int fd;
    int fd2;
    int fd3;
    int fd4;
    /* O_SYNC */
    if ( ( fd = open("./no_append.txt", O_WRONLY | O_CREAT | O_TRUNC | O_SYNC, FILE_MODE)) < 0 ) {
       err_sys("unable to open file"); 
    }

    if ( ( fd2 = open("./no_append.txt", O_WRONLY | O_CREAT | O_TRUNC | O_SYNC, FILE_MODE)) < 0 ) {
       err_sys("unable to open file"); 
    }


    /* These overwrites each others write  */
    if (write(fd, buf, 4) != 4 || write(fd2, buf2, 4) != 4) {
        err_sys("buf write error");
    } 

    /* Write With O_APPEND this is used for example in logging*/
    if ( ( fd3 = open("./o_append.txt", O_WRONLY | O_CREAT | O_TRUNC | O_APPEND, FILE_MODE)) < 0 ) {
       err_sys("unable to open file"); 
    }

    if ( ( fd4 = open("./o_append.txt", O_WRONLY | O_CREAT | O_TRUNC | O_APPEND, FILE_MODE)) < 0 ) {
       err_sys("unable to open file"); 
    }

    if ( write(fd4, buf, 4) != 4 || write(fd3, buf, 4) != 4) {
        err_sys("buf write error");
    }
    exit(0);

}


    

