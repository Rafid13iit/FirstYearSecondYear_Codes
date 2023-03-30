
//there is something Wrong in the code
// ?????

#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long long int llu;

int main ()
{
    //fixed DFA
    int nStates = 8, nStartStates = 1, nFinishingStates = 1, nSymbols = 2;
    int symbol_1 = 0, symbol_2 = 1;

    char startingState = 'A';
    char finishingState = 'E';

    char table[nStates][nStates]; //table to implement Table Filling Algorithm

    pair < map <int, char>, pair <char, char> > p[nStates]; // DFA state transition table, first is for the states,
                                            // and the second is for where it is going from that state using 0 and 1 symbols

    //Fixed DFA table
    cout << "Enter the DFA transition table : " << endl;
    for (int i = 0; i < nStates; i++)
    {
        char c;
        cin >> c;
        (p[i].first).insert({i, c});
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
            if (((p[i].first)[i] != finishingState && (p[j].first)[j] == finishingState) 
                    || ((p[i].first)[i] == finishingState && (p[j].first)[j] != finishingState))
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
                    if (table[(p[i].first).at((p[i].second).first)][(p[i].first).at((p[j].second).first)] == 'X') 
                    {
                        table[i][j] = 'X';
                        table[j][i] = 'X';
                    }
                        
                    else if (table[(p[i].first).at((p[i].second).second)][(p[i].first).at((p[j].second).second)] == 'X')
                    {
                        table[i][j] = 'X';
                        table[j][i] = 'X';
                    }

                    else continue;
                }
            }
        }

    }

    // printing the Table 
    cout << endl << "The table is : " << endl << "    ";
    for (int i = 0; i < nStates; i++)
    {
        cout << (p[i].first)[i] << "  ";
    }

    cout << endl << startingState << endl;
    for (int i = 1; i < nStates; i++)
    {
        cout << (p[i].first)[i] << "   ";

        for (int j = 0; j < i; j++)
        {
            if (table[i][j] == '=') cout << table[i][j] << "  ";
            else cout << table[i][j] << "  ";
        }
        cout << endl;
    }

    //printing the Equivalent states
    cout << endl << "Equivalent states are : " << endl;
    for (int i = 1; i < nStates; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (table[i][j] == '=')
            {
                cout << (p[i].first)[i] << " = " << (p[j].first)[j] << endl;
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

A C D
B H D
C F E
D E F
E A E
F F B
G E F
H F E

*/