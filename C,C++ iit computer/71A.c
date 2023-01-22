#include <stdio.h>
#include <string.h>
int main ()
{
    int n;

    scanf("%d", &n);


    for (int i=1; i<=n; i++){
    char a[100];
    gets(a);
    getchar();

    if (strlen(a)>10) {
        printf("%c%d%c\n", a[0], strlen(a)-2, a[strlen(a)-1]);
    }
    else {
        printf(a);
    }

    }

    return 0;
}
