#include "apue.h"

int
main(void)
{
    char name[L_tmpnam], line[MAXLINE];
    FILE *fp;
    printf("%s\n", tmpnam(NULL));
    printf("%s\n", tmpnam(name));
    if ((fp = tmpfile()) == NULL) {
        err_sys("failed to create tmpfile");
    }
    fputs("one line to tmp file\n", fp);
    rewind(fp);
    if (fgets(line, sizeof(line), fp) == NULL) {
        err_sys("unable to null");
    }
    fputs(line, stdout);
    exit(0);
}
