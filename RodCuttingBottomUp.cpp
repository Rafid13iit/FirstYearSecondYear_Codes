#include <iostream>
#define MAX 100
using namespace std;

int bottomUpCutRod (int p[], int n) 
{
    int r[n];
    r[0] = 0;

    for (int j = 1; j <= n; j++){
        int q = -1;

        //this inner loop iterating through all possible cutting lengths.
        for (int i = 1; i <= j; i++){
            q = max(q, p[i] + r[j-i]);
            //the current profit of the cutting length (p[i])
            // the profit of the remaining rod (r[j-i]) or the previously calculated maximum profit (q).
        }

        r[j] = q;

        //cout << q << endl;
    }

    return r[n];
}

int main ()
{
    freopen ("rodCut2.txt", "r", stdin);
    
    int n, num;
    cout << "Enter the total length of the Rod : ";
    cin >> n;

    cout << "Enter the given number of cutting lengths : ";
    cin >> num;

    int l[MAX], p[MAX];

    cout << "Enter the cutting lengths : " << endl;
    for (int i = 1; i <= num; i++){
        cin >> l[i];
    }

    cout << "Enter the cutting lengths profits sequencially : " << endl;
    for (int i = 1; i <= num; i++){
        cin >> p[i];
    }

    cout << "Maximum profit : " << bottomUpCutRod(p, n);

    return 0;
}