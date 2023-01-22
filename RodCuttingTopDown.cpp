#include <iostream>
#define MAX 100
using namespace std;

int cutRod (int p[], int n)
{
    if (n == 0){
        return 0;
    }

    int q = -1;

    for (int i = 1; i <= n; i++){
        cout << q << endl;
        q = max(q, p[i] + cutRod(p, n-i)); //r(n-i) =  p[i] + cutRod(p, n-i)
    }

    return q;
}

int main ()
{
    freopen ("rodCut.txt", "r", stdin);
    
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

    cout << "Maximum profit : " << cutRod(p, n);

    return 0;
}