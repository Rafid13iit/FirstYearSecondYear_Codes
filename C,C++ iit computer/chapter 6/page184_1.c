#include <stdio.h>
int main ()
{
    char *p = "stop";
    char str[100];

    do{
        printf("Enter a string:\n");
        gets(str);
    }
    while(strcmp(p, str));

    return 0;
}
