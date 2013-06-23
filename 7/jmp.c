#include "apue.h"
#include <setjmp.h>

static void f1(int, int, int, int);
static void f2(void);

static jmp_buf jmpbuffer;
static int global;

int
main(void)
{
    int          autoval;
    register int regival;
    volatile int volaval;
    static   int statval;
    
    global = 1; autoval = 2; regival = 3; volaval = 4; statval = 5;

    if (setjmp(jmpbuffer) != 0) {
        printf("after longjmp\n");
        printf(
            "global = %d, autoval = %d, regival = %d, volaval = %d, statval = %d\n",
            global, autoval, regival, volaval, statval
        );
        exit(0);
    }

    global = 95; autoval = 96; regival = 97; volaval = 98; statval = 99;
    f1(autoval, regival, volaval, statval);
}

static void
f1(int i, int j, int k, int l)
{
    printf("int f1()\n");
    printf(
        "global = %d, autoval = %d, regival = %d, volaval = %d, statval = %d\n",
        global, i, j, k, l
    );
    f2();
}

static void
f2(void)
{
    longjmp(jmpbuffer, 1);
}
