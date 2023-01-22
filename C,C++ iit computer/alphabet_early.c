#include <stdio.h>
int main ()
{
    char ch1, ch2='z';
    int i;

    printf("Please input your letters: \n");
    for (i=1; i<=10; i++){
        ch1 = getchar();
        getchar();
        if (ch1<ch2) ch2 = ch1;
    }

    printf("\nThe letter which comes earliest in alphabet is : %c\n", ch2);

    return 0;
}
