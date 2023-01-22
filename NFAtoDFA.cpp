#include<iostream>
#include<string>
using namespace std;

#define a 1
#define ab 2
#define abc 3
#define abcd 4
#define ad 5
#define abd 6

#define max 100

int main()
{
    char str[max];
    string path[max];
    int f = a;
    int head = -1;

    printf("Enter your string : ");
    scanf("%s",str);

    for(int i = 0 ; str[i] != '\0' ; i++)
    {
        switch(f)
        {
        case a :
            if(str[i] == '0')
            {
                f = a;
                head++;
                path[head] = "a";
            }
            else if(str[i] == '1')
            {
                f = ab;
                head++;
                path[head] = "ab";
            }
            break;
        case ab :
            if(str[i] == '0')
            {
                f = a;
                head++;
                path[head] = "a";
            }
            else if(str[i] == '1')
            {
                f = abc;
                head++;
                path[head] = "abc";
            }
            break;
        case abc :
            if(str[i] == '0')
            {
                f = a;
                head++;
                path[head] = "a";
            }
            else if(str[i] == '1')
            {
                f = abcd;
                head++;
                path[head] = "abcd";
            }
            break;
        case abcd :
            if(str[i] == '0')
            {
                f = ad;
                head++;
                path[head] = "ad";
            }
            else if(str[i] == '1')
            {
                f = abcd;
                head++;
                path[head] = "abcd";
            }
            break;
        case ad :
            if(str[i] == '0')
            {
                f = ad;
                head++;
                path[head] = "ad";
            }
            else if(str[i] == '1')
            {
                f = abd;
                head++;
                path[head] = "abd";
            }
            break;
        case abd :
            if(str[i] == '0')
            {
                f = ad;
                head++;
                path[head] = "ad";
            }
            else if(str[i] == '1')
            {
                f = abcd;
                head++;
                path[head] = "abcd";
            }
            break;

        }
    }

    if(f == abcd || f == abd || f == ad)
    {
        printf("Your string is accepted!\n");
        printf("path : ");
        for(int j = 0 ; j <=head ; j++) cout << path[j] << " ";
        printf("\n");
    }
    else printf("Your String is not accepted!\n");

    return 0;
}