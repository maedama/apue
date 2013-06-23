#include "apue.h"
#include <stdlib.h>
#include <stdio.h>

static void my_exit1(void);
static void my_exit2(void);

int main
(int argc, char *argv[])
{
    if (argc != 2) {
        err_quit("usage: atexit <1:exit 0:_exit>");
    }
    atexit(my_exit1);
    atexit(my_exit1);
    atexit(my_exit2);
    if (atoi(argv[1]) == 1) {
        exit(0);
    } else {
        _exit(0);
    }
}

static void my_exit1(void)
{
    printf("my exit\n");
}

static void my_exit2(void)
{
    printf("my exit2\n");
}
