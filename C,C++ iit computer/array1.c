#include <stdio.h>
int main ()
{
    int a[5], choice, i, j, temp;

    printf("Enter the elements of the the array : \n");
    for (i=0; i<5; i++){
        scanf("%d", &a[i]);
    }

    printf("\nYour array is : \n");
    for (i=0; i<5; i++){
        printf("%d ", a[i]);
    }

    repeat:
    printf("\n\nWhat do you want to do? (Just input the number) \n");
    printf("1. Sorting ascending order\n");
    printf("2. Sorting descending order\n");
    scanf("%d", &choice);

    //array sorting  //this is to remember

    if (choice==1){
        printf("\nNow your array is : \n");
        for (i=0; i<5; i++){
            for (j=i+1; j<5; j++){
                if (a[i] > a[j]){  //ascending code
                    temp=a[i];
                    a[i]=a[j];
                    a[j]=temp;
                }
            }
            printf("%d ", a[i]);
        }
    }


    else if (choice==2){
        printf("\nNow your array is : \n");
        for (i=0; i<5; i++){
            for (j=i+1; j<5; j++){
                if (a[i] < a[j]){  //descending code
                    temp=a[i];
                    a[i]=a[j];
                    a[j]=temp;
                }
            }
            printf("%d ", a[i]);
        }
    }

    else{
        printf("\nERROR.\n");
        printf("Input between 1 and 2.\n");
        goto repeat;
    }
    printf("\n");

    return 0;
}
