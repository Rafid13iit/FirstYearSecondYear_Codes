#include <stdio.h>
int main ()
{
    int num, deletePosition;

    printf("Test Data:\n");

    printf("Input the size of the array: ");
    scanf("%d", &num);

    int array[num];

    printf("Input %d elements in the array ascending order :\n", num);

    for (int i = 0; i < num; i++){
        printf("element-%d : ", i);
        scanf("%d", &array[i]);
    }

    printf("Input the position where to delete: ");
    scanf("%d", &deletePosition);

    for (int i = deletePosition - 1; i < num; i++){
         if (i == num - 1) num = num - 1;
         else array[i] = array[i + 1];
    }

    printf("The new list is : ");
    for (int i = 0; i < num; i++){
        printf("%d ", array[i]);
    }

    return 0;
}