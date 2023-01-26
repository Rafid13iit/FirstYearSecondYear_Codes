#include <bits/stdc++.h>
using namespace std;

struct State
{
    string name;
}up[8];

unordered_map<string, unordered_set<string>> transitionTable;
unordered_set<string> epsilonClosure(string state, unordered_map<string, unordered_set<string>> epsilonTransitions);
unordered_set<string> move(unordered_set<string> states, char symbol);

void NfaToDfa(string s)
{
    up[0].name = "a";
    up[1].name = "ab";
    up[2].name = "abc";
    up[3].name = "abcd";

    // building epsilon transitions
    transitionTable["a"] = {"ab"};
    transitionTable["ab"] = {"abc"};
    transitionTable["abc"] = {"abcd"};
    transitionTable["abcd"] = {};

    unordered_set<string> currentState = {"a"};
    for (int i = 0; i < s.size(); i++)
    {
        char symbol = s[i];
        currentState = move(epsilonClosure(currentState), symbol);
        cout << "(" << string(currentState.begin(), currentState.end()) << "," << symbol << ")" << "->";
        for (auto state : currentState)
        {
            cout << state << ",";
        }
        cout << endl;
    }
}

unordered_set<string> epsilonClosure(unordered_set<string> states, unordered_map<string, unordered_set<string>> epsilonTransitions)
{
    unordered_set<string> closure = states;
    queue<string> q;

    for (auto state : states)
    {
        q.push(state);
    }

    while (!q.empty())
    {
        string current = q.front();
        q.pop();

        for (auto nextState : epsilonTransitions[current])
        {
            if (closure.count(nextState) == 0)
            {
                closure.insert(nextState);
                q.push(nextState);
            }
        }
    }

    return closure;
}

unordered_set<string> move(unordered_set<string> states, char symbol)
{
    unordered_set<string> newStates;
    for (auto state : states)
    {
        if (transitionTable.count(state) == 0)
        {
            continue;
        }

        for (auto nextState : transitionTable[state])
        {
            if (nextState[0] == symbol)
            {
                newStates.insert(nextState);
            }
        }
    }

    return newStates;
}

int main()
{
    string input;
    cin >> input;

    NfaToDfa(input);
    cout << "The string is accepted" << endl;

    return 0;
}
