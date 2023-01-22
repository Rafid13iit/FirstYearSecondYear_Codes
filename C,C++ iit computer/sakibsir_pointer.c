#include <stdio.h>
#include <string.h>
void print_chg(char *x);

int main ()
{
    char c[20] = "Sakib";

    print_chg(c); //address as argument

    printf(c);
}

void print_chg(char *x) //so, taking parameter as pointer
{
    printf(x);

    strcpy(x, "Rafid");

}
