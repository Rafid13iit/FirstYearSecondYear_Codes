#include <stdio.h>
int main ()
{
    int row, col, n;

    printf("Please input the value of N : \n");
    scanf("%d",&n);

    for (row=n; row>=1; row--){

        for (col=1; col<=n-row; col++){
            printf("  ");
        }

        for (col=1; col<=row; col++){
            printf("%d ",col);
        }

        printf("\n");
    }

    return 0;
}

