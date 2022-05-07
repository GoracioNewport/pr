#include <bits/stdc++.h>
using namespace std;
#define ll long long 

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	else return gcd(b, a % b);
}

int main() {
	ll a, b, c, d;
	cin >> a >> b >> c >> d;
	ll e = abs(a - c);
	ll f = abs(b - d);
	// cout << e << ' ' << f << ' ' << gcd(e, f) << endl;
	cout << e + f - gcd(e, f) << endl;
}