#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	ll n;
	cin >> n;
	vector <ll> a(n);
	for (auto &i : a) cin >> i;
	ll len = sqrt(n) + 1;
	if (len % 2) len++;
	vector <ll> d(n / len + 1, 0);
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) d[i / len] += a[i];
		else  d[i / len] -= a[i];
	} ll q;
	cin >> q;
	// for (auto &i : d) cout << i << ' ';
	// cout << endl;

	while(q--) {
		ll t;
		cin >> t;
		if (t == 0) {
			ll i, j;
			cin >> i >> j;
			i--;
			if (i % 2 == 0) {
				d[i / len] -= a[i];
				d[i / len] += j;
			} else {
				d[i / len] += a[i];
				d[i / len] -= j;
			} a[i] = j;
		} else {
			ll l, r;
			cin >> l >> r;
			l--;
			r--;
			ll ans = 0;
			for (ll i = l; i <= r;) {
				if (i % len == 0 && i + len <= r) {
					if ((i - l) % 2 == 0) ans += d[i / len];
					else ans -= d[i / len];
					i += len;
				} else {
					if ((i - l) % 2 == 0) ans += a[i];
					else ans -= a[i];
					i++;
				}
			} cout << ans << '\n';
		}
	}
}