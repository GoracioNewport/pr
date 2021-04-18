#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

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

long double getDist(p64 a, p64 b) {
  ll x = abs(a.fi - b.fi);
  ll y = abs(a.se - b.se);
  return sqrt((x * x) + (y * y));
}

int main() {
  fast_cin();
  
  ll n, m;
  cin >> n >> m;

  if (m != 2) {
    vp64 ns(n);
    vp64 ms(m);
    for (auto &i : ns) cin >> i.fi >> i.se;
    for (auto &i : ms) {
      cin >> i.fi >> i.se;
      ll a;
      cin >> a;
    } long double ans = 0;
    for (auto &i : ns) {
      long double l = getDist(i, ms[0]);
      for (auto &j : ms) l = min(l, getDist(i, j));
      ans = max(ans, l);
    } cout << setprecision(20) << fixed << ans << endl;
  } else {
    vp64 ns(n);
    vp64 ms(m);
    v64 p(m);
    for (auto &i : ns) cin >> i.fi >> i.se;
    forn(i,m) cin >> ms[i].fi >> ms[i].se >> p[i];
    double l = 0;
    double r = INF;
    forn(z,200) {
      double m = (l + r) * .5;
      bool good = true;
      ll cntO = p[0];
      ll cntT = p[1];
      forn(i,n) {
        double o = getDist(ns[i], ms[0]);
        double t = getDist(ns[i], ms[1]);
        if (o > m && t > m) good = false;
        else if (o <= m && t <= m) {
          // if (cntT > 0) cntT--;
          // else cntO--;
        } else {
          if (o <= m) cntO--;
          else cntT--;
        }
      } if (cntO < 0 || cntT < 0) good = false;
      if (good) r = m;
      else l = m;
    } cout << setprecision(20) << fixed << l << ln;
  }

}
