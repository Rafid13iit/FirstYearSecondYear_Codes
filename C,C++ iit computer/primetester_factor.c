#include <stdio.h>
int main ()
{
    int i, num, count=0;

    printf("PLease enter a number to test: \n");
    scanf("%d", &num);

    for (i=1; i<=num; i++){
        if (num%i==0){
            count++;
        }
    }

        if (count==2){
            printf("This is prime number!\n");
        }
        else {
            printf("Not a prime number!\n");
        }

    printf("\nThe factors are: \n");
    for (i=1; i<=num; i++){
        if (num%i==0 && i!=1 && i!=num){
           printf("%d ", i);
        }
    }

    return 0;
}

