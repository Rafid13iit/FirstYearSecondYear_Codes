#include <stdio.h>
int main ()
{
    int len, wid;

    printf("Please enter the length and width of the rectangle :\n");
    scanf("%d%d", &len, &wid);

    printf("Area is : %d", len*wid);

    return 0;
}

