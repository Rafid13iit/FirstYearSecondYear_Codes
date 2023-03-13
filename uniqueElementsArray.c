#include <stdio.h>
int main ()
{
    int num;

    printf("Test Data:\n");
    printf("Print all unique elements of a array:\n");
    printf("-------------------------------------\n");

    printf("Input the numbers of elements to be stored in the array: ");
    scanf("%d", &num);

    int array[num];

    printf("Input %d elements in the array :\n", num);

    for (int i = 0; i < num; i++){
        printf("element-%d : ", i);
        scanf("%d", &array[i]);
    }

    printf("The unique elements found in the array are:\n");

    int count = 0;
    for (int i = 0; i < num; i++){
        for (int j = 0; j < num; j++){
            if (array[i] == array[j]) count++;

            if(count > 1) break;
        }

        if (count == 1) printf("%d ", array[i]);
        count = 0; 
    }

    return 0;
}