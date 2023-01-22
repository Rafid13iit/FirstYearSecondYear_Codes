#include <stdio.h>
int main ()
{
    int n, i, top = 0;

    printf("How many items are there?\n");
    scanf("%d", &n);

    int a[n];

    printf("Enter the items : \n");
    for (i=0; i<n; i++){
        scanf("%d", &a[i]);
    }


}
