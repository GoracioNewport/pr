#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool ok(ll w, ll h, ll n, ll x) {
	return (((x / w) * (x / h)) >= n);
}


int main() {
	ios::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll w, h, n; // MAX long long = 4e18;
	cin >> w >> h >> n;

	ll l = 0;
	ll r = 1;

	while(!ok(w, h, n, r)) r *= 2;


	while(l + 1 < r) {
		ll m = (l + r) / 2;
		if (ok(w, h, n, m)) r = m;
		else l = m;
	} cout << r << '\n';

}