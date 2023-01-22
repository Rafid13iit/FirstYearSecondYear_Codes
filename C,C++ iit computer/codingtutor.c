#include<stdio.h>
int get_sum(int x, int y){
    int sum=x+y;
    return sum;
}
void say_hi(){
    printf("hi\n");
}
int main()
{
    printf("main start\n");

    say_hi();
    get_sum(10,20);

    return 0;
}
