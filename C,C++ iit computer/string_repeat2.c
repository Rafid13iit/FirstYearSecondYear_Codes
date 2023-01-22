#include <stdio.h>
#include <string.h>
int main ()
{
    char str[80], bigstr[1000]=" ";

    for ( ; ; ){
       printf("Enter a string: ");
       gets(str);

       if (!strcmp(str,"quit")) break;
       strcat(str, "\n");

       /* prevent an array overrun */
       if (strlen(bigstr) + strlen(str) >= 1000) break;
       strcat(bigstr, str);
    }

    printf(bigstr);

    return 0;
}
