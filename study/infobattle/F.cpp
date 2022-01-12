#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (ll)2e18

int main() {
  ll n;
  cin >> n;
  vector <ll> a(n);
  for (auto &i : a) cin >> i;
  vector <pair <ll,ll>> ans(n, {-1, n});
  stack <pair <ll,ll>> s;
  s.push({-INF, -1});
  for (ll i = 0; i < n; i++) {
    ll x = a[i];
    while (s.top().first > x) {
      ans[s.top().second].second = i;
      s.pop();
    } if (s.top().first == x) ans[i].first = ans[s.top().second].first;
    else ans[i].first = s.top().second;
    s.push({x,i});
  } for (auto &i : ans) {
    cout << i.first + 1 << ' ' << i.second + 1 << endl;
  }

}