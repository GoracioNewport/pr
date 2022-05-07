#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ios::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll n;
	cin >> n;
	vector <ll> m(n);
	for (auto &i : m) cin >> i;

	vector <vector <double>> dp(n, vector <double> (n, -1));
	for (int i = 0; i < n; i++) dp[i][i] = m[i];

	for (ll len = 2; len <= n; len++) {
		for (ll l = 0; l < n - len + 1; l++) {
			ll r = l + len - 1;
			double res = 0;
			for (ll m = l; m < r; m++) {
				res = max(res, (dp[l][m] + dp[m + 1][r]) / 2);
			} dp[l][r] = res;
		}
	} cout << dp[0][n - 1] << endl;
}