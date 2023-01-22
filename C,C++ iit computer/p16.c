#include<stdio.h>
int main ()
{
    int a,b;
    b=1;
    printf("please enter a number of which you want to see namta\n");
    scanf("%d",&a);
    while(b++,b<=10){
        printf("%dX%d=%d\n",a,b,a*b);
    }
    return 0;
}
