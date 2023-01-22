#include <iostream>
using namespace std;

struct user {
    string username;
    int age;
    string gender;
};

int main ()
{
    user users[10];

    users[0].username = "Rafid";
    users[1].username = "Rokaiya";

    users[0].age = 21;
    users[1].age = 23;

    for (int i = 0; i < 2; i++){
        cout << users[i].username << "'s age is " << users[i].age << endl;
    }

    return 0;
}