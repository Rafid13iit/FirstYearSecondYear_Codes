#include <stdio.h>
#include <string.h>
int main ()
{
    char y[5], i, j;

    gets(y);

    if (y[3] == 9){
                y[3] = 0;
                y[2]++;
            }
    else y[3]++;


    for (i=0; i<3; i++) {
        for (j=i+1; j<4; j++){
            if (y[i] == y[j] && y[j] == 9){
                y[j] = 0;
                y[i]++;
            }
            else if (y[i] == y[j] && y[j] == 9 && y[i] == 9){
                y[j] = 0;
                y[i] = 0;
                y[i-1]++;
            }
            else if (y[i] == y[j]) y[j]++;
        }
    }

    printf("%s", y);

    return 0;
}
