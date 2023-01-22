#include <stdio.h>
int main ()
{
    int a;

    a=365*24*60*60;

    printf("The number of seconds in a year is : %d\n", a);
    printf("The number of minutes in a year is : %d\n", a/60);
    printf("The number of hours in a year is : %d\n", a/60/60);

    return 0;
}
