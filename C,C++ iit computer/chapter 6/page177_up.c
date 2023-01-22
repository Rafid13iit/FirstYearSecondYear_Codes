#include <stdio.h>
int main ()
{
    int a[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int *p;

    p = a;

    printf("%d %d %d\n\n", a[0], a[1], a[2]);

    printf("%d %d %d\n\n", *p, *(p + 1), *(p + 2));

    return 0;
}

