#include <stdio.h>
int main ()
{
    int n;
    scanf("%d", &n);

    int room[n][2], i, j;

    for (i=0; i<n; i++){
        for (j=0; j<2; j++){
            scanf("%d", &room[i][j]);
        }

        printf("\n");
    }

    int count = 0;
    for (i=0; i<n; i++){
        if (room[i][0] <= (room[i][1]-2) ) count++;
    }

    printf("%d", count);

    return 0;

}
