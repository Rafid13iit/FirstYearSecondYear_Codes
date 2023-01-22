#include<stdio.h>
int main()
{
    float f;

    for(f=1.0;(int)f<=9;f=f+.1) printf("%f\n",f);

    return 0;
}
