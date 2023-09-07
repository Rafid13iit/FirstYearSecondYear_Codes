#include<bits/stdc++.h>
using namespace std;

int josephus(int n,int k)
{
    if(n==1)
        return 1;
    else return (josephus(n-1,k)+k-1)%n+1;

}
int main()
{
    int n;
    cout << "Enter the number of person: ";
    cin >> n;

    int k;
    cout << "Enter the position of person to be cut :";
    cin >> k;

    int result=josephus(n,k);
    cout << "The person who is alive at last :" << result << endl;
    return 0;
}
