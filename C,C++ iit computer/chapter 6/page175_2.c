#include <stdio.h>
int main ()
{
    int *p, q;
    p = &q;

    q = 1;
    printf("%d  %p\n", p, p);

    *p++; //this will not increment q
    printf("%d  %d  %p", q, p, p);





    printf("\n\n\n");

    int *a, b[5] = {1, 2, 3, 4, 5};

    a = &b;

    printf("%d  %d  %p  %d\n\n", b[3], *(a + 3), a, a); // it will print value, value, hexadecimal address, decimal address


    *a++; //increments address inside a, it will not increment the value of b
    *a = 10;

    printf("%d  %d  %p  %d\n", b, *a, a, a);

    return 0;
}
