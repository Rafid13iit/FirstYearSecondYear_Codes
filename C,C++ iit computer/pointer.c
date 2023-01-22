#include <stdio.h>
int main ()
{
    int *a;

    *a = 10; // incorrect, a is not holding any address

    printf("%d %d ", *a, a);

}
