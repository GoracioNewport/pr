#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define INF 2e18
#define eps 10e-6

int main() {
	int n, k;
	cin >> n >> k;
	vector <int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	while(k--) {
		ll x;
		cin >> x;
		if (binary_search(a.begin(), a.end(), x)) cout << "YES" << endl;
		else cout << "NO" << endl;
	}	
}