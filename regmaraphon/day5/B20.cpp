#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll INF = 2e18;

int main() {
  ll n;
  cin >> n;
  vector <ll> hs(n);
  vector <ll> as(n);
  for (auto &i : hs) cin >> i;
  ll ma = hs[0];
  ll mi = hs[0];
  for (auto &i : hs) {
    ma = max(i, ma);
    mi = min(i, mi);
  }
  for (auto &i : as) cin >> i;
  pair <ll, ll> ans = {INF, INF};
  for (int i = mi; i <= ma; i++) {
    ll locAns = 0;
    for (int j = 0; j < n; j++) {
      locAns += (abs(hs[j] - i) * as[j]);
    } if (locAns < ans.second) {
      ans.first = i;
      ans.second = locAns;
    }
  } cout << ans.first << ' ' << ans.second << endl;
}