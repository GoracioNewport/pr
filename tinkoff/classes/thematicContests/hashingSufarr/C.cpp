//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
//#pragma GCC optimize("unroll-loops")
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

vv64 p;
vector <map <p64, ll>> z;
v64 used, w;

mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

p64 dfs(ll v) { // H, d
  used[v] = true;
  ll H = 0, d = 0;
  for (auto& u : p[v]) {
    if (!used[u]) {
      auto x = dfs(u);
      H += x.fi * 2;
      d = max(d, x.se);
    }
  } H += w[v];
  if (H < 0) H += LONG_LONG_MAX;
  z[d][mp(w[v], H)]++;
  return {H, d + 1};
}

int main() {
  fast_cin();

  ll n;
  cin >> n;
  p.resize(n, v64());
  used.resize(n);
  w.resize(n);
  z.resize(n);
  forn(i,n - 1) {
    ll x, y;
    cin >> x >> y; x--; y--;
    p[x].pb(y);
    p[y].pb(x);
  } for (auto& i : w) cin >> i;
  unordered_map <ll, ll> Z;
  for (auto& i : w) {
    if (!Z[i]) {
      ll x = rng();
      if (x < 0) x += LONG_LONG_MAX;
      Z[i] = x;
    }
  } for (auto& i : w) i = Z[i];
  dfs(0);

  ll ans = 0;
  for(auto& i : z) {
    for (auto& j : i) ans += j.se * (j.se - 1) / 2;
  } cout << ans << ln;

}