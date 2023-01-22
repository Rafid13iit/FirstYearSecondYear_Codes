#include <stdio.h>
int main ()
{
    char ch;

    printf("Please enter your message : \n");

    ch = getchar();
    getchar();

    while (ch!='\n'){
        printf("%c", ch+1);
        ch = getchar();
        getchar();

    }

    return 0;
}
