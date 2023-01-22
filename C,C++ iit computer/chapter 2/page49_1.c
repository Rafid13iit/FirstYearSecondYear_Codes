#include<stdio.h>
int main(){
    int num1,num2,choice;
    printf("What do you want to do? 1.addition 2.substraction ");
    printf("Enter your choice: ");
    scanf("%d",&choice);
    if(choice == 1){
        printf("Enter two numers");
        scanf("%d %d",&num1,&num2);
        printf("The sum of %d and %d is %d",num1,num2,num1+num2);
    }
    else{
        printf("Enter two numers");
        scanf("%d %d",&num1,&num2);
        printf("The sbstraction of %d and %d is %d",num1,num2,num1-num2);
    }
return 0;

}
