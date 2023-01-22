#include <stdio.h>
int main ()
{
    int *p;
    double q, temp;

    temp = 1234.1234;

    p = &temp; // this is wrong here, because data types are not same
    q = *p;

    printf("%f", q); // will not print the exact value of q

    return 0;
}

