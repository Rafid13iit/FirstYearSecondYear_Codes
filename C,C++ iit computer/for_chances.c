#include <stdio.h>
int main ()
{
    int i, chances, ans, right;

    printf("Welcome to the game of MATH! \n");
    printf("You will get 3 chances to solve the problem.\n");
    printf("Let's start!\n\n");

    for (i=1; i<=10; i++){
        printf("What is the answer of %d * %d ?\n", i, i);
        scanf("%d", &ans);

        if (ans==i*i){
            printf("Correct answer!\n\n");
        }

        else{
            printf("You are Wrong! Try again.\n\n");

            right=0;
            for (chances=1; chances<=2 && right==0; chances++){

                printf("What is the answer of %d + %d ?\n", i, i);
                scanf("%d", &ans);

                if (ans==i*i){
                    printf("Correct!\n\n");
                    right=1;
                }

                else{
                    printf("Wrong again.\n\n");
                }

            }

            if (right==0){
                printf("Your chances are over! The answer is %d.\n\n", i*i);
            }

        } //else ends here
    }//For ends here

    return 0;
}
