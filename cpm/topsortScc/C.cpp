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

vv64 p, r;
v64 used, path;

void dfsTop(ll v) {
  used[v] = true;
  for (auto& u : p[v]) if (!used[u]) dfsTop(u);
  path.pb(v);
}

void dfsColor(ll v, ll c) {
  used[v] = c;
  for (auto& u : r[v]) if (!used[u]) dfsColor(u, c);
}

int main() {
  fast_cin();

  ll n, m;
  cin >> n >> m;

  p.resize(n, v64());
  r.resize(n, v64());
  used.resize(n);
  vp64 edges;

  while(m--) {
    ll x, y;
    cin >> x >> y; x--; y--;
    edges.pb({x, y});
    p[x].pb(y);
    r[y].pb(x);
  } forn(i, n) if (!used[i]) dfsTop(i);
  reverse(all(path));
  forn(i,n) used[i] = 0;

  ll cnt = 0;

  for(auto& i : path) {
    if (!used[i]) {
      dfsColor(i, ++cnt);
    }
  } vp64 z;

  for (auto& i : edges) {
    if (used[i.fi] != used[i.se]) z.pb({used[i.fi], used[i.se]});
  } sort(all(z));
  z.erase(unique(all(z)), z.end());
  cout << sz(z) << ln;



}