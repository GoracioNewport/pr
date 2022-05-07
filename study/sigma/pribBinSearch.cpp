#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  ll n, k;
  cin >> n >> k;
  vector <ll> ns(n);
  vector <ll> nk(k);

  for (auto &i : ns) cin >> i;
  for (auto &i : nk) cin >> i;

  for (ll i = 0; i < k; i++) {
    ll u = upper_bound(ns.begin(), ns.end(), nk[i]) - ns.begin();
    ll l = u - 1;

    if (u == 0) {
      cout << ns[0] << endl;
    } else {
      if (abs(ns[u] - nk[i]) >= abs(nk[i] - ns[l])) cout << ns[l] << '\n';
      else cout << ns[u] << '\n';
    }
  }
}
