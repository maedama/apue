#include "apue.h"
#include <unistd.h>

int
main(int argc, char *argv[])
{
    if (argc != 2) {
        err_quit("usage: access <pathname>");
    }

    if (access(argv[1], R_OK) >= 0) {
        printf("read ok");
    } else {
        printf("read not ok");
    }
    exit(0);
}
