#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  ios::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll n, k, q;
  cin >> n >> k >> q;
  string s1;
  cin >> s1;
  while(q--) {
    ll l, r;
    cin >> l >> r;
    l--;
    string s = s1.substr(l,r);
    ll len = r - l + 1;
    // cout << s << endl; 
    ll ans = 0;
    for (int i = 0; i < (s.size() - k) + 1; i++) {
      if (s[i] == '1') {
        ans++;
        for (int j = i; j < i + k; j++) {
          if (s[j] == '0') s[j] = '1';
          else s[j] = '0';
        }
      }
    } ll cnt = 0;
    for (auto &i : s) cnt += (i == '0');
    if (cnt == s.size()) cout << ans << '\n';
    else cout << -1 << '\n'; 
  }
}