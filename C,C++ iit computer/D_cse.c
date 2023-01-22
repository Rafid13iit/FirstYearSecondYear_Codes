#include <stdio.h>
int main ()
{
    long long int a, b;
    while (scanf("%lld %lld", &a, &b) != EOF){

    a = a - b;

    if (a >= 0) printf("%lld\n", a);
    else printf("%lld\n", a*-1);
    }

    return 0;
}
