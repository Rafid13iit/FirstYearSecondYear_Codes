#include <stdio.h>
#include <string.h>
int length(int *x);

int main ()
{
    char a[50] = "SakibSir";

    printf("The length is : %d", length(a));

    return 0;
}


int length(int *x)
{
    return strlen(x);
}
