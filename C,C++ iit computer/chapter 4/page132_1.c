#include<stdio.h>
#include<conio.h>
int main()
{
    double i;

    for(i=1.0; i<101.0; i++)
    {
        printf("the square root of %lf is %lf\n",i,sqrt(i));

        printf("whole number part %d\t",(int)sqrt(i));

        printf("fractional part %lf\n",sqrt(i)-(int)sqrt(i));

        printf("\n");
    }

    return 0;
}

