#include<stdio.h>
int main(){
    float num;
    int choice;
    printf("1: Feet to Meters, 2: Meters to feet. ");
    printf("Enter the choice");
    scanf("%d",&choice);

    if(choice == 1){
        printf("Enter the number in feet ");
        scanf("%f",&num);
        printf("Meters: %f",num/3.28);
    }
    else {
        printf("Enter the number in meters: ");
        scanf("%f",&num);
        printf("Feet: %f",num*3.38);
    }
    return 0;

}
