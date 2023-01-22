#include <iostream>
using namespace std;

#define nl '\n'
typedef long long int ll;
typedef  unsigned long long int llu;

ll f(ll n) {
    ll result = 0;
    for (ll i = 1; i <= n; i++){
        result += (n % i);
    }

    return result;
}

int main() {
  ll L, R;
  cin >> L >> R;

  ll sum = 0;
  for (ll n = L; n <= R; ++n) {
    if (f(n) == f(n-1)) {
      sum += n;
    }
  }

  cout << sum;

  return 0;
}
