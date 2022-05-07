#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <ll> v64;
#define ln '\n'

int main() {
	// ifstream in;
	// ofstream out;
	// in.open("hall.in");
	// out.open("hall.out");
	ll a, b, c, d;
	cin >> a >> b >> c >> d;
	ll ans = 0;
	for(ll x = 1; x <= 10000; x++) {
		for (ll y = x; y <= 10000; y++) {
			if ((x * y >= a) && (x * y <= b) && ((2 * (x + y)) >= c) && ((2 * (x + y)) <= d)) {
				// if (x == y) ans++;
				ans++;
				cout << x<< ' ' << y << ln;
			}
		}
	} cout << ans << ln; 
	// out.close();
}
