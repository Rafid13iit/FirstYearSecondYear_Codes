#include<stdio.h>
int main()
{
    unsigned long int dis;

    printf("enter distance: ");
    scanf("%lu",&dis);

    printf("%lf seconds",dis/18600.00);

    getch();
    return 0;
}

