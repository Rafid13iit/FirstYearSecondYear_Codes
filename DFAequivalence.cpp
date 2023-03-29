#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long long int llu;

int main ()
{
    //fixed DFA
    int nStates = 8, nStartStates = 1, nFinishingStates = 1, nSymbols = 2;
    int symbol_1 = 0, symbol_2 = 1;

    int startingState = 0;
    int finishingState = 4;

    char table[nStates][nStates]; //table to implement Table Filling Algorithm

    pair <int, pair <int, int> > p[nStates]; // DFA state transition table, first is for the states,
                                            // and the second is for where it is going from that state using 0 and 1 symbols

    //Fixed DFA table
    cout << "Enter the DFA transition table : " << endl;
    for (int i = 0; i < nStates; i++)
    {
        cin >> p[i].first;
        cin >> (p[i].second).first >> (p[i].second).second;
    }

    //initially unmarking all pairs in the table
    for (int i = 0; i < nStates; i++)
    {
        for (int j = 0; j < nStates; j++)
        {
            table[i][j] = '='; // unmarked as it can be equivalent
        }
    }

    //mainly Table Filling Algorithm starts from here
    
    // Step - 1
    for (int i = 1; i < nStates; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if ((i != finishingState && j == finishingState) || (i == finishingState && j != finishingState))
            {
                table[i][j] = 'X'; // marked the pair as not equivalent
                table[j][i] = 'X';
            }
        }
    }

    
    for (int thisProcess = 1; thisProcess <= 100; thisProcess++)
    {
        //Step - 2
        
        for (int i = 1; i < nStates; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (table[i][j] == '=')
                {
                    if (table[(p[i].second).first][(p[j].second).first] == 'X') 
                    {
                        table[i][j] = 'X';
                        table[j][i] = 'X';
                    }
                        
                    else if (table[(p[i].second).second][(p[j].second).second] == 'X')
                    {
                        table[i][j] = 'X';
                        table[j][i] = 'X';
                    }

                    else continue;
                }
            }
        }

    }


    cout << endl << "The table is : " << endl;
    for (int i = 1; i < nStates; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (table[i][j] == '=') cout << table[i][j] << "  ";
            else cout << table[i][j] << "  ";
        }
        cout << endl;
    }


    cout << endl << "Equivalent states are : " << endl;
    for (int i = 1; i < nStates; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (table[i][j] == '=')
            {
                cout << i << " = " << j << endl;
            }
        }
    }

    
    return 0;
}

/*
0 2 3
1 7 3
2 5 4
3 4 5
4 0 4
5 5 1
6 4 5
7 5 4
*/