#include "apue.h"
#include <errno.h>
#include <limits.h>

static void pr_sysconf(char *, int);
static void pr_pathconf(char *, char *, int);

int
main(int argc, char *argv[])
{
    if (argc != 2) {
        err_quit ("usage printlimit <dirname>");
    }
#ifdef NAME_MAX
    printf("NAME_MAX is defined to be %d\n", NAME_MAX+0);
#else
    printf("no symbol for NMAE_MAX\n");
#endif
#ifdef _PC_NAME_MAX
    pr_pathconf("NAME_MAX =", argv[1], _PC_NAME_MAX);
#else
    printf ("no symbol for _PC_NAME_MAX");
#endif
#ifdef _SC_ARG_MAX
    pr_sysconf("ARG_MAX =", _SC_ARG_MAX);
#else
    printf("no symbol for _SC_ARG_MAX\n");
#endif
}

static void pr_sysconf(char *mesg, int name)
{
    long val;

    fputs(mesg, stdout);
    errno = 0;
    if (( val = sysconf(name)) < 0) {
        if (errno != 0) {
            if (errno == EINVAL) {
                fputs(" (not supported)\n", stdout);
            } else {
                err_sys("sysconf error");
            }
        } else {
            fputs (" (no limit)\n", stdout);
        }
    } else {
        printf(" %ld\n", val);
    }
}

static void pr_pathconf(char *mesg, char *path, int name)
{
    long val;

    fputs(mesg, stdout);
    errno = 0;
    if (( val = pathconf(path, name)) < 0 ) {
        if (errno != 0) {
            if (errno == EINVAL) {
                fputs(" (not supported)\n", stdout);
            } else {
                err_sys("pathconf error");
            }
        } else {
            fputs(" (no limit)\n", stdout);
        }
    } else {
        printf(" %ld\n", val);
    }
}

