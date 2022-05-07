#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {

	ios::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll t;
	cin >> t;
	for (int k = 0; k < t; k++) {
		// cout << "New\n";
		ll n, m;
		cin >> n >> m;
		vector <vector <ll>> preS(n, vector <ll> (m));
		vector <vector <ll>> preR(m, vector <ll> (n));
		vector <vector <ll>> ans;
		set <ll> firstRow;
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
			// cout << 1;
			cin >> preS[i][j];
			if (j == 0) firstRow.insert(preS[i][j]);
		} bool found = false;
		for (int i = 0; i < m; i++) {
			found = false;
			for (int j = 0; j < n; j++) {
				ll a;
				cin >> a;
				if (firstRow.count(a) > 0) {
					found = true;
					for (int o = 0; o < n; o++) {
						for (int g = 0; g < n; g++) {
							if (preS[g][0] == a) ans.push_back(preS[g]);
						}
						if (o != n - 1) cin >> a;
					}
				} if (found) break;
			}
		} for (auto &i : ans) {
			for (auto &j : i) cout << j << ' ';
			cout << endl;
		}
	}
}