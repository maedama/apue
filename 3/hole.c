#include "apue.h"
#include <fcntl.h>

char buf1[] = "abcdefghij";
char buf2[] = "ABCDEFGHIJ";

int
main(void)
{
    int fd;
    if ( (fd = open("./hole.txt", O_WRONLY | O_CREAT | O_TRUNC, FILE_MODE)) < 0 ) {
        err_sys("file create error");
    }
    if (write(fd, buf1, 10) != 10) {
        err_sys("buf write error");
    }
    if (lseek(STDIN_FILENO, 16384, SEEK_SET) != 16384) {
        err_sys("seek error");
    }
    if (write(fd, buf2, 10) != 10) {
        err_sys("buf write error");
    }
    exit(0);
}

