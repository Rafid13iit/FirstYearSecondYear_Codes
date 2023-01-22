
#include<stdio.h>
int main(){
    int num,i;
    printf("Enter an integer number");
    scanf("%d",&num);
    for(i=num;i>=0;i--){
        printf("%d\n",i);
        if(i==0){
            printf("\a");
        }
    }
    return 0;
}
