#include <stdio.h>
void input(int*x);

int main ()
{
    int a[10];
    int i;

    input (a);

    for (i=0; i<10; i++){
        printf("%d ", a[i]);
    }

    return 0;
}


void input(int*x)
{
    int i;

    for (i=0; i<10; i++){
        scanf("%d", x);
        x++;
    }
}
