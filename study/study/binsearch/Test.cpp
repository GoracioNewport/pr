#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	int n, k;
	cin >> n >> k;
	vector <int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	while(k--) {
		ll x;
		cin >> x; // Нужно найти максимальный i такой, что a[i] >= x. Если таких нет, вывести n + 1.
		int l = -1;
		int r = n;
		while (l + 1 < r) {
			int m = (l + r) / 2;
			if (a[m] >= x) r = m;
			else l = m;
		} cout << r + 1 << endl;

	} 
}