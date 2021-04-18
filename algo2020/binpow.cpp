#include <bits/stdc++.h>
using namespace std;
#define ll long long 

ll binpow(ll a, ll n) {
	if (n == 0) return 1;
	if (n % 2 == 0) {
		ll b = binpow(a, n / 2);
		return b * b;
	} else return binpow(a, n - 1) * a;
}

int main() {
	ll a, n;
	cin >> a >> n;
	cout << binpow(a, n) << endl;
}