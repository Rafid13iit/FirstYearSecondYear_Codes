#include <stdio.h>
#include <string.h>
int main ()
{
    char str[100], *p;
    int i;

    gets(str);

    for (i=0; i<strlen(str); i++){
        if (str[i] == ' '){
            p = &str[i+1];
            break;
        }
    }

    printf("%s", p);

    return 0;
}


