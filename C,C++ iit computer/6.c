#include <stdio.h>
int main ()
{
    int i, j, count = 0, sum = 0;
    long long int n, m;
    scanf("%lld%lld", &n, &m);

    int a[n];
    for (i=0; i<n; i++){
        scanf("%d", &a[i]);

    }

    for (i=0; i<n-1; i++){
            sum = a[i];
        for (j=i+1; j<n; j++){
            sum = sum + a[j];
            if (sum == m) {
                    printf("Yes");
                    count = 1;
                    break;
            }

        }
        if (count = 1) break;
    }

    if(count != 1){

    for (i=0; i<n-1; i++){
        for (j=i+1; j<n; j++){
            if (a[i] + a[j] == m){
                printf("Yes");
                count = 1;
                break;
            }

        }
        if (count = 1) break;
    }
    }

    if (count != 1) printf("No");

    return 0;
}
