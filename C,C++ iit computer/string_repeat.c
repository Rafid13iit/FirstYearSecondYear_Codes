#include <stdio.h>
#include <string.h>
int main ()
{
    char str1[80], bigstr[1000];
    int i;

    do{
        gets(str1);
        strcat(bigstr, str1);

        printf(bigstr);
        printf("\n");

    } while (str1 != "quit");

    return 0;
}
