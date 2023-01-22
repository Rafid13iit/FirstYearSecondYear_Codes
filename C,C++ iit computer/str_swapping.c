#include <stdio.h>
#include <string.h>
int main ()
{
    char s1[30]="madam";
    char s2[30]="hero alam";
    char temp[30];

    printf(s1);
    printf("\n");
    printf(s2);

    strcpy(temp, s1);
    strcpy(s1, s2);
    strcpy(s2, temp);

    printf("\n\n");

    printf(s1);
    printf("\n");
    printf(s2);

    return 0;
}
