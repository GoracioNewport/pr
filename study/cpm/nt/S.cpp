#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ln '\n'

mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

ll gcd(ll a, ll b, ll& x, ll& y) {
  if (a == 0) {
    x = 0;
    y = 1;
    return b;
  } ll x1, y1;
  ll d = gcd(b % a, a, x1, y1);
  x = y1 - (b / a) * x1;
  y = x1;
  return d;
}

int main() {

  ll a, b, c;
  cin >> a >> b >> c;
  ll x, y;
  ll d = gcd(a, b, x, y);
  if (c % d) cout << -1;
  else {
    ll X = (x * (c / d));
    ll Y = (y * (c / d));

    ll B = b / d;
    ll A = a / d;

    while ((X > 1e9) || (Y < -1e9)) {
      X -= B;
      Y += A;
    }

    while ((X < -1e9) || (Y > 1e9)) {
      X += B;
      Y -= A;
    }

    if (X < -1e9 || Y < -1e9 || X > 1e9 || Y > 1e9) cout << -1 << ln;
    else cout << 0 << ln << X << ' ' << Y;
  }


}