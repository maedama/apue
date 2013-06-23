#include "apue.h"
#include <stdio.h>

static int global = 6;

int
main(void) {
    int var = 88;
    pid_t pid;
    printf("before fork pid:%d global:%d var:%d\n", getpid(), global, var);
    setvbuf(stdout, NULL, _IOFBF, 0);
    fputs("this is called once before fork, but would be writen twice, since IO is buffered\n", stdout);
    if ( (pid = fork()) < 0 ) {
        err_sys("fork error");
    } else if (pid > 0) {
        /* Parent Process */
        sleep(1); /* Wait to confirm child process finishes first */
    } else {
        /* Child Process */
        var++;
        global++;
    }

    /* Child and parent do not share variable */
    printf("after fork pid:%d global:%d var:%d\n", getpid(), global, var); 
    exit(0);
}
