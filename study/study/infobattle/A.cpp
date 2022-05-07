#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct window {
    deque <pair <ll,ll>> d;
    ll l, r;

    window() {
      l = r = 0;
    }

    void push_back(ll x) {
      while (!d.empty() && d.back().first >= x) d.pop_back();
      d.push_back({x,r});
      r++;
    }

    void pop_front() {
      if (d.front().second == l) d.pop_front();
      l++;
    }

    ll getMin() {
      return d.front().first;
    }
};

int main() {
  ll n;
  cin >> n;
  vector <ll> a(2 * n);
  for (ll i = 0; i < n; i++) {
    cin >> a[i];
    a[i + n] = a[i];
  }

  vector <ll> prefSum(2 * n + 1);

  for (ll i = 0; i < 2 * n; i++) {
    prefSum[i + 1] = prefSum[i] + a[i];
  }

  ll ans = (ll)-2e18;
  window w;
  ll s = 0;
  for (ll i = 0; i < n; i++) {
    w.push_back(prefSum[i]);
    s += a[i];
  }
  for (ll i = n; i < 2 * n; i++) {
    s += a[i];
    w.pop_front();
    w.push_back(prefSum[i]);
    ans = max(ans, s - w.getMin());
  } cout << ans << endl;


}
