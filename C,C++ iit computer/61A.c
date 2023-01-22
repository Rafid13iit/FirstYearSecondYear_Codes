#include <stdio.h>
#include <string.h>
int main ()
{
    int i;
    char a[101];
    scanf("%s", a);

    char b[strlen(a)+1];
    scanf("%s", b);

    for (i=0; i<strlen(a); i++){

            if (a[i] == '1' && b[i] == '1') printf("0");
            else if (a[i] == '1' && b[i] == '0') printf("1");
            else if (a[i] == '0' && b[i] == '1') printf("1");
            else if (a[i] == '0' && b[i] == '0') printf("0");
    }

    return 0;
}
