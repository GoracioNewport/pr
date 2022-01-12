#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  ll n;
  cin >> n;
  vector <ll> ar(n);
  vector <ll> dr(n);
  for (int i = 0; i < n; i++) {
    cin >> ar[i] >> dr[i]; 
  }
  ll t;
  cin >> t;
  while(t--) {
    ll l, r, k;
    cin >> l >> r >> k;
    vector <ll> a;
    vector <ll> d;
    l--;
    r--;
    for (int i = l; i <= r; i++) {
      a.push_back(ar[i]);
      d.push_back(dr[i]);
    } ll ans = 0;
    for (int t = 0; t < k; t++) {
      // for (auto &i : a) cout << i << ' ';
      // cout << endl;
      ll mi = a[0];
      for (auto &i : a) mi = min(mi, i);
      ans = max(ans, mi);
      for (int i = 0; i < a.size(); i++) a[i] += d[i];
    } cout << ans << endl; 
  }
}