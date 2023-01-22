#include <bits/stdc++.h>
using namespace std;

#define nl '\n'
typedef long long int ll;
typedef  unsigned long long int llu;

set <long long int> s;

void countDivisor (long long int n)
{
	for (ll i = 1; i <= sqrt(n); i++){
		if (n % i == 0){

			s.insert(i);
			s.insert(n / i);
		}
	}
}

int main ()
{
	ll t, n;
	cin >> t;

	while(t--){
		cin >> n;

		countDivisor (n);

		cout << s.size() << endl;

		for (auto it : s){
			cout << it << " ";
		}
		cout << endl;
		s.clear();
	}

	return 0;
}