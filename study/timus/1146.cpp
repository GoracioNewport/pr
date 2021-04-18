#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  ll n, m;
  cin >> n;
  m = n;
  vector <vector <ll>> a(n, vector <ll> (m));
  for (ll i = 0; i < n; i++) {
    for (ll j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }

  vector <vector <ll>> prefSum(n, vector <ll> (m + 1));
  for (ll i = 0; i < n; i++) {
    for (ll j = 0; j < m; j++) {
      prefSum[i][j + 1] = prefSum[i][j] + a[i][j];
    }
  }

  ll ans = (ll)-2e18;

  for (ll l = 0; l < m; l++) {
    for (ll r = l; r < m; r++) {
      vector <ll> b(m);
      for (ll i = 0; i < n; i++) {
        b[i] = prefSum[i][r + 1] - prefSum[i][l];
      }

      ll locans = b[0];
      ll sum = 0;
      ll minSum = 0;
      for (ll r1 = 0; r1 < n; r1++) {
        sum += b[r1];
        locans = max(ans, sum - minSum);
        minSum = min(minSum, sum);
      } ans = max(ans, locans);
    }
  } cout << ans << endl;

}
