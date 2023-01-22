#include<stdio.h>
int series();
int num=21;
int main()
{
    int i;

    for(i=0;i<10;i++)
    {
        printf("%d", series() );

        return 0;
    }
}

int series()
{
    num=(num*1468)%467;
    return num;
}
