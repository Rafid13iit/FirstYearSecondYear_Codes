#include <stdio.h>
int main ()
{
    int a, b, c;

    printf("Please enter the length, width and height of the cube :\n");
    scanf("%d%d%d", &a, &b, &c);

    printf("The volume is: %d\n", a*b*c);

    return 0;
}

