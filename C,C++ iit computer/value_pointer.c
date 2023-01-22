#include <stdio.h>
int main ()
{
    int val = 5, *a;

    a = &val;

    printf("%d\n", *a);

    *a = *a + 10; // *a = value of the address stored at the variable

    printf("%d\n", *a);

    return 0;
}
