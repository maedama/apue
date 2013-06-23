#include "apue.h"
#include <stdio.h>
#include <fcntl.h>

int
main(int argc, char *argv[])
{
    struct stat buf;
    int pos;
    
    setvbuf(stdout, NULL, _IONBF, 0);

    putc("a", stdout);  // This is still buffered and not seen 
    sleep(1); //
    rewind(stdout);
    putc("b", stdout);  // This overwrites buffer ant not seen;
    sleep(1);
}
