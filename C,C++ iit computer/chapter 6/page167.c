#include <stdio.h>
int main ()
{
    int *ptr, q;

    q = 199;
    ptr = &q;

    printf("%d  %d  %p\n", *ptr, ptr, ptr);

    return 0;
}
