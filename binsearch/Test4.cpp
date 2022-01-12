#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define INF 2e18
#define eps = 10e-6

bool good(vector <ld> &a, ld x, ll k) {
	ll cnt = 0;
	for (int i = 0; i < a.size(); i++) {
		cnt += (a[i] / x);
	} return (cnt >= k);
}

int main() { 
	ld n, k;
	cin >> n >> k;
	vector <ld> a(n);
	for (ll i = 0; i < n; i++) cin >> a[i];
	ld l = 0;
	ld r = INF;
	for (ll z = 0; z < 200; z++) {
		ld m = (l + r) / 2;
		if (good(a, m, k)) l = m;
		else r = m; 
	} cout << setprecision(20) << fixed << l << endl;
}