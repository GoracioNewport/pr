#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ln '\n'

ll mod = 1e9 + 7;

int main() {

  freopen("tiling.in", "r", stdin);
  freopen("tiling.out", "w", stdout);

  ll n, k;
  cin >> n >> k;
  vector <vector <ll>> p(2, vector <ll> (n, 0));
  for(ll i = 0; i < k; i++) {
    ll x, y;
    cin >> x >> y;
    p[y - 1][x - 1] = 1;
  } vector <vector <ll>> dp(n, vector <ll> (4, 0));

  dp[0][0] = dp[0][1] = dp[0][2] = dp[0][3] = 1;
  if (p[0][0]) dp[0][0] = dp[0][2] = 0;
  if (p[1][0]) dp[0][0] = dp[0][1] = 0;
  if (!p[0][0] && !p[1][0]) dp[0][3] = 2;

  for (ll i = 1; i < n; i++) {
    if (!p[0][i] && !p[1][i]) {
      dp[i][0] = dp[i - 1][3];
      dp[i][1] = (dp[i - 1][3] + dp[i - 1][2]) % mod;
      dp[i][2] = (dp[i - 1][3] + dp[i - 1][1]) % mod;
      dp[i][3] = ((dp[i - 1][3] * 2) + dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][0]) % mod;
    } else if (p[0][i] && !p[1][i]) {
      dp[i][0] = 0;
      dp[i][1] = dp[i - 1][3];
      dp[i][2] = 0;
      dp[i][3] = (dp[i - 1][3] + dp[i - 1][1]) % mod;
    } else if (!p[0][i] && p[1][i]) {
      dp[i][0] = 0;
      dp[i][1] = 0;
      dp[i][2] = dp[i - 1][3];
      dp[i][3] = (dp[i - 1][3] + dp[i - 1][2]) % mod;
    } else if (p[0][i] && p[1][i]) {
      dp[i][0] = 0;
      dp[i][1] = 0;
      dp[i][2] = 0;
      dp[i][3] = dp[i - 1][3];
    }
  }

  cout << dp[n - 1][3] << ln;


}