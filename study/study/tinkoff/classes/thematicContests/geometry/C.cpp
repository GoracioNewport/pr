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
  r(ld x, ld y) : x(x), y(y) {};
  r() {};

  ld len() {
   return hypot(x, y);
  }

  ld angle() {
    return atan2(y, x);
  }

  ld operator^(r o) {
    return (x * o.y - o.x * y);
  }
};

int main() {
  fast_cin();

  ll n, k, m;
  cin >> n >> m >> k;
  vector <r> p(n), q(m);
  for (auto& i : p) cin >> i.x >> i.y;
  for (auto& i : q) cin >> i.x >> i.y;
  ld startX = p[0].x, startY = p[0].y;

  for (auto& i : p) {
    i.x -= startX;
    i.y -= startY;
  } for (auto& i : q) {
    i.x -= startX;
    i.y -= startY;
  }

  ll ans = 0;
  for (auto& i : q) {

    if ((p[1]^i) < 0 || (p[sz(p) - 1]^i) > 0) {
      // cout << "SKIP" << ln;
      // cout << p[1].x << ' ' << p[1].y << ' ' << p[sz(p) - 1].x << ' ' << p[sz(p) - 1].y << ' ' << i.x << ' ' << i.y << ln << ln;
      continue;
    }

    ll l = 1;
    ll R = n;
    while(l + 1 < R) {
      ll m = (l + R) / 2;
      if ((p[m]^i) > 0) l = m;
      else R = m;
    }
    
    r r1(p[l].x - p[R].x, p[l].y - p[R].y);
    r r2(i.x - p[R].x, i.y - p[R].y);
    
    ans += ((r1^r2) <= 0);

    // cout << (r1^r2) << ln;
    // cout << r1.x << ' ' << r1.y << ' ' << r2.x << ' ' << r2.y << ln << ln;

  } cout << (ans >= k ? "YES" : "NO") << ln;



}