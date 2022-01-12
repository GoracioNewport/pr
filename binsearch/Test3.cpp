#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 2e18

bool good(ll w, ll h, ll n, ll a) {
	ll cnt = (a / w) * (a / h);
	return (cnt >= n);
}

int main() {
	ll w, h, n;
	cin >> w >> h >> n;
	ll l = 0;
	ll r = 1;
	while (!good(w,h,n,r)) r *= 2;
	while (l + 1 < r) {
		ll m = (l + r) / 2;
		if (good(w,h,n,m)) r = m;
		else l = m;
	} cout << r << endl;

}