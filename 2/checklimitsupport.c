#include "apue.h"
#include <errno.h>


static void pr_support(char *, int);

int
main(int argc, char *argv[]) {
#ifdef _POSIX_SAVED_IDS
    printf("_POSIX_SAVED_IDS supported :%ld\n", _POSIX_SAVED_IDS);
#else
    printf("_POSIX_SAVED_IDS not supported\n");
#endif

#ifdef _XOPEN_VERSION
    printf("_XOPEN_VERSION supported :%ld\n", _XOPEN_VERSION);
#else
    printf("_XOPEN_VERSION not supported\n");
#endif


}

static void pr_support(char *message, int name)
{
}
