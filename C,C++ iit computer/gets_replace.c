#include <stdio.h>
int main ()
{
    char str[80];
    int i;

    printf("Enter a string (Press q to exit) :\n");
    for (i=0; i<80; i++){
        scanf("%c", &str[i]);
        if (str[i]=='q')
        {
            str[i] = '\0';
            printf("\nProgram finished.\n");
            break;
        }
    }

    return 0;
}
