#include <stdio.h>
#include <string.h>
int main ()
{
    char str[50];
    int i = 0;

    printf("Test Data:\n");
    printf("Input a string to reverse : ");

    scanf("%s", str);

    printf("Reversed string is : ");
    for (i = strlen(str) - 1; i >= 0; i--){
        printf("%c", str[i]);
    }    

    return 0;
}