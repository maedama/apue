#include "apue.h"
#include <stdio.h>

void pr_stdio(const char *, FILE *);
int
main(void)
{
    FILE *fp;
    fputs("enter any character\n", stdout);
    if (getchar() == EOF) {
        err_sys("getchar error");
    }
    fputs("one line to standard error\n", stdout);
    pr_stdio("stdin", stdin);
    pr_stdio("stdout", stdout);
    pr_stdio("stderr", stderr);
    if ( (fp = fopen("/etc/motd", "r")) == NULL) {
        err_sys("fopen error");
    }
    if (getc(fp) == EOF) {
        err_sys("get c error");
    }
    pr_stdio("/etc/motd", fp);
}

void
pr_stdio(const char *name, FILE *fp)
{
    /*
        non compatible feature, see stdio.h of your system
        i.e /usr/include/stdio.h
    */
    
    printf("stream = %s", name);
    if (fp->_flags & _IONBF) {
        printf(", unbuffered");
    }
    else if (fp->_flags & _IOLBF) {
        printf(", line buffered");
    } else {
        printf(", fully buffered");
    }
    printf(", buffer size = %d\n", fp->_blksize);
}
