#include <stdio.h>
int main ()
{
    char a[1000];
    gets(a);

    if (a[0] >= 97) a[0] = a[0]-32;

    printf(a);

    return 0;
}
