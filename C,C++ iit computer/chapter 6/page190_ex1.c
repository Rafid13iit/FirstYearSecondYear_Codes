#include <stdio.h>
int main ()
{
    int **p_to_p, *p, a;

    a = 5;
    p = &a;
    p_to_p = &p;

    printf("%d\n", **p_to_p);
    printf("%p %p %p\n", p_to_p, p, &a);
    printf("%u %u %u\n", p_to_p, p, &a);
    printf("%d %d %d\n", p_to_p, p, &a);

    return 0;
}
