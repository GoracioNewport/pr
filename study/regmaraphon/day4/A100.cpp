#include <bits/stdc++.h>
using namespace std;
#define ll long long

enum { ANT, TRAP };

int main() {
  ll n, m;
  cin >> n >> m;
  vector <ll> ans(n, -1);
  vector <pair <ll, pair <ll,ll>>> p; // <координата, <тип, id>>
  vector <ll> a(n);
  vector <ll> b(m);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    p.push_back({a[i], {ANT, i}});
  } for (int i = 0; i < m; i++) {
    cin >> b[i];
    p.push_back({b[i], {TRAP, i}});
  } sort(p.begin(), p.end());
  // for (auto &i : p) {
  //   cout << i.first << ' ' << i.second.first << ' ' << i.second.second << endl;
  // }
  stack <ll> c;
  for (int i = 0; i < p.size(); i++) {
    if (p[i].second.first == ANT) c.push(p[i].second.second);
    else {
      if (!c.empty()) {
        ll ind = c.top();
        c.pop();
        ans[ind] = p[i].second.second;
      }
    }
  } for (auto &i : ans) cout << (i == -1 ? -1 : i + 1) << '\n';
}