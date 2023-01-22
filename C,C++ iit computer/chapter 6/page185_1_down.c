#include <stdio.h>
int main ()
{
    char *p1 = "One", *p2 = "Two", *p3 = "Three";

    printf("%s %s %s\n", p1, p2, p3);
    printf("%s %s %s\n", p1, p3, p2);
    printf("%s %s %s\n", p3, p2, p1);
    printf("%s %s %s\n", p3, p1, p2);
    printf("%s %s %s\n", p2, p1, p3);
    printf("%s %s %s\n", p2, p3, p1);

    return 0;
}
