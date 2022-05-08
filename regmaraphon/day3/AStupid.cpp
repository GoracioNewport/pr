#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  ll n;
  cin >> n;
  vector <ll> a(n);
  for (auto &i : a) cin >> i;
  
  vector <ll> one(n + 1, 0);
  one[1] = (a[0] == 1 ? 1 : 0);
  for (int i = 1; i < n; i++) {
    one[i + 1] = one[i];
    if (a[i] == 1) one[i + 1]++;
  }

  ll q;
  cin >> q;
  while(q--) {
    ll l, r;
    cin >> l >> r;
    ll len = r - l + 1;
    l--;
    if (one[r] - one[l] == len) cout << 2 << '\n';
    else cout << 1 << '\n';
  }
}