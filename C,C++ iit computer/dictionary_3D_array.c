#include <stdio.h>
#include <string.h>
int main ()
{
    char main_words[2][5][15];
    char input_word[15];
    int i;

    //without using an extra variable j

    for (i=0; i<5; i++){
        gets (main_words[0][i]);
        gets (main_words[1][i]);
    }

    printf("Please enter a word to see meaning:\n");
    gets (input_word);

    for (i=0; i<5; i++){
        int c= strcmp(input_word, main_words[0][i]);
        if (c==0) printf("Meaning: %s", main_words[1][i]);
    }

}
