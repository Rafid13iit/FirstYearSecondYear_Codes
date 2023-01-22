#include <stdio.h>
#include <string.h>
char* concat(char *x);

int main ()
{
    char a[50] = "Rafid";
    printf("%s", concat(a));

    return 0;
}

char* concat(char *x)
{
    return strcat(x, " is a good boy.");
}
