#include<stdio.h>
int main()
{
    unsigned u;
    long l;
    short s;

        printf("enter an unsigned: ");
        scanf("%u",&u);

        printf("enter a long: ");
        scanf("%ld",&l);

        printf("enter a short: ");
        scanf("%hd",&s);

        printf("%u %ld %hd\n", u, l, s);

    return 0;
}

