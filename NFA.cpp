#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100
int main ()
{
	int states;
	char start, final;
	char str[MAX];

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

	//printf("%s\n", str);

	int i = 0, temp = 0;

	for (char x = start; x < start + states && i <= strlen(str); x++, i++){

		if (x == final){
			printf("The string is ACCEPTED as it reaches in the final state!\n");
			temp = 1;
			break;
		}

		if (str[i] == '0') {
  			printf("(%c,0) -> %c\n", x , start);
			x = start;
			x--;
		}

		else if (str[i] == '1') {
			printf("(%c,1) -> %c\n", x , x+1);
		}
	}

	if (temp == 0){
		printf("The string is NOT ACCEPTED as it can not reach in the final state!\n");
	}

	return 0;
}

