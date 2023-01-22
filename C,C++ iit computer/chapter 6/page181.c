#include <stdio.h>
#include <ctype.h>
int main ()
{
    char str[80];
    int i, *p;

    printf("Enter a string :\n");
    gets(str);
    p = str;

    while(*p){ // this means, when the value of the address inside p is not 0
        *p++ = toupper(*p);
    }
    printf("%s\n", str);

    p = str;

    while(*p){
        *p++ = tolower(*p);
    }
    printf("%s\n", str);

    return 0;
}
