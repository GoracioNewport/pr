// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
// #pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

// Author: @GoracioNewport

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 1791791791;
double eps = 1e-12;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

struct r {
  ld x, y;
  r () {};
  r (ld x, ld y): x(x), y(y) {};

  ld len() {
    return hypot(x, y);
  }

  ld angleRad() {
    return atan2(y, x);
  }

  ld angleDeg() {
    return angleRad() * (180.0 / M_PI);
  }
};

istream& operator>>(istream &in, r& a) {
  in >> a.x >> a.y;
  return in;
}

ostream& operator<<(ostream &out, const r& a) {
  out << a.x << ' ' << a.y << ln;
  return out;
}

r operator+(r a, r b) {
  return { a.x + b.x, a.y + b.y};
}

r operator-(r a, r b) {
  return {a.x - b.x, a.y - b.y};
}

ld operator*(r a, r b) { // Скалярное произведение
  return a.x * b.x + a.y * b.y;
}

ld operator^(r a, r b) {  // Векторное произведение
  return a.x * b.y - a.y * b.x;
}

ld rAngle(r a, r b) {
  return atan2(a ^ b, a * b);
}

struct segment {
  r p, q;
};

int main() {
  fast_cin();

  r a, b, c;
  cin >> a >> b >> c;

  b = b - a;
  c = c - a;

  cout << fixed << setprecision(20) << abs(b ^ c) / 2 << ln;
}