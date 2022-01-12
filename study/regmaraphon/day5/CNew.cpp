#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  ll a, b, k;
  cin >> a >> b >> k;
  ll ans = 0;
  for (ll i = max(a, (ll)pow(10, k - 1)); i <= b; i++) {
    string so = to_string(i);
    // cout << i << endl;
    for (int j = 0; j <= (so.size() - k); j++) {
      string s = so.substr(j, k);
      if (s.size() < k || (j + k > so.size())) continue;
      bool good = true;
      for (int z = 0; z < s.size() - 1; z++) if (s[z] != s[z + 1]) good = false;
      if (good) {
        ans++;
        // cout << so << endl;
        break;
      }
    }
  } cout << ans << endl;
}