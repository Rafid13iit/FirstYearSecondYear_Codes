#include <stdio.h>
void function2(void);
void function3(void);
int main ()
{
    function2();

    printf("3\n");

    return 0;
}

void function2(void)
{
    function3();

    printf("2 ");
}

void function3(void)
{
    printf("1 ");
}

