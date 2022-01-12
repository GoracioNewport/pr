#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  ll n, m, k;
  cin >> n >> m >> k;
  vector <vector <ll>> p(n, vector <ll> (m, 0));
  ll ans = 0;
  ll ansK = 0;
  for (auto &i : p) for (auto &j : i) cin >> j;
  for (int x1 = 0; x1 < n; x1++) {
    for (int y1 = 0; y1 < m; y1++) {
      for (int x2 = 0; x2 < n; x2++) {
        for (int y2 = 0; y2 < m; y2++) {
          // cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl;
          if ((abs(x1 - x2)) * (abs(y1 - y2)) < k) continue;
          ll mi = p[x1][y1];
          for (int I = x1; I <= x2; I++) {
            for (int J = y1; J <= y2; J++) {
              mi = min(p[I][J], mi);
            }
          } if (mi >= ans) {
            ans = mi;
            ansK = max(ansK, (ll)(abs(x1- x2) * abs(y1 - y2)));
          }
        } 
      }
    }
  } cout << ans << ' ' << ansK << endl;
}