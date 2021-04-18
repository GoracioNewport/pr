#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll INF = 2e18;

int main() {
  ll a, b, k;
  cin >> a >> b >> k;
  if (k > 18) k = 18;
  ll ans = 0;
  for (ll i = max(a,(ll)(pow(10,k - 1))); i <= b; i++) {
    string s = to_string(i);
    // bool good = false;
    // if (k > s.size()) continue;
    for (ll j = 0; j <= (s.size() - k); j++) {
      bool locGood = true;
      // if (j + k > s.size()) continue;
      string s1 = s.substr(j, j + k);
      for (ll z = 0; z < s1.size() - 1; z++) if (s1[z] != s1[z + 1]) locGood = false;
      if (locGood) {
        ans++;
        break;
      }
    }
  } cout << ans << endl;
} 