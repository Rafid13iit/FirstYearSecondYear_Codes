#include <stdio.h>
#include <string.h>
int main ()
{
    char str1[] = "Pointers are not fun at all!";
    char str2[80], *p1, *p2;

    p1 = str1 + strlen(str1) - 1; // storing given string's last character's address to p1
    p2 = str2;

    while (p1 >= str1){
        *p2++ = *p1--;
    }

    *p2 = '\0';
    printf("%s\n%s\n", str1, str2);

    return 0;
}
