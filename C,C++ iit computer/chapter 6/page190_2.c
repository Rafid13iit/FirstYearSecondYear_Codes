#include <stdio.h>
#include <string.h>
int main ()
{
    char *p, **mp, str[80];

    p = str;
    mp = &p;

    printf("Enter a string:\n");
    gets(*mp);

    printf("Hi, your string was: %s\n", *mp);

    return 0;
}
