#include <bits/stdc++.h>
using namespace std;
#define ll long long

set <ll> c;

ll binpow(ll a, ll n, ll k) {
	if (n == 0) return a;
	else if (n % 2 == 0) {
		ll b = binpow(a, n / 2, k);
		return (b * b) % k;
	} else return (binpow(a, n - 1, k) * a) % k;
}

void factorization(ll a) {
	ll n = a;
	for (int i = 2; i * i <= n; i++) {
		while (a % i == 0) {
			c.insert(i);
			a /= i;
		}
	}
	if (a > 1) c.insert(a);
}

int main() {
	ll a;
	cin >> a;
	factorization(a);
	ll y = 1;
	
	for (auto &i : c) {
		y*= i;
	}

	if (y >= 29) {
		cout << y << endl;
	} else {
		for (int i = 1; i <= 29; i++) {
			if (binpow(y * i, y * i, a) % a == 0) {
				cout << y * i << endl;
				break;
			}
		}
	}
}