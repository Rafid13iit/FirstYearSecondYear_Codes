#include <stdio.h>
#include <string.h>
int main ()
{
    int n;
    scanf("%d", &n);

    char a[n+1];
    scanf("%s", a);

    int k, count = 0;
    char i, j;

    for (i=65, j=97; i<=65+26, j<=97+26; i++, j++){
        for (k=0; k<n; k++){

            if (i == a[k] || j == a[k]){
                count++;
                break;
            }
        }
    }

    if (count >= 26) printf("YES");
    else printf("NO");


    return 0;
}
