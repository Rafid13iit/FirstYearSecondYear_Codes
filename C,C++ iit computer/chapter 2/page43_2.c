#include<stdio.h>
int main(){
    float num;
    int choice;
    printf("Enter Value: ");
    scanf("%f",&num);
    printf("1: Feet to meter. 2:Meter to Feet. ");
    printf(" Enter choice: ");
    scanf("%d",&choice);

    if(choice == 1)printf("%f",num/3.28);
    if(choice == 2)printf("%f",num*3.28);
    return 0;
}
