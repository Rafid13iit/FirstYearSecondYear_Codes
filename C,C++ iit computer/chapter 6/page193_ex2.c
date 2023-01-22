#include <stdio.h>
void lalon(int *ptr);

int main ()
{
    int i;

    lalon (&i);
    printf("%d", i);

    return 0;
}

void lalon (int *ptr)
{
    *ptr = -1;
}
