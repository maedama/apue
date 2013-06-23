#include "apue.h"

static void f1(int count);

int
main(void)
{
    f1(3);
    exit(0);
}

static void f1(int count)
{
    static int   statval = 0;    /* Stat val initialization is done on compile phase*/
    int          autoval = 0; /* this is initialized everytime we run the routine and saved in stack on recursive call */
    volatile int volaval = 0; /* this is initialized everytime we run the routine and saved in stack on recursive call */

    if (count > 0 ) {
        f1(count-1);
    }
    autoval++;
    statval++;
    volaval++;
    printf("auto:%d volaval:%d, stat:%d\n", autoval, volaval, statval);
}
