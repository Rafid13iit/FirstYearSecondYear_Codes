#include<stdio.h>
#include<conio.h>
int main(){
    char ch;
    ch=getche();
    while(ch!='\r'){
        printf("%c",ch-1);
        ch= getche();
    }
}
