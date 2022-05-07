#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    string l;
    cin >> l;
    ll n = l.size();
    vector <vector <ll>> dp(n, vector <ll> (n));
    for (ll i = 0; i < n; i++) dp[i][i] = 1;

    for (ll j = 1; j < n; j++) {
      for (ll i = (j - 1); i >= 0; i--) {
        dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
      }
    }

    cout << dp[0][n - 1] << endl;

}
