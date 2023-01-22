#include <stdio.h>
int main ()
{
    long long int a, b;
    scanf("%lld%lld", &a, &b);

    if (b % a == 0) printf("YES");
    else printf("NO");

    return 0;
}
