#include <stdio.h>
int main ()
{
    int i, n, count=0;

    printf("Please enter N : \n");
    scanf("%d",&n);

    for (i=1; i<=n; i++){
        if (n%i==0) count++;
    }

    if (count==2) printf("The number is a Prime Number.\n");
    else printf("The number is not a Prime Number.\n");

    return 0;
}

