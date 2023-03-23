#include <bits/stdc++.h>
using namespace std;
int main ()
{
    int t;
    cin >> t;

    while(t--)
    {
        string str, pattern;
        int sum = 0;

        cin >> str;
        cin >> pattern;

        for (int i = 0; i < str.length(); i++)
        {
            int k = i;
            for (int j = 0; j < pattern.length(); j++)
            {
                if (pattern[j] == str[k])
                {
                    if (j == pattern.length() - 1)
                    {
                        sum++;
                        //i = k;
                        break;
                    }

                    k++;
                    continue;
                }
                else
                {
                    break;
                }
                
            }
        }

        cout << sum << endl;
    }

    return 0;
}

/*
abcabbabaababc
ab

Ans -> 5

abcabbabaababc
abc

Ans -> 2
*/
