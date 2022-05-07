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

vv64 p;
vp64 w;
v64 used;

bool DEBUG = false;

p64 dfs(ll v, ll c) {
  used[v] = c;
  ll l = -INF;
  ll r = INF;
  ll cnt = 0;

  for (auto& u : p[v]) {
    if (used[u] != c) {
      auto q = dfs(u, c);
      l = max(l, q.fi);
      r = min(r, q.se);
      cnt++;
    }
  } if (!cnt) {
    if (DEBUG) cout << v + 1 << " Leaf. Return: " << w[v].fi << ' ' << w[v].se << ln;
    return {w[v].fi, w[v].se};
  } else {
    if (DEBUG) cout << v + 1 << " Node. Return: " << l + w[v].fi << ' ' << r + w[v].se << ln;
    if (l + w[v].fi > r + w[v].se || l > r) return {2e9, -2e9};
    return {l + w[v].fi, r + w[v].se};
  }
}

int main() {
  fast_cin();

  ll n;
  cin >> n;
  p.resize(n, v64());
  w.resize(n);
  used.resize(n);

  forn(z,n - 1) {
    ll x, y;
    cin >> x >> y; x--; y--;
    p[x].pb(y);
    p[y].pb(x);
  } forn(z,n) {
    ll l, r;
    cin >> l >> r;
    w[z] = {l, r};
  } forn(i,n) {
//    if (i != 5) continue;
    if (DEBUG) cout << i + 1 << " -------" << ln;
    ll l = -INF;
    ll r = INF;
    used[i] = i + 1;
    for (auto& u : p[i]) {
      auto q = dfs(u, i + 1);
      if (DEBUG) cout << u << ' ' << q.fi << ' ' << q.se << ln;
      l = max(l, q.fi);
      r = min(r, q.se);
    } cout << (l <= r ? 1 : 0) << ' ';
    if (DEBUG) cout << l << ' ' << r << ln;
  }


}