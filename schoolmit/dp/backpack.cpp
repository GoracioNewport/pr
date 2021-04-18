#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ll n, m;
	cin >> n >> m;
	vector <pair <ll, ll>> diamonds(n);
	for (auto &i : diamonds) cin >> i.first >> i.second;
	vector <vector <ll>> dp(n + 1, vector <ll> (m + 1, 0));
	
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			if (j - diamonds[i - 1].first < 0) dp[i][j] = dp[i - 1][j];
			else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - diamonds[i - 1].first] + diamonds[i - 1].second);
		}
	} cout << dp[n][m] << endl;

}