#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  ll n, q;
  cin >> n >> q;
  for (int i = 0; i < n - 1; i++) {
    ll a, b;
    cin >> a >> b;
  } while (q--) {
    ll k;
    cin >> k;
    vector <pair <ll, ll>> a(k);
    ll ind = 0;
    for (auto &i : a) {
      cin >> i.first;
      i.second = ind;
      ind++;
    } sort(a.begin(), a.end());
  }
}