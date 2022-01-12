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
  r (pdd x): x(x.fi), y(x.se) {};

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
ld getDist(pair <pdd, pdd> l, pdd a) {

  ld x1 = l.fi.fi;
  ld y1 = l.fi.se;
  ld x2 = l.se.fi;
  ld y2 = l.se.se;
  ld x3 = a.fi;
  ld y3 = a.se;

  ld dx = x2 - x1;
  ld dy = y2 - y1;
  ld mag = sqrt(dx*dx + dy*dy);
  dx /= mag;
  dy /= mag;

  ld lambda = (dx * (x3 - x1)) + (dy * (y3 - y1));
  ld x4 = (dx * lambda) + x1;
  ld y4 = (dy * lambda) + y1;

//  cout << x3 << ' ' << y3 << ' ' << x4 << ' ' << y4 << ln;

//  cout << (x4 <= max(x1, x2)) << (x4 >= min(x1, x2)) << (y4 <= max(y1, y2)) << (y4 >= min(y1, y2)) << ln;

  ld ans = ((x4 <= max(x1, x2)) && (x4 >= min(x1, x2)) && (y4 <= max(y1, y2)) && (y4 >= min(y1, y2)) ? hypot(abs(a.fi - x4), abs(a.se - y4)) : INF);
//  cout << ans << ln;
  return min(ans, min(hypot(abs(x1 - x3), abs(y1 - y3)), hypot(abs(x2 - x3), abs(y2 - y3))));
}

ld dist(pdd a, pdd b) {
  return hypot(abs(a.fi - b.fi), abs(a.se - b.se));
}

ld area (r a, r b, r c) {
  return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

bool intersect_1 (ld a, ld b, ld c, ld d) {
  if (a > b)  swap (a, b);
  if (c > d)  swap (c, d);
  return max(a,c) <= min(b,d);
}

bool intersect (r a, r b, r c, r d) {
  return intersect_1 (a.x, b.x, c.x, d.x)
         && intersect_1 (a.y, b.y, c.y, d.y)
         && area(a,b,c) * area(a,b,d) <= 0
         && area(c,d,a) * area(c,d,b) <= 0;
}

ld segDist(pair <pdd, pdd> l, pair <pdd, pdd> d) {

  if (intersect(r(l.fi), r(l.se), r(d.fi), r(d.se))) return 0;

  ld a = min(
          min(dist(l.fi, d.fi), dist(l.fi, d.se)),
          min(dist(l.se, d.fi), dist(l.se, d.se))
  );

  ld c = min(
          min(getDist(l, d.fi), getDist(l, d.se)),
          min(getDist(d, l.fi), getDist(d, l.se))
  );

  return min(a, c);
}

int main() {
  fast_cin();

  ld a, b, c, d, e, f, g, h;
  cin >> a >> b >> c >> d >> e >> f >> g >> h;
  ld x = segDist({{a, b}, {c, d}}, {{e, f}, {g, h}});
  cout << fixed << setprecision(20) << x << ln;
//  cout << (x == 0 ? "YES" : "NO") << ln;
}