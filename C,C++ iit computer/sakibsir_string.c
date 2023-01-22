#include <stdio.h>
#include <string.h>
int main ()
{
    char iit[]="I love my country, and I also love IIT.";
    char to_find[10];
    int string_len, word_len;

    printf("The given string is : ");
    printf(iit);

    printf("\nPlease write a word to find from the string: \n");
    gets(to_find);

    string_len = strlen(iit);
    word_len = strlen(to_find);

    int i, j, found = 0;
    for (i=0; i<string_len; i++){
        found = 1;

        for (j=0; j<word_len; j++){
            if (iit[i+j] != to_find[j]){
                found=0;
                break;
            }
        }

        if (found == 1 && j == word_len - 1){
            printf("\n\n'%s' found at: %d\n", to_find, i);
        }
    }



    //new portion, new code below:


    int num_word=0;
    for (i=0; i<=string_len; i++){
        if (iit[i]==' ') num_word++;
    }

    printf("\nThe number of words in the given string is: %d\n", num_word+1);

    printf("The words are:\n\n");

    for (i=0; i<=string_len; i++){

        if (iit[i]==',' || iit[i]=='.') iit[i]='\0';
        printf("%c", iit[i]);

        if (iit[i]==' ') printf("\n");
    }

    return 0;
}
