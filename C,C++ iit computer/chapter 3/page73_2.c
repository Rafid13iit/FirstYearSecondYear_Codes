#include<stdio.h>
int main(){
    int a,b;
    char ch;

    printf("Do you want to:\n");
    printf("Add,Substract,Multiple,Division?\n");
    printf("Enter the first letter ");
    ch=getchar();
    printf("\n");

    printf("Enter the first number: ");
    scanf("%d",&a);

    printf("Enter the second number: ");
    scanf("%d",&b);

    if(ch=='A') printf("%d",a+b);
    if(ch=='B') printf("%d",a-b);
    if(ch=='C') printf("%d",a*b);
    if(ch=='D' && b!=0) printf("%f",a/b);

    return 0;

}
