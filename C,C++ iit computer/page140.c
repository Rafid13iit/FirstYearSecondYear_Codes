#include <stdio.h>
int main ()
{
    int sqr[10];
    int i;

    printf("Enter the values : \n");
    for (i=0; i<10; i++){
        scanf("%d", &sqr[i]);
    }

    printf("The squares are : \n");
    for (i=0; i<10; i++){
        printf("%d\n", sqr[i]*sqr[i]);
    }

    return 0;
}
