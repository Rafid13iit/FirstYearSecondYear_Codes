#include <stdio.h>
float dollarToBDT(float a);
int main ()

{
    float dol, bdt;

    printf("Enter the amount in dollar : \n");
    scanf("%f", &dol);

    bdt= dollarToBDT(dol);

    printf("The amount in BDT is : %.2f\n", bdt);

    return 0;
}


float dollarToBDT(float a)
{
    return (a*78.55);
}

