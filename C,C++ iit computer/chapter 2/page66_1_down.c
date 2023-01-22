#include<stdio.h>
int main(){
    int a=14,b,i,c;
    for(i=1;i<=10;i++){
        if(i==1)printf("Enter number: ");
        else printf("Enter another number: ");
        scanf("%d",&b);
        c=i;
        if(a==b){
            printf("Right\n");
            i=10;
        }
        else if(b>a){
            printf("high\n");
        }
        else{
            printf("low\n");
        }
    }
    printf("Number of tries are %d",c);
    return 0;
}
