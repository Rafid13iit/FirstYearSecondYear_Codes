#include <stdio.h>
#include <string.h>
int main ()
{
    char S[100];
    gets(S);
    char T[strlen(S)];
    gets(T);

    int i, count = 0, x = 1;
    char temp;

    x = strcmp(S, T);

    for (i=0; i<strlen(S)-1; i++){
        if (S[i] == T[i+1] && S[i+1] == T[i]){
                count++;
                temp = T[i];
                T[i] = T[i+1];
                T[i+1] = temp;
        }
    }

    if ((count == 1 && strcmp(S, T) == 0)  ||  (count == 0 && strcmp(S, T) == 0)  ||  x == 0) printf("YES");
    else printf("NO");

    return 0;
}
