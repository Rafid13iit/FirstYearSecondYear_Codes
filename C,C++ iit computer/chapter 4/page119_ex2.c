#include<stdio.h>
void sp(double distance);
int main()
{
    double distance;
    printf("enter distance in feet: ");
    scanf("%lf",&distance);
    sp(distance);
    return 0;
}
void sp(double distance)
{
    printf("travel time : %f",distance/1129);
}
