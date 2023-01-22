#include <stdio.h>
int main ()
{
    char *cp, ch;
    int *ip, i;
    float *fp, f;
    double *dp, d;

    cp = &ch;
    ip = &i;
    fp = &f;
    dp = &d;

    printf("Print the current address:\n\n");
    printf("%p  %p  %p  %p\n\n", cp, ip, fp, dp); //to see address use %p in pointer

    cp++;
    ip++;
    fp++;
    dp++;

    printf("Print new address after increment:\n\n");
    printf("%p  %p  %p  %p\n\n", cp, ip, fp, dp);

    return 0;
}
