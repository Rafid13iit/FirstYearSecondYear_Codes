#include <stdio.h>
int main ()
{
    char *p, ch;
    int i;

    p = &ch;
    for (i=0; i<10; i++){
        p[i] = 'A' + i;  /* wrong, we know, we can index a pointer only when N
                            that pointer points to an array */
    }

    return 0;
}

