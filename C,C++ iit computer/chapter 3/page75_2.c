#include<stdio.h>
int main(){
    char i,j;
    for(i='A',j='a';i<='Z',j<='z';i++,j++){
        printf("ASCII code of %c is %d\n",i,i);
        printf("ASCII code of %c is %d\n",j,j);
    }
    return 0;
}
