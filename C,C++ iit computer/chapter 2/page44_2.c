#include<stdio.h>
int main(){
    int a;
    printf("Enter a number: ");
    scanf("%d",&a);
    if(a%2 == 0){
        printf("the number is Even");
    }
    if(a%2 != 0){
        printf("the number is not a even number");
    }
    return 0;

}
