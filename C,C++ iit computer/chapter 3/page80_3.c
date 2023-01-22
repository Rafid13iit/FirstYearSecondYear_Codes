#include<stdio.h>
#include<conio.h>
int main(){
    char ch;

    for(ch=getche();ch!='q';ch=getche());
    printf("found the q");
    return 0;
}
