#include <stdio.h>
void myputs (char *p);
int main ()
{
    myputs ("My name is Rafid. Do you know me? But, I know you! How can be this possible!");

    return 0;
}

void myputs (char *p)
{
    while (*p){
        printf("%c", *p);
        p++;
    }
    printf("\n");
}
