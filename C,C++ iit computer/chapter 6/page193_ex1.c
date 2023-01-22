#include <stdio.h>
void mystrcat (char *to, char *from);

int main ()
{
    char str[] = "My name ";

    mystrcat (str, "is Rafid.");
    printf(str);

    return 0;
}

void mystrcat (char *to, char *from)
{
    int i;
    for (i=0; i<strlen(to); i++);
    to = &to[i];

    while (*from){
        *to++ = *from++;
    }

    *to = '\0';
}

