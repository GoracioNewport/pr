#include <bits/stdc++.h>
using namespace std;
#define ll long long

mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

int main() {
	int n, k;
	cin >> n >> k;
	vector <int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	while(k--) {
		int x;
		cin >> x;
		int l = -1;
		int r = n;
		while (l + 1 < r) {
			int m = (rng() % r) + l + 1;
			if (a[m] <= x) l = m;
			else r = m;
		} if (l != n && a[l] == x) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}