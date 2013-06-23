#include "apue.h"
#include <stdio.h>
#include <fcntl.h>

int
main(int argc, char *argv[])
{
    struct stat buf;
    
    if (fstat(STDOUT_FILENO, &buf) < 0) {
        err_sys("fstat failed");
    }
    
    if (S_ISCHR(buf.st_mode)) {
        printf("character\n");
    } else if (S_ISBLK(buf.st_mode)) {
        printf("block\n");
    } else {
        printf("other\n");
    }

    if (argc != 2) {
        err_quit("bufmode <mode>");
    }
    
    if (atoi(argv[1]) == 0) {
        setvbuf(stdout, NULL, _IOFBF, 0);
    } else if (atoi(argv[1]) == 2) {
        setvbuf(stdout, NULL, _IOLBF, 0);
    } else {
        setvbuf(stdout, NULL, _IONBF, 0);
    }

    printf("a\n");  // This is still buffered and not seen 
    sleep(1); //
    printf("b\n");  // This overwrites buffer ant not seen;
    sleep(1);
    fflush(stdout);
    /* Seek would not work on charcater device */
    printf("abc");  // This is still buffered and not seen 
    sleep(1);
    if (lseek(STDOUT_FILENO, 1, SEEK_CUR) < 0 ) {
        err_sys("unable to seek");
    }
    printf("efg");  // This is still buffered and not seen 
    sleep(1);
    printf("\n");
    sleep(1);
}
