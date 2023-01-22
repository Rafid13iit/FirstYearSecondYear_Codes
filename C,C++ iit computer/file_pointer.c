#include <stdio.h>
#include <stdlib.h>
int main ()
{
    FILE *fp;

    fp = fopen("rafid.txt", "r");

    while(fp){
        char ch;
        ch = fgetc(fp);
        printf("%c", ch);
    }

    return 0;
}
