#include<stdio.h>
#include<string.h>
#define max 100

int main()
{
    char str[max];
    char path[max];
    char f = 'a';
    int head = -1;

    printf("Enter your string : ");
    scanf("%s",str);

    int l = strlen(str);
    for(int i = 2 ; i<l ; ++i )
    {
        if(str[i] == '1' && str[i-1] == '1' && str[i-2] == '1' && f != 'd')
        {
            path[++head] = 'b';
            path[++head] = 'c';
            path[++head] = 'd';
            f = 'd';
        }
        else if(f == 'a')
        {
            path[++head] = 'a';
        }
        else if(f == 'd')
        {
            path[++head] = 'd';
        }
    }

    if(f == 'd')
    {
        printf("Your string is accepted!\n");
        printf("path : ");
        for(int j = 0 ; j <=head ; j++) printf("%c ",path[j]);
        printf("\n");
    }
    else printf("Your String is not accepted!\n");

    return 0;
}