#include <stdio.h>
int main ()
{
    int num, count=0;

    printf("Enter a number to test PRIME Number:\n\n");
    scanf("%d", &num);

    for (int i=1; i<=num; i++){
        if (num%i==0){
            count++;
            while(i!=1 && i!=num) printf("%d ", i);



        }
    }

    if (count==2) printf("\nPrime Number!\n");

    return 0;
}
