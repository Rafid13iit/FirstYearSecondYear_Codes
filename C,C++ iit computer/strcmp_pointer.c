#include <stdio.h>
#include <string.h>
int comp(char *x);

int main ()
{
    char a[50] = "Bangladesh";

    if (comp(a) == 0)
        printf("Strings are same!\n");
    else
        printf("Strings are NOT same!\n");

    return 0;
}

int comp(char *x)
{
    return strcmp(x, "Pakistan");
}
