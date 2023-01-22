#include <stdio.h>
int main ()
{
    int a[8], i;

    printf("Enter the elements of the the array : \n");
    for (i=0; i<8; i++){
        scanf("%d", &a[i]);
    }

    printf("\nYour array is : \n");
    for (i=0; i<8; i++){
        printf("%d ", a[i]);
    }

    //reverse array
    printf("\n\nThe reverse array is :\n");
    for (i=7; i>=0; i--){
        printf("%d ", a[i]);
    }

    printf("\n");

    return 0;
}
