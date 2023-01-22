#include<stdio.h>
int main()
{
    int a,b,c;
    printf("please enter three numbers\n");
    scanf("%d%d%d",&a,&b,&c);
    if(a>b && a>c){
        printf("the big number is %d",a);
    }
    else if(b>a && b>c){
        printf("the big number is %d",b);
    }
    else{
        printf("the big number is %d",c);
    }
    return 0;
}
