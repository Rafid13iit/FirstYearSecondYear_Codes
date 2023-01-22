#include <stdio.h>
int main ()
{
    int a[4], i;

    for (i=0; i<3; i++){
        scanf("%d", &a[i]);
    }

    for (i=0;;){
        a[i]++;
        a[i+1]++;
        a[i+2]++;

        printf("%d%d%d", a[i],a[i+1],a[i+2]);
        break;
    }

    return 0;
}
