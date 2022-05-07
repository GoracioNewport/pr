#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  ios::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll n;
  cin >> n;
  int ar[n];
  int dr[n];
  for (int i = 0; i < n; i++) cin >> ar[i] >> dr[i];
  int t;
  cin >> t;
  while (t--) {
    ll k;
    int l, r;
    cin >> l >> r >> k;
    l--;r--;
    ll mi = 2e18;
    for (int i = l; i <= r; i++) {
      mi = min(ar[i] + (dr[i] * (k - 1)), mi);
    }
    // for (int i = l; i <= r; i++) {
    //   a.push_back(ar[i]);
    //   d.push_back(dr[i]);
    // } for (int i = 0; i < a.size(); i++) {
    //   a[i] += (d[i] * (k - 1));
    // } ll mi = a[0];
    // for (auto &i : a) mi = min(i, mi);
    cout << mi << '\n';
  }
}