#include <stdio.h>

void func1(void); //function prototype

int main ()
{
    printf("I ");

    func1();  //calling a function here

    printf("IIT.\n");

    return 0;
}

void func1(void)
{
    printf("love ");
}
