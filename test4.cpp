#include <bits/stdc++.h>
using namespace std;

int main()
{
    int num_states, num_transitions;
    cin >> num_states >> num_transitions;

    char transition_matrix[num_states][num_transitions][num_states];
    map<int, string> state_names;
    map<char, int> state_indices;
    map<int, string> epsilon_transitions;
    int starting_index = 0;
    char state_name;

    for(int i = 0; i < num_states; i++)
    {
           cin >> state_name;
           state_names[starting_index] = state_name;
           state_indices[state_name] = starting_index;
           starting_index++;
    }

    for(int i = 0; i < num_states; i++)
    {
        for(int j = 0; j < num_transitions; j++)
        {
            for(int k = 0; k < num_states; k++)
            {
                cin >> transition_matrix[i][j][k];
            }
        }
    }

    cout << "    E-NFA table" << endl;

    for(int i = 0; i < num_states; i++)
    {
        for(int j = 0; j < num_transitions; j++)
        {
            for(int k = 0; k < num_states; k++)
            {
                cout << transition_matrix[i][j][k] << " ";
            }
            cout << "|";
        }
        cout << endl;
    }

    for(int i = 0; i < num_states; i++)
    {
        epsilon_transitions[i] = state_names[i];
        for(int j = 0; j < num_states; j++)
        {
            if(transition_matrix[i][num_transitions-1][j] != '0' && 
               epsilon_transitions[i] != to_string(transition_matrix[i][num_transitions-1][j]))
            {
                epsilon_transitions[i] += transition_matrix[i][num_transitions-1][j];
            }
        }
    }

    for(int i = 0; i < num_states; i++)
    {
        for(int j = 1; j < epsilon_transitions[i].length(); j++)
        {
            if(epsilon_transitions[state_indices[epsilon_transitions[i][j]]].length() > 1)
            {
                for(int k = 1; k < epsilon_transitions[state_indices[epsilon_transitions[i][j]]].length(); k++)
                {
                    if(epsilon_transitions[i].find(epsilon_transitions[state_indices[epsilon_transitions[i][j]]][k]) == string::npos)
                    {
                        epsilon_transitions[i] += epsilon_transitions[state_indices[epsilon_transitions[i][j]]][k];
                    }
                }
            }
        }
    }

    cout << " Epsilons" << endl;

    for(int i = 0; i < num_states; i++)
    {
        cout << state_names[i] << " ---> " << epsilon_transitions[i] << endl;
    }

    map<int, map<int, string>> new_transition_matrix;
    int power = pow(2, num_states);
    string new_states_array[power];
    new_states_array[0] = epsilon_transitions[0];
    map<string, int> new_states_map;
    new_states_map[epsilon_transitions[0]] = 1;
    vector<char> each_state;
    int start_index = 0, end_index = 1;

    while(start_index < end_index)
    {
        for(int x = 0; x < num_transitions-1; x++)
        {
            for(int i =
