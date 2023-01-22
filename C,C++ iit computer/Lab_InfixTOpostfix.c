#include <stdio.h>
#include <string.h>

#define SIZE 20

int i, top1 = 0, top2 = 0, item = 0;
char input[SIZE], stack1[SIZE], stack2[SIZE];

void push(char a);

int main ()
{
    printf("Enter the infix expression :\n");
    scanf("%s", input); //5*(6+2)-12/4
                        //5+6-8*2+3/3

    for (i=0; i<strlen(input); i++){

        push(input[i]);

    }

    if (top1 != -1){
        for (i = top1-1; i>-1; i--){
            stack2[top2] = stack1[i];
            top2++;
        }
    }

    stack2[top2] = '\0';


    printf("%s\n", stack2);


}

void push(char a)
{
    if (a == '-' || a == '+' || a == '*' || a == '/' || a == '(' || a == ')'){

        if (top1 == 0){
            stack1[top1] = a;
            top1++;
        }

        else if (a == ')'){

            for (top1 = top1-1; !(stack1[top1] == '('); top1--){
                stack2[top2] = stack1[top1];
                top2++;
            }


        }

        else if ((a == '-' && stack1[top1-1] == '+') || (a == '-' && stack1[top1-1] =='*') || (a == '-' && stack1[top1-1] =='/') || (a == '+' && stack1[top1-1] =='*') || (a == '+' && stack1[top1-1] =='/') || (a == '*' && stack1[top1-1] =='/')) {
            stack2[top2] = stack1[top1-1];
            stack1[top1-1] = a;
            top2++;
        }

        else {
            stack1[top1] = a;
            top1++;
        }
    }

    else {
        stack2[top2] = a;
        top2++;
    }
}
