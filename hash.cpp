#include <bits/stdc++.h>
using namespace std;
#define ll long long 

vector <ll> h;
vector <ll> ks;

const ll k = 239, mod = 1791791791;

ll sub_hash(ll l, ll r) {
	
}

int main() {

	ios::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	cin >> s;
	ll n = s.size();

	h.resize(n + 1, 0);
	ks.resize(n + 1, 1);

	for (int i = 0; i < n; i++) ks[i + 1] = (ks[i] * k) % mod;
	for (int i = 0; i < n; i++) {
		ll x = (s[i] - 'a' + 1);
		h[i + 1] = (((h[i] * k) % mod) + x) % mod;
	}

	for (auto &i : h) cout << i << ' ';
	cout << endl;


}