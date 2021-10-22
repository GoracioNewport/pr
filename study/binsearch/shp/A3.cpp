#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

bool ok(ld w, ld h, ld n, ld x) {
	return (((ll)(x / w) * (ll)(x / h)) >= n);
}


int main() {
	ld w, h, n;
	cin >> w >> h >> n;

	ld l = 0;
	ld r = 2;

	while(!ok(w, h, n, r)) r *= 2;

	for (ll i = 0; i < 100; i++) {
		ld m = (l + r) / 2;
		if (ok(w, h, n, m)) r = m;
		else l = m;
	} cout << fixed << setprecision(20) << r << '\n';

}