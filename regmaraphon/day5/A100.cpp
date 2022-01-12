#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  ll n, l;
  cin >> n >> l;
  ll ans = 0;
  for (int z = 0; z < n; z++) {
    ll r, s, t;
    cin >> r >> s >> t;
    if (l == 1) {
      ans++;
      continue;
    } ll posF = s % (2 * l - 2);
    bool left = false;
    // cout << posF << endl;
    if (posF > l) {
      // cout << "Hi\n";
      left = true;
      posF = (2 * l - posF);
    } ll timeF = 0;
    if (left) {
      if (r <= posF) timeF = posF - r;
      else timeF = (posF + r) - 2;
    } else {
      if (r >= posF) timeF = r - posF;
      else timeF = ((l - posF) + (l - r)) - 2;
    } if (timeF <= t) {
      // cout << "YES\n";
      ans++;
    } // else cout << "NO\n";
    // cout << timeF << endl;
    // cout << left << endl;
  } cout << ans << '\n';
}