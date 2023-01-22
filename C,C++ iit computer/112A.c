#include <stdio.h>
#include <string.h>
int main ()
{
    char a[100];
    gets(a);

    char b[strlen(a)+1];
    gets(b);

    for (int i='A'; i<='Z'; i++){
        i = i + 32;
    }

    int x = strcmp(a,b);

    if (x>0) printf("1");
    else if (x<0) printf("-1");
    else printf("0");

    return 0;
}
