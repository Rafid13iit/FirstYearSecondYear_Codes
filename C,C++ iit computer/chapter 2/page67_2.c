#include<stdio.h>
int main(){
    int a,b,i,c=0;
    printf("How many rooms do you have?  ");
    scanf("%d",&a);
    for(i=1;i<=a;i++){
        printf("Enter the dimension of number %d room: ",i);
        scanf("%d",&b);
        c=c+b;
    }
    printf("Total square footage is %d",c);
}
