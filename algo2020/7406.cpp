#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll binpow(ll a, ll n, ll p) {
	if (n == 0) return 1;
	else if (n % 2 == 0) {
		ll b = binpow(a, n / 2, p);
		return (b * b) % p;
	} else return (binpow(a, n - 1, p) * a) % p;
}

int main() {
	ios::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll a, p, t;
	cin >> t;
	for (ll i = 0; i < t; i++) {
		cin >> p >> a;
		cout << binpow(a, p - 2, p) % p << endl;
	}
}