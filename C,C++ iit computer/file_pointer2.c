#include <stdio.h>
#include <stdlib.h>
int main ()
{
    char ch;
    FILE *fp;

    fp = fopen("rafid.txt", "r");

    do{
        ch = fgetc(fp);
        printf("%c", ch);

    } while(ch != EOF);

    return 0;
}

