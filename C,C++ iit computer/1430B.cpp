#include <bits/stdc++.h>
using namespace std;

int main ()
{
    long int n;
    scanf("%ld", &n);

    for (int i=0; i<n; i++){
        int num, pour;
        scanf("%d%d", &num, &pour);

        int a[num];
        for (int j=0; j<num; j++){
            scanf("%d", &a[j]);
        }

        sort(a,a+n);
        printf(a);

        int sum = a[num-1];
        for (int k=1; k<=pour; k++){
            sum = sum + a[num-k-1];
        }

        printf("%d", sum);
        printf("\n");
    }

    return 0;
}


