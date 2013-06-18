#include "apue.h"
#include <fcntl.h>

#define BUFSIZE 4096
int
main(void)
{

    int n;
    char buf[BUFSIZE];
    /* read blocks until n byte read or n byte read impossibleness is confirmed(i.e endoffile) */
    while (( n = read(STDIN_FILENO, buf, BUFSIZE)) > 0) {
        if (write(STDOUT_FILENO, buf, n) != n) {
            err_sys("write error");
        }
    }
    if (n < 0) {
        err_sys("read error");
    }
    exit(0);
}
