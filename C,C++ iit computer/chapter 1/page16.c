#include <stdio.h>
int main ()
{
    int num1;
    float num2;

    printf("Please input a integer and float number: \n");
    scanf("%d%f", &num1, &num2);

    printf("You entered : %d and %.3f\n", num1, num2);

    return 0;
}
