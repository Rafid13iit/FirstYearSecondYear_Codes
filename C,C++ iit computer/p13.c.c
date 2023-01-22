#include<stdio.h>
int main()
{
    int n;
    printf("please enter a number");
    scanf("%d",&n);
    if( n> 0){
            printf("the number is positive\n");
    }
    else if( n<0){
            printf("the number is negative\n");
    }
            else{
                printf("the number is zero!");

    }
return 0;
}

