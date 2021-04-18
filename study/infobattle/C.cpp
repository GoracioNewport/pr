#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ll n, m;
	cin >> n >> m;
	vector <ll> a(n + m);
	for (auto &i : a) cin >> i;
	ll p;
	ll cnt = n + m;
	ll offset = 0;
	while (cnt > 0) {
		// cout << "New Cycle, offset " << offset << endl;
		p = (m + offset) % (n + m);
		ll b = p;
		do {
			swap(a[offset % (n + m)], a[p % (n + m)]);
			p = (p + m) % (n + m);
			// cout << p << endl;	
			cnt--;	
		} while (b != p && cnt > 0);
		offset++;
	} for (auto &i : a) cout << i << ' ';
	cout << endl;
	
}