#include <stdio.h>
#include <string.h>
int main ()
{
    char s[100], t[100], temp[100];

    gets(s);
    gets(t);

    int i, j;
    for (i=strlen(t)-1, j=0 ; i>=0, j<=strlen(s)+1 ; i--, j++){
        temp[j] = t[i];
    }

    int x = strcmp(s, temp);

    if (x == 0) printf("YES");
    else printf("NO");

    return 0;
}
