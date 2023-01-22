#include <stdio.h>
int main ()
{
    char football[100];

    gets(football);

    int i, count = 0;

    for (i=0; i<100; i++){

        if (football[i] == football[i+1]) count++;
        else count = 0;

        if (count = 7) break;
    }

    if (count = 7) printf("YES");
    else printf("NO");

    return 0;
}
