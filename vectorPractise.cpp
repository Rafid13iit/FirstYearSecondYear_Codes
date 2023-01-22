#include <iostream>
#include <vector>
using namespace std;
int main ()
{
    vector <int> v;

    //pushing random 10 int to the vector
    for (int i = 0; i < 10; i++){
        v.push_back(rand() % 100);
    }

    //vector <int> :: iterator it = v.begin();
    auto it = v.begin();

    for (it = v.begin(); it != v.end(); it++){
        cout << *it << " " << endl;
    }

    return 0;
}