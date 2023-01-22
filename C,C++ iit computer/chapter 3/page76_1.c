#include<Stdio.h>
int main(){
    int a,b;
    char ch;
    printf("Do you want to:\n");
    printf("Add,substract,Multiply,or division");
    printf("Enter first letter: ");
    ch=getchar();
    printf("\n");

    printf("Enter first number: ");
    scanf("%d",&a);
    printf("Enter secod number: ");
    scanf("%d",&b);

    if(ch=='A')printf("%d",a+b);
    else if(ch=='S')printf("%d",a-b);
    else if(ch=='M')printf("%d",a*b);
    else if(ch=='D' && b!=0)printf("%d",a/b);
    return 0;
}
