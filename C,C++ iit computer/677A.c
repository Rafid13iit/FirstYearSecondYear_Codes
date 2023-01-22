#include <stdio.h>
int main ()
{
    int n, h;
    scanf("%d%d", &n, &h);

    int h_f[n];
    int i, width = 0;


    for (i=0; i<n; i++){
        scanf("%d", &h_f[i]);
    }


    for (i=0; i<n; i++){
        if (h_f[i] <= h) width++;
        else width = width + 2;
    }


    printf("%d", width);

    return 0;
}
