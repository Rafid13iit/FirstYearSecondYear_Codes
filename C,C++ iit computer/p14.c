#include<stdio.h>
int main()
{
    int num=41;
    if (num<20){
        printf("the number is less than 20");
    }
    else if (num<40){
        printf("the number is less than 40");
    }
    else if(num==40){
        printf("the number 40");
    }
    else{
        printf("the number is greater than 40");
    }
    return 0;
}
