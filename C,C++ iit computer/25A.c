#include <stdio.h>
#include <string.h>
int main ()
{
    int n, i;
    scanf("%d", &n);

    int a[n];
    for (i=0; i<n; i++){
        scanf("%d", &a[i]);
    }

    for (i=0; i<n; i++){

        if (((a[i+1] - a[i]) % 2 != 0) && ((a[i+2] - a[i+1]) % 2 == 0)){
            printf("%d", i+1);
            break;
        }
        else if (((a[i+1] - a[i]) % 2 != 0) && (a[i+1] != a[i+2])){
            printf("%d", i+1+1);
            break;
        }
    }

    return 0;
}
