#include <stdio.h>
#include <string.h>
int main ()
{
    int *ptr, i, a = 5;
    int ary[5] = {1, 3, 5, 7, 9};

    ptr = ary;

    printf("Address of the 1st element only : \n");
    for (i=0; i<5; i++){
        printf("%d\n", ptr); //only to print address of the 1st element
    }
    printf("\n");

    printf("Address of ALL element : \n");
    for (i=0; i<5; i++){
        printf("%d  %u  %p\n", ptr + i, ptr + i, ptr + i); //to print address of ALL elements
    }
    printf("\n");

    printf("Value of 1st element only : \n");
    for (i=0; i<5; i++){
        printf("%d\n", *ptr); //only to print value of the 1st element
    }
    printf("\n");

    printf("Value of ALL elements : \n");
    for (i=0; i<5; i++){
        printf("%d\n", *(ptr + i)); //only to print value of the 1st element
    }
    printf("\n");

        printf("Address of ALL element : \n");
    for (i=0; i<5; i++){
        printf("%d\n", ary + i); //to print address of ALL elements using array 1st element address
    }
    printf("\n");


    ptr = &a;  // you can not write ptr = a;
    printf("Address and Value printing of a n:\n");
    printf("%d   %d   %d   %d\n", ptr, *ptr, &a, a);


    return 0;

}
