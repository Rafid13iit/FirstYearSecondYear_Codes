#include <stdio.h>
#include <ctype.h> // header file of toupper() and tolower() function
int main ()
{
    char str[80];
    int i;

    printf("Enter a string :\n");
    gets(str);

    for (i=0; str[i]; i++){
        str[i] = toupper(str[i]); // to upper ()
    }
    printf("%s\n\n", str);

    for (i=0; str[i]; i++){
        str[i] = tolower(str[i]); // to lower ()
    }
    printf("%s\n", str);

    return 0;

}
