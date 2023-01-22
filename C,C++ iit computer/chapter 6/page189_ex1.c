#include <stdio.h>
int main ()
{
    float *fp, **mfp, val;

    fp = &val;
    mfp = &fp;

    **mfp = 123.123;

    printf("%f", **mfp);

    return 0;
}
