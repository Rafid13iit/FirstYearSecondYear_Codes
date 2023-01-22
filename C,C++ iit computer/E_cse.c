#include <stdio.h>
int main ()
{
    int t, i, j;
    scanf("%d", &t);

    int a[t][3];

    for (i=0; i<t; i++)
        for (j=0; j<3; j++){
        scanf("%d", &a[i][j]);
    }

    for (i=0; i<t; i++){
        if ((a[i][0] > a[i][1] && a[i][1] > a[i][2]) || (a[i][2] > a[i][1] && a[i][1] > a[i][0])) printf("Case %d: %d\n", i+1, a[i][1]);
        else if ((a[i][1] > a[i][0] && a[i][0] > a[i][2]) || (a[i][2] > a[i][0] && a[i][0] > a[i][1])) printf("Case %d: %d\n", i+1, a[i][0]);
        else printf("Case %d: %d\n", i+1, a[i][2]);
    }

    return 0;

}
