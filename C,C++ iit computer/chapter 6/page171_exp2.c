/* this program is wrong but harmless */

#include <stdio.h>
int main ()
{
    int *p;
    double q, temp;

    temp = 1234.1234;

    p = &temp;  //attempt to assign q a value using
    q = *p;   // indirection through an integer pointer

    printf("%f", q); //this will not print 1234.1234

    return 0;
}
