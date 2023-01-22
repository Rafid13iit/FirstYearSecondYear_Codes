#include <stdio.h>
int get_sqr();

int main (int x)
{
    int a, num;

    printf("Please enter a number to see its square :\n");
    scanf("%d", &num);

    a = get_sqr(num);

    printf("Square value is : %d\n", a);

    return 0;
}

int get_sqr(int x)
{
    return x*x;
}
