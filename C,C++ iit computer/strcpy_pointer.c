#include <stdio.h>
#include <string.h>
char* copy(char *x);

int main ()
{
    char a[50] = "Bangladesh is a populated country.";
    char *p;

    p = copy(a);

    printf(p);

    return 0;
}


char* copy(char *x)
{
    return strcpy(x, "Bangladesh is a beautiful country.\n");
}

