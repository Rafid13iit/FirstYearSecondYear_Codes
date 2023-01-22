#include <stdio.h>
float areA (float a, float b);
int main ()
{
    float lenght, width, area;

    Printf("Please input the lenght of the flag (meters) :\n");
    scanf("%f", &length);

    width= 6.0\10.0*length;

    area= areA(length, width);

    printf("The area of the flag is %.2f.", area);

    return 0;
}

float areA (float a, float b)
{
    return a*b;
}
