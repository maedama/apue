#include "apue.h"
#include <fcntl.h>
#include <dirent.h>
#include <limits.h>

#define MAX_FILE_PATH 4096
typedef int Myfunc (const char *, const struct stat *);
static long nreg, ndir, nblk, nchr, nfifo, nslink, nsock, ntot;

static Myfunc myfunc;
static int myftw(char *, Myfunc *);

int
main(int argc, char *argv[]) 
{
    int ret;
    char *path;
    if (argc != 2) {
        err_quit("usage: myftw <path_to_traverse>");
    }
    path = argv[1];

    ret = myftw(path, myfunc);
    printf("total          = %7ld\n",  ntot);
    printf("regular files  = %7ld\n", nreg);
    printf("directories    = %7ld\n", ndir);
    printf("block special  = %7ld\n", nblk);
    printf("char special   = %7ld\n", nchr);
    printf("fifo           = %7ld\n", nfifo);
    printf("symlinks       = %7ld\n", nslink);
    printf("socket         = %7ld\n", nsock); 
}

static int myftw(char *path, Myfunc *myfunc) {
    DIR *dp;
    struct dirent *direntbuf;
    struct stat statbuf;
    char FILE_PATH[MAX_FILE_PATH];
   
    if ( (dp = opendir(path)) == NULL) {
        err_sys("can not open dir %s", path);
    }

    while ( (direntbuf = readdir(dp)) != NULL) {
        if (strcmp(direntbuf->d_name, ".") == 0 || 
            strcmp(direntbuf->d_name, "..") == 0 )
        {
            continue; /* ignore dot and dot dot */
        }

        if (sprintf(FILE_PATH, "%s/%s", path, direntbuf->d_name) < 0) {
            err_sys("filename too long?");
        }
        if (lstat(FILE_PATH, &statbuf) < 0) {
            err_sys("lstat error");
        }

        myfunc(FILE_PATH, &statbuf); /* Call myfunc */
        
        /* Recursivly follow the link */
        if (S_ISLNK(statbuf.st_mode)) {
            /* Skip symlink */
        }
        else if (S_ISDIR(statbuf.st_mode)) {
            myftw(FILE_PATH, myfunc);
        }
    }
    return 0;
}

static int
myfunc(const char *pathname, const struct stat *statptr)
{
    switch(statptr->st_mode & S_IFMT) {
        case S_IFREG: nreg++;    break;
        case S_IFBLK: nblk++;    break;
        case S_IFCHR: nchr++;    break;
        case S_IFIFO: nfifo++;   break;
        case S_IFLNK: nslink++;  break;
        case S_IFSOCK: nsock++;  break;
        case S_IFDIR: ndir++;    break;
        default:
            err_dump("unknown type %d with path:%s", statptr->st_mode, pathname);
    }
    ntot++;
    return 0;
}
