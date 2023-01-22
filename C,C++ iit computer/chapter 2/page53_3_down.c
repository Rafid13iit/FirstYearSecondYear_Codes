#include<stdio.h>
int main(){
    int num,i;
    printf("Enter the number: ");
    scanf("%d",&num);
    int p=1;
    for(i=2;i<=num/2;i++){
        if(num%i == 0){
            p=0;
        }
    }
    if(p==1){
        printf("This is a prime number");
    }
    else{
        for(i=2;i<=num/2;i++){
            if(i<3)printf("The factors of %d are: ",num);
            if(num%i == 0){
            printf("%d ",i);
            }
        }
    }

    return 0;
}
