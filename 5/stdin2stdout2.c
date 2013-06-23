#include "apue.h"

int
main(void)
{
    int c;
    char buf[MAXLINE];
    while ((c = fgets(buf, MAXLINE, stdin)) != NULL) {
        if (fputs(buf, stdout) == EOF) {
            err_sys("putc error");
        }
    }

    if (ferror(stdin)) {
        err_sys("input error");
    }
    exit(0);
}
