#include<stdio.h>
int main(){
    int a,b;
    char ch;

    printf("Do you want to:\n");
    printf("Add, Subsract, Multiply, Divide?\n");
    do{
        printf("Enter the first letter: ");
        ch=getchar();
    } while(ch!='A' && ch!='S' && ch!='M' && ch!='D');
    printf("\n");

    printf("Enter the first number: ");
    scanf("%d",&a);
    printf("Enter the second number: ");
    scanf("%d",&b);

    switch(ch){
        case 'A': printf("%d",a+b);
          break;
        case 'S': printf("%d",a-b);
          break;
        case 'M': printf("%d",a*b);
          break;
        case 'D': printf("%d",a/b);
          break;

    }
    return 0;
}
