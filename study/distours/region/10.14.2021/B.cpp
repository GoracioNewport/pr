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
 return (cntR * (a + b)) + (cntO * a) + (cntT * b);
}

int main() {

  freopen("forest.in", "r", stdin);
  freopen("forest.out", "w", stdout);

  ll a, k, b, m, x;
  cin >> a >> k >> b >> m >> x;
  ll l = -1;
  ll r = (ll)2e18;

//  for (ll i = 0; i <= 20; i++) cout << i << ' ' << cnt(a, k, b, m, x, i) << ln;

  while(l + 1 < r) {
    ll t = (l + r) / 2;
    ll X = cnt(a, k, b, m, x, t);
    if (X < x) l = t;
    else r = t;
  } cout << r << ln;
//  cout << cnt(a, k, b, m, x, r);

}