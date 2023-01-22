#include<stdio.h>
int main()
{
    long l;
    short s;
    double d;

    printf("enter the values: \n");

    scanf("%ld%hd%lf", &l, &s, &d);
    printf("%ld  %hd  %lf", l, s, d);

    return 0;
}
