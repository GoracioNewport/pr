#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ln '\n'

ll gcd(ll a, ll b) {
  if (b == 0) return a;
  else return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
  return a / gcd(a, b) * b;
}

ll cnt(ll a, ll k, ll b, ll m, ll x, ll t) {
  ll cntZ = t / lcm(k, m);
  ll cntO = (t / k) - cntZ;
  ll cntT = (t / m) - cntZ;
  ll cntR = t - cntZ - cntO - cntT;
  // cout << lcm(k, m) << ln;
  // cout << cntZ << ' ' << cntO << ' ' << cntT << ' ' << cntR << ' ' << t << ln;
  bool overflow = false;
  ll len1 = (to_string(cntO)).size() + (to_string(b)).size() - 1;
  ll len2 = (to_string(cntT)).size() + (to_string(a)).size() - 1;
  if (max(len1, len2) >= 19) return (ll)2e18;
  return (cntR * (a + b)) + (cntO * b) + (cntT * a);
}

int main() {

  freopen("forest.in", "r", stdin);
  freopen("forest.out", "w", stdout);

  ll a, k, b, m, x;
  cin >> a >> k >> b >> m >> x;
  ll l = -1;
  ll r = 1;
  while(cnt(a, k, b, m, x, r) <= x) r *= 2;

//  for (ll i = 0; i <= 20; i++) cout << i << ' ' << cnt(a, k, b, m, x, i) << ln;

  while(l + 1 < r) {
    ll t = (l + r) / 2;
    ll X = cnt(a, k, b, m, x, t);
    if (X < x) l = t;
    else r = t;
  } cout << r << ln;
//  cout << cnt(a, k, b, m, x, r);

}