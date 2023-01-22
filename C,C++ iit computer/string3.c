#include <stdio.h>
int main ()
{
    char s1[30];

    printf("Enter your full name: \n");
    scanf("%s", &s1);

    printf("Your full name is: %s \n", s1); //scanf don't shows the words after space

    return 0;
}
