#include <stdio.h>
int main ()
{
    int team;
    scanf("%d", &team);

    int a[team][2], i, j, count = 0;

    for (i=0; i<team; i++){
        for (j=0; j<2; j++){
           scanf("%d", &a[i][j]);
        }
    }

    for (i=0; i<team; i++){
        for (j=0; j<team; j++){
            if (a[i][0] == a[j][1] && a[i][0] != a[i][1]) count++;
        }
    }

    printf("%d", count);

    return 0;
}
