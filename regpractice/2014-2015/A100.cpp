#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll findP(ll a, ll b) {
	// cout << "------------" << endl;
	ll ans = 0;
	for(ll x = 1; x <= sqrt(a); x++) {
		ll yMaxS = (a / x);
		ll yMaxP = (b - 2 * x) / 2;
		ll y = min(yMaxS, yMaxP);
		if (y >= x) ans += y - x + 1;
		// for (ll i = x + 1; i <= y; i++) {
		// 	cout << x << ' ' << i << endl;
		// }
	} return ans;
}

int main() {
	ifstream in("hall.in");
	ofstream out("hall.out");

	ll a, b, c, d;
	in >> a >> b >> c >> d;
	// cout << x << ' ' << y << endl;
	out << findP(b, d) - findP(b, c - 1) - findP(a - 1, d) + findP(a - 1, c - 1) << endl;
	out.close();
}