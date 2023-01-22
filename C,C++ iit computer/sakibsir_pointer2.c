#include <stdio.h>
char* print_chg(void);

int main ()
{
    char *a;

    a = print_chg();

    printf(a);

    return 0;
}

char* print_chg(void)
{
    char y[10000] = "BSSE13";

    return y;
}

