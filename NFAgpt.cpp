#include <stdio.h>
#include <stdbool.h>

#define MAX_LEN 100

int main() 
{
    char str[MAX_LEN+1];
    printf("Enter a string: ");
    scanf("%s", str);

    int state = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        char c = str[i];

        if (c == '1') {
            if (state == 0) {
                state = 1;
            } 
            else if (state == 1) {
                state = 2;
            } 
            else if (state == 2) {
                printf("String contains 111 as a contiguous sequence of characters\n");
                return 0;
            }
        } 
        
        else {
            state = 0;
        }
    }

    printf("String does not contain 111 as a contiguous sequence of characters\n");
    return 0;
}
