// this code is not showing correct result

#include <stdio.h>
int main ()
{
    float balance[10][5] = {1, 2, 3, 4, 5,
                            6, 7, 8, 9, 10,
                            11, 12, 13, 14,
                            15, 16, 17, 18};

    float *p;

    p = (float *) balance;

    printf("%f\n", *(p + (3*5) + 1) ); //printing the value of "balance[3][1]" == 16
    printf("%f\n", *(p + (0*5) + 2) ); //printing the value of "balance[0][2]" == 3

    return 0;
}
