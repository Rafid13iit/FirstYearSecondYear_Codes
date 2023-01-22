#include <stdio.h>
int main ()
{
    int x;
    float y;

    scanf("%d%f", &x, &y);

    if (x >= y || x % 5 != 0 || y - x -.50 < 0) printf("%.2f", y);
    else{
        printf("%.2f", y-x-.50);
    }

    return 0;
}
