// assign a value in q using pointer
#include <stdio.h>
int main ()
{
    int *ptr, q;

    ptr = &q;
    *ptr = 199;

    printf("q's value is %d.\n", q); // i can use *ptr instead of q

    return 0;
}
