#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> n >> k;
	vector <int> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	} while(k--) {
		int x;
		cin >> x;

		int l = -1;
		int r = n - 1;
		while(l + 1 < r) {
			int m = (l + r) / 2;
			if (a[m] <= x) l = m;
			else r = m;
		} cout << r << '\n';
	}

}