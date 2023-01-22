#include <stdio.h>
void mystrcpy (char *to, char *from);

int main ()
{
    char str[80] = "Blank string!";

    printf("Before copy:\n");
    printf(str);

    mystrcpy (str, "I love my parents.");

    printf("\n\nAfter coping new string:\n");
    printf(str);

    return 0;
}

void mystrcpy (char *to, char *from)
{
    while (*from){
        *to++ = *from++;
    }

    *to = '\0'; // null terminates the string
}
