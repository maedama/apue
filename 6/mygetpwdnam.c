#include "apue.h"
#include <pwd.h>
#include <stddef.h>
#include <string.h>

struct passwd *getpwdnam(const char *);

int
main(int argc, char *argv[]) {
    struct passwd *ptr;
    if (argc != 2) {
        err_quit("usage: mygetpwdnam <user_name>");
    }
    ptr = getpwdnam(argv[1]);
    if (ptr != NULL) {
        printf("found %s: enc:%s, uid:%d\n", ptr->pw_name, ptr->pw_passwd, ptr->pw_uid);
    } else {
        printf("not found %s\n", argv[1]);
    }
    exit(0);
}



struct passwd
*getpwdnam(const char *name)
{
    struct passwd *ptr;
    while ((ptr = getpwent()) != NULL) {
        if (strcmp(name, ptr->pw_name) == 0) {
            break;
        }
    }
    return ptr;
}



