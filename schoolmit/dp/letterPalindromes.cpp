#include <bits/stdc++.h>
using namespace std;
#define ll long long 

int main() {
	ios::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	cin >> s;

	ll n = s.size();

	vector <vector <ll>> dp(n, vector <ll> (n));
	for (ll i = 0; i < n; i++) {
		dp[i][i] = 1;
		if (i < n - 1) {
			if (s[i] == s[i + 1]) dp[i][i + 1] = 3;
			else dp[i][i + 1] = 2;
		}
	}

	for (ll len = 3; len <= n; len++) {
		for (ll l = 0; l + len <= n; l++) {
			ll r = l + len - 1;
			if (s[l] != s[r]) dp[l][r] = dp[l + 1][r] + dp[l][r - 1] - dp[l + 1][r - 1];
			else dp[l][r] = dp[l + 1][r] + dp[l][r - 1] + 1;
		}
	} cout << dp[0][n - 1] << endl;

}