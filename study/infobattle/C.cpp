#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  ll n, m;
  cin >> n >> m;
  vector <ll> a(n + m);
  for (auto &i : a) cin >> i;

  if (n == m) {
    for (ll i = 0; i < n; i++) {
      swap(a[i], a[i + n]);
    }
  }

  else {
    ll p = m;
    for (ll i = 0; i < (n + m) - 1; i++) {
      swap(a[0], a[p]);
      p = (p + m) % (n + m);
      if (p == 0 && i < (n + m) - 2) {
        p = (p + m) % (n + m);
        swap(a[0], a[p]);
        p = (p + m) % (n + m);
      }
    }
  }

  for (auto &i : a) cout << i << ' ';
  cout << endl;
}