#include <stdio.h>
int main ()
{
    int n1, n2, i, j, count = 0;

    scanf("%d", &n1);
    int a[n1];

    for (i=0; i<n1; i++){
        scanf("%d", &a[i]);
    }

    scanf("%d", &n2);
    int b[n2];

    for (i=0; i<n2; i++){
        scanf("%d", &b[i]);
    }

    for (i=0; i<n1; i++){
        for (j=0; j<n2; j++){
            if (a[i] + b[j] == 10000){
                count++;
                break;
            }
        }
        if (count == 1) break;
    }

    if (count == 1) printf("YES");
    else printf("NO");


    return 0;
}
