#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector <ll> h;
vector <ll> ks;
const ll k = 239, mod = 1791791791;

ll sub_hash(ll l, ll r) {
  l++;
  r++;
  return ((h[r] - ((h[l - 1] * ks[r - l + 1]) % mod) + mod) % mod);
}

int main() {
  ll n, m;
  cin >> n >> m;
  string s;
  for(int i = 0; i < m; i++) {
    ll x, y;
    char z;
    cin >> x >> y >> z;
    s += z;
  } h.resize(m + 1, 0);
  ks.resize(m, 1);
  for(int i = 1; i < m; i++) ks[i] = ks[i - 1] * k;
  for(int i = 0; i < m; i++) {
    ll x = (s[i] - 'a' + 1);
    h[i + 1] = ((h[i] * k) + x) % mod;
  } pair <ll,ll> ans = {-1, -1};
  
  // for (auto &i : h) cout << i << ' ';
  // cout << endl;
  
  for(int len = 2; len <= m; len += 2) {
    for (int l = 0; l <= (m - len); l++) {
      ll r = l + len - 1;
      if (r >= n) continue;
      ll m = l + (len / 2) - 1;
      // cout << l << ' ' << m << endl;
      // cout << m + 1 << ' ' << r << endl;
      // cout << sub_hash(l, m) << endl;
      // cout << sub_hash(m + 1, r) << endl;
      // cout << endl;
      if (sub_hash(l, m) == sub_hash(m + 1, r)) {
        // cout << "MATCH" << endl;
        ans = {l, len};
        break;
      }
    } if (ans.first != -1) break;
  } if (ans.first == -1) cout << -1 << endl;
  else {
    cout << ans.second + 1 << endl;
    for (int i = ans.first; i <= ans.first + ans.second; i++) cout << i + 1 << ' ';
    cout << endl;
  }
}