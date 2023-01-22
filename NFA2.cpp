//only to check is there any 111 as substring in the string

#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

int main() 
{
    int states, count = 0;
	char start, final;
	char str[MAX_LEN];

	printf("How many states?\n");
	scanf("%d", &states);

	printf("Let, starting state is : A\n");
	start = 'A';
 
	printf("Your states are :\n");
	for (char x = start; x < start + states; x++){
		printf("%c ", x);
		final = x;
	}

	printf("\nLet, final state is : %c\n", final);

	printf("Input a bit string : ");
	scanf("%s", str);

	int i = 0, temp = 0;
    char state = start;

    printf("One possible path is :\n");

    for (int i = 0; i < strlen(str); i++) {

        if (str[i] == '1' && str[i+1] == '1' && str[i+2] == '1' && count == 0) {
            if (state == start) {
                state += 1;
                printf("(%c,1) -> %c\n", state-1 , state);
            } 
            if (state == start+1) {
                state += 1;
                printf("(%c,1) -> %c\n", state-1 , state);
            } 
            if (state == start+2) {
                state += 1;
                printf("(%c,1) -> %c\n", state-1 , state);
            }
            
            i += 2;
            count++;
        } 
        
        else {
            //state = start;
            printf("(%c,%c) -> %c\n", state , str[i], state);
        }
    }

    if (state == final){
        printf("ACCEPTED, string contains 111 as substring.\n");
        return 0;
    }

    printf("NOT ACCEPTED, as NFA can not reach it's final state, so string does not contain 111 as substring.\n");
    return 0;
}
