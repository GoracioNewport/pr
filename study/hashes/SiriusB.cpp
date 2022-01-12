#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll k = 239, mod = 1791791791;

vector <ll> ks;
vector <ll> hrg;
vector <ll> hrw;

ll subhash(vector <ll> &h, ll l, ll r) {
	return ((h[r] - ((h[l - 1] * ks[r - l + 1]) % mod) + mod) % mod);
}

int main() {
	ios::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	cin >> s;
	s += s;
	ll n = s.size();

	ks.resize(n + 1, 1);
	hrg.resize(n + 1, 0);
	hrw.resize(n + 1, 0);

	for (int i = 0; i < n; i++) {
		ks[i + 1] = (ks[i] * k) % mod;
		ll x = (s[i] - 'a' + 1);
		hrg[i + 1] = ((hrg[i] * k) + x) % mod;
		ll y = (s[n - i - 1] - 'a' + 1);
		hrw[i + 1] = ((hrw[i] * k) + y) % mod; 
	}
	// cout << s << endl;
	// for (auto &i : hrg) cout << i << ' ';
	// cout << endl;
	// for (auto &i : hrw) cout << i << ' ';
	// cout << endl;

	ll ans = -1;

	for (int i = 1; i <= (n / 2); i++) {
		// cout << subhash(hrg, i, (n / 4) + i - 1) << ' ' << i << ' ' << (n / 4) + i - 1 << endl;
		// cout << subhash(hrw, (n / 2) + 2 - i, (n / 2) + 1 - i + (n / 4)) << ' ' << (n / 2) + 2 - i << ' ' << (n / 2) + 1 - i + (n / 4) <<  endl;
		if (subhash(hrg, i, (n / 4) + i - 1) == subhash(hrw, (n / 2) + 2 - i, (n / 2) + 1 - i + (n / 4))) ans = i;
	} cout << ans << endl;

}