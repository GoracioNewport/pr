#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll k = 29, mod = 1e9 + 7;
vector <ll> h, ks;

ll subHash(ll l, ll r) { // хеш s[l...r] в 0-индексации
	return ((h[r + 1] - ((h[l] * ks[r - l + 1]) % mod) + mod) % mod);
}

int main() {
	string s;
	cin >> s;
	ll n = s.size();
	h.resize(n + 1, 0);
	ks.resize(n + 1, 1);
	for(ll i = 0; i < n; i++) {
		ll x = (s[i] - 'a' + 1);
		ks[i + 1] = (ks[i] * k) % mod;
		h[i + 1] = (h[i] * k + x) % mod;
	} 

	ll m;
	cin >> m;
	while(m--) {
		ll a, b, c, d;
		cin >> a >> b >> c >> d;
		if (subHash(a - 1, b - 1) == subHash(c - 1, d - 1)) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
}