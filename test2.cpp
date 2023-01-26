#include<bits/stdc++.h>
using namespace std;

struct State
{
    string name
}up[8];

void NfaToDfa(string s)
{
    string currentState = "a", previousState = "a";
    up[0].name = "a";
    up[1].name = "ab";
    up[2].name = "abc";
    up[3].name = "abcd";

    int currentIndex = 0;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == '0')
        {
            if(currentIndex <= 3)
            {
                cout << "(" << previousState << "," << s[i] << ")" << "->" << up[0].name << endl;
            }
            else
            {
                cout << "(" << up[3].name << "," << s[i] << ")" << "->" << up[0].name << endl;
            }
        }
        else if(s[i] == '1')
        {
            currentIndex++;
            if(currentIndex <= 3)
            {
                cout << "(" << up[currentIndex-1].name << "," << s[i] << ")" << "->" << up[currentIndex].name << endl;
            }
            else
            {
                cout << "(" << up[3].name << "," << s[i] << ")" << "->" << up[3].name << endl;
            }
        }
        previousState = up[currentIndex].name;
    }
}

int main()
{
    string input;
    cin >> input;
    int count = 0;
    char currentChar = 'a';
    for(int i = 0; i < input.size(); i++)
    {
        if(input[i] == '0' && count == 0)
        {
            count = 0;
            cout << "(" << currentChar << "," << input[i] << ")" << "->" << currentChar << endl;
            continue;
        }
        else if(input[i] == '1')
        {
            count++;
            cout << "(" << currentChar << "," << input[i] << ")";
            currentChar++;
            cout << "->" << currentChar << endl;
            if(count == 3)
            {
                break;
            }
        }
        else if(input[i] == '0' && count != 0)
        {
            count = 0;
            currentChar = 'a';
            cout << "(" << currentChar << "," << input[i] << ")" << "->" << currentChar << endl;
        }
    }
    if(count == 3)
    {
        cout << "The string is accepted" << endl;
        NfaToDfa(input);
    }
    else
    {
        cout << "The string is not accepted" << endl;
    }
}
