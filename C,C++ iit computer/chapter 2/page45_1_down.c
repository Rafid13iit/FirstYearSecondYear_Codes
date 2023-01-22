#include<stdio.h>
int main(){
    printf("Enter two numbers: ");
    int a,b;
    scanf("%d %d",&a,&b);

    printf("1.Do sum 2.Do product Enter choice: ");
    int choice;
    scanf("%d",&choice);
    if(choice == 1){
        printf("the sum of %d and %d is %d",a,b,a+b);
    }
    if(choice == 2){
        printf("the product of %d and %d is %d",a,b,a*b);
    }
    return 0;
}

