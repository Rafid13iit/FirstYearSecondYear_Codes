#include <iostream>
#define MAX 1000
using namespace std;

int F[MAX][MAX], length, numOfCut, c[MAX], i, j;

void BreadCut ()
{
    //setting all values 0 of the 2D array
    for (i = 0; i <= numOfCut; i++){
        F[c[i]][c[i+1]] = 0;
    }  
    // or, memset(F, 0, sizeof F);

    for (i = 0; i <= numOfCut; i++){
         cout << F[c[i]][c[i+1]] << " ";
    }

    

    return ;
}

int main ()
{
    cin >> length >> numOfCut;

    c[0] = 0;
    for (i = 1; i <= numOfCut; i++){
        cin >> c[i];
    }
    c[numOfCut+1] = length;

    BreadCut ();

    return 0;
}
