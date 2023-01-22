#include<stdio.h>
int main(){
    int i;
    char a,b,c;
    printf("please Enter 10 charecters\n");
    for(i=1;i<=9;i++){
        if(i==1){
            a=getchar();
            getchar();
            b=getchar();
            if(a<b){
                c=a;
            }
            else c=b;
        }
        else{
            getchar();
            a=getchar();
            if(a<c){
                c=a;
            }
        }
    }
    printf("%c comes earliest in alphabet",c);
}
