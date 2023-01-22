#include <stdio.h>
int main ()
{
    int n;
    scanf("%d", &n);

    int a[n][2], i, j;

    for (i=0; i<n; i++)
        for (j=0; j<2; j++){
        scanf("%d", &a[i][j]);
    }

    for (i=0; i<n; i++)
        for (j=0; j<1; j++){

            if (a[i][j] < a[i][j+1]) printf("<\n");
            else if (a[i][j] > a[i][j+1]) printf(">\n");
            else printf("=\n");
    }

    return 0;

}
