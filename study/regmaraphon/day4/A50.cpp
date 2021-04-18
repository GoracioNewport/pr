#include <bits/stdc++.h>
using namespace std;
#define ll long long

enum { ANT, TRAP };

int main() {
  ll n, m;
  cin >> n >> m;
  vector <pair <ll, ll>> a(n);
  vector <ll> b(m);
  ll ind = 0;
  for (auto &i : a) {
    cin >> i.first;
    i.second = ind;
    ind++;
  } for (auto &i : b) cin >> i;
  vector <ll> ans(n, -1);
  
  for (int i = 0; i < m; i++) {
    auto it = upper_bound(a.begin(), a.end(), b[i]);
    if (it != a.begin()) {
      it--;
      // cout << "Found " << *it << endl;
      ans[it - a.begin()] = i;
      a.erase(it);
    } else cout << "No match" << endl;
  } for (auto &i : ans) cout << i + 1 << '\n';
}