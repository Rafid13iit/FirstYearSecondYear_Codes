#include<bits/stdc++.h>
using namespace std;

int main()
{
    int locations, connections;

    cout << "How many locations are there?\n";
    cin >> locations;

    int location[locations][locations] = {-1}, visitedOrNot[locations] = {0};

    cout << "How many connections are there among the locations?\n";
    cin >> connections;

    cout << "Input the locations and route cost which connect each other (for example: A B 15):\n";
    for(int i = 0; i < connections; i++){
        char place_1, place_2;
        int cost;

        cin >> place_1 >> place_2 >> cost;

        //The expression (int)(a-'A') will cast the result of a-'A' to an integer.
        //For example, if a is the character 'C', then a-'A' would evaluate to 2 ...
        int place_1_INT = (int)(place_1-'A');
        int place_2_INT = (int)(place_2-'A');

        location[place_1_INT][place_2_INT] = cost;
        location[place_2_INT][place_1_INT] = cost;
    }

    char destination; 
    cout << "Input your destination location : ";
    cin >> destination;

    cout << "Best route using Greedy Algo. : A";
    visitedOrNot[0] = 1;


    for(int i = 0; i < locations; ){
        int shortDistance = 100000, in;
        char ch;

        for(int j = 0; j < locations; j++){
            if(location[i][j] != -1){
                if(location[i][j] < shortDistance && visitedOrNot[j] != 1){

                    shortDistance = location[i][j];
                    ch = (char)('A'+j);
                    in = j;
                }
            }
        }

        cout << " -> " << ch;
        if(ch == destination) break;

        visitedOrNot[in] = 1;
        i = in;

    }
    cout << endl;

    return 0;
}

/*

8
10
A B 15
B C 11
C D 27
D E 7
E F 19
F G 13
A G 25
A H 10
H D 20
H E 2
D

*/