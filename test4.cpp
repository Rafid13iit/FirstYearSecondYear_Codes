#include <stdio.h>
#include <math.h>

double f(double x)
{
    return sin(x);
}

double forward_difference(double x, double h)
{
    return (f(x + h) - f(x)) / h;
}

int main(void)
{
    double x = 0.5;
    double h = 0.1;
    double approx = forward_difference(x, h);
    printf("The approximation of the derivative at x=%.1f is: %.4f\n", x, approx);
    return 0;
}
