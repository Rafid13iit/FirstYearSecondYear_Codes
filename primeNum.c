#include <stdio.h>
#include <math.h>
int main ()

{
    int start, end, count = 0, i , j;

    scanf("%d%d", &start, &end);

    for (i = start; i <= end; i++){
        count = 0;

        for (j = 2; j < i; j++){

            if (i % j == 0){
                count++;
                break;
            }
        }

        if (count == 0 && i > 1){
            printf("%d is prime number\n", i);
        }
        else {
            printf("%d is NOT prime number\n", i);
        }

        //count = 0;
    }

    return 0;
}