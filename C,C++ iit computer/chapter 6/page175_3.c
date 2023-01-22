#include <stdio.h>
int main ()
{
    int *a, b;

    a = &b;

    b=10;
    printf("%d  %d  %p  %d\n\n", b, *a, a, a); // will print value, value, hexadecimal address, decimal address


    (*a)++;  //to increment the value of b, it will not increment the address inside a

    printf("%d  %d  %p  %d\n", b, *a, a, a);

    return 0;
}

