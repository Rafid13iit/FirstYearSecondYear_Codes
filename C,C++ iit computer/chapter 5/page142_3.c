#include <stdio.h>
int main ()
{
    char mess[100];
    int i;

    printf("Enter message (less than 100 characters)\n");

    for (i=0; i<100; i++){
        mess[i] = getche();
        if (mess[i] == '\r') break;
    }

    printf("\n");

    for (i=0; mess[i] != '\r'; i++){
        printf("%c", mess[i]+1);
    }

    return 0;
}
