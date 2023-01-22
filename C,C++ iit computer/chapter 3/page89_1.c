#include<stdio.h>
int main(){
    int is_prime,i,j;
    for(i=2;i<=1000;i++){
        is_prime=0;
        for(j=2;j<i/2;j++){
            if(i%j==0){
                is_prime=1;
            }
        }
        if(is_prime == 0){
            printf("%d ",i);
        }
    }
}
