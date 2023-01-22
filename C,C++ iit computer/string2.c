#include <stdio.h>
int main ()
{
    char a[80]={"Sakib Al Hasan"}, b[60];
    int i;

    //copy a to b without using strcpy function

    for (i=0; a[i]; i++){
        b[i]=a[i];
    }

    b[i]='\0';
    printf("%s\n\n", b);

    //concatenation d to c without using strcat function

    char c[80]={"Rakib"};
    char d[60]={" Ul Hasnain"};
    int j;

    for (i=0; c[i]; i++);
    for (j=0; d[j]; j++){
        c[i]=d[j];
        i++;
    }

    d[j]='\0';
    printf("%s\n\n", c);

    //counting Length without strlen function

    char e[80]={"Bangladesh"};
    char f[60]={"Saudi Arab"};

    for (i=0; e[i]; i++);
    printf("\nLength of e: %d\n", i);

    for (j=0; f[j]; j++);
    printf("\nLength of f: %d\n", j);

    return 0;
}
