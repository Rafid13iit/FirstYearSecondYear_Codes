#include <stdio.h>
#include <string.h>

char *p[][2] = {
"Red Delicious", "red",
"Golden Delicious", "yellow",
"Winesap", "red",
"Lodi", "green",
" ", " "  //terminate the table with null strings
};

int main ()
{
    int i;
    char apple[30];

    printf("Enter the name of apple:\n");
    gets(apple);

    for (i=0; *p[i][0]; i++){
        if (!strcmp(apple, p[i][0])) printf("%s is %s\n", apple, p[i][1]);
    }

    return 0;
}
