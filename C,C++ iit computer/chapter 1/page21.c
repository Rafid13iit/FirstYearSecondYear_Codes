//program to convert earth days to jovian years

#include <stdio.h>
int main ()
{
    int earth_days;

    printf("please enter earth days : \n");
    scanf("%d", &earth_days);

    float eq_jy = (earth_days/365)*12;

    printf("The equivalent jovian year is : %.2f\n", eq_jy);

    return 0;
}
