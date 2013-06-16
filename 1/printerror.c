#include "apue.h"
#include <errno.h>

int
main(int args, char *argv[])
{
    fprintf(stderr, "EACES: %s\n", strerror(EACCES));
    errno = ENOENT;
    perror(argv[0]);
    exit(0);
}
