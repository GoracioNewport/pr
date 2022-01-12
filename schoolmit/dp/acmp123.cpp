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

	for (int i = 1; i < n; i++) {
		dp[i][i - 1] = 0;
	}

	for (ll len = 1 ; len <= n; len++) {
		for (ll l = 0; l + len <= n; l++) {
			ll r = len + l - 1;
			if (len % 2 == 1) dp[l][r] = 0;
			else if 
		}
	}

}