#include <bits/stdc++.h>
using namespace std;
int main ()
{
    vector <long long int> v;
    
    long long n, i, temp, max = 1, count = 1;
    cin >> n;
    
    cin >> temp;
    v.push_back(temp);
    
    for (i = 1; i < n; i++){
        cin >> temp;
        v.push_back(temp);
        
        if (v.at(i) >= v.at(i-1)) {
            count++;
            if (max <= count) max = count;
        }
        else{
            count = 1;
        }
    }
    
    cout << max;
 
    return 0;
}