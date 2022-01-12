// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
// #pragma GCC optimize("unroll-loops")
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

int main() {
  fast_cin();
  ll n;
  cin >> n;
  vp64 p(n);
  for (auto &i : p) cin >> i.fi >> i.se;
  v64 sel_e(n, -1), used(n, 0);
  vector <double> min_e(n, INF);
  min_e[0] = 0;
  double ans = 0;
  forn(i, n) {
    ll v = -1;
    forn(j, n) if (!used[j] && (v == -1 || min_e[j] < min_e[v])) v = j;
    used[v] = 1;
    if (sel_e[v] != -1) {
      // cout << v << ' ' << sel_e[v] << endl;
      
      ll x = abs(p[v].fi - p[sel_e[v]].fi);
      ll y = abs(p[v].se - p[sel_e[v]].se);
      double len = sqrt(x * x + y * y);
      ans += len;
    }
    forn(u, n) {
      ll x = abs(p[v].fi - p[u].fi);
      ll y = abs(p[v].se - p[u].se);
      double len = sqrt(x * x + y * y);
      if (len < min_e[u]) {
        min_e[u] = len;
        sel_e[u] = v;
      }
    }
  } cout << setprecision(10) << fixed << ans << endl;
}
