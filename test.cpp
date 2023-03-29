#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long long int llu;

int main ()
{
    //fixed DFA
    int nStates = 5, nStartStates = 1, nFinishingStates = 1, nSymbols = 2;
    int symbol_1 = 0, symbol_2 = 1;

    int startingState = 0;
    int finishingState = 4;

    int table[nStates][nStates]; //table to implement Table Filling Algorithm

    pair <int, pair <int, int> > p[nStates]; // DFA state transition table, first is for the states,
                                            // and the second is for where it is going from that state using 0 and 1 symbols

    //Fixed DFA table
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
            table[i][j] = -1; // unmarked
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
                table[i][j] = 1; // marked the pair
                table[j][i] = 1;
            }
        }
    }

    //Step - 2
    for (int thisProcess = 1; thisProcess <= 100; thisProcess++)
    {

        for (int i = 1; i < nStates; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (table[i][j] == -1)
                {
                    if (table[(p[i].second).first][(p[j].second).first] == 1) 
                    {
                        table[i][j] = 1;
                        table[j][i] = 1;
                    }
                        
                    else if (table[(p[i].second).second][(p[j].second).second] == 1)
                    {
                        table[i][j] = 1;
                        table[j][i] = 1;
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
            if (table[i][j] == -1) cout << table[i][j] << "  ";
            else cout << " " << table[i][j] << "  ";
        }
        cout << endl;
    }


    cout << endl << "Equivalent states are : " << endl;
    for (int i = 1; i < nStates; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (table[i][j] == -1)
            {
                cout << i << " = " << j << endl;
            }
        }
    }

    
    return 0;
}

/*
0 1 2
1 1 3
2 1 2
3 1 4
4 1 2
*/