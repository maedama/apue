#include "apue.h"

int
main(int argc, char *argv[])
{
    if (argc != 3) {
        err_quit("tempnam <DIR> <PREFIX>");
    }

    char *filename;
    filename = tempnam(
        strcmp(argv[1], " ") != 0 ? argv[1] : NULL,  
        strcmp(argv[2], " ") != 0 ? argv[2] : NULL
    );
    printf("filename:%s", filename);
    exit(0);
}
