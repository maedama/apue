#include "apue.h"
#include <stdio.h>

static int global = 6;

int
main(void) {
    int var = 88;
    pid_t pid;
    printf("before vork\n");
    if ( (pid = vfork()) < 0 ) {
        err_sys("fork error");
    } else if (pid > 0) {
        /* Parent Process */
    } else {
        /* Child Process */
        var++;
        global++;
        _exit(0); /* do not flush buffer */
    }

    /* parent is executed after child, and shares memory with child */
    printf("after fork pid:%d global:%d var:%d\n", getpid(), global, var); 
    exit(0);
}
