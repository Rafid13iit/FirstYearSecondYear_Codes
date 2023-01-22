#include <stdio.h>
double absolute(double x);
int main ()
{
    double a, b;

    printf("Enter any real number:\n");
    scanf("%lf", &a);

    printf("The absolute value of %.4lf is : %.4lf\n", a, absolute(a));

    return 0;
}

double absolute(double x)
{
   if (x<0)
       return x*(-1);
   else
       return x;
}
