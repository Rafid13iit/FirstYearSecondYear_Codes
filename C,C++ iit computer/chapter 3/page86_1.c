#include<stdio.h>
int main(){
    int i=1;
    float j,k;
    while(i){
        printf("Enter the amount in gallons: ");
        scanf("%f",&j);
        printf("%f gallons = %f liters\n",j,j*3.7854);
        printf("If you want to stop press 0,else press any number\n");
        scanf("%d",&i);
    }
}
