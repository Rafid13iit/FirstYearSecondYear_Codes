#include <stdio.h>
#include <string.h>
int main ()
{
    char s[100], t[100];

    gets(s);
    gets(t);

    int i, j, count = 0;
    for (i=strlen(t)-1, j=0 ; i>=0, j<=strlen(s)+1 ; i--, j++){

        if (s[j] = t[i]) count++;
        else count = 0;
    }

    if (count >= strlen(s)+1) printf("YES");
    else printf("NO");

    return 0;
}
