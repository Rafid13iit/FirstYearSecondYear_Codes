#include<stdio.h>
int main()
{
    int i,j,n,s;

    printf("Enter the number of rows:\n");
    scanf("%d",&n);

    for(i=1;i<=n;i++){

        for(s=n-i+1;s>=1;s--){
            printf("a");
        }

        for(j=1;j<=2*i-1;j++){
            printf("*");
        }

        for(s=n-i+1;s>=1;s--){
            printf("a");
        }

        printf("\n");
    }

    return 0;
}
