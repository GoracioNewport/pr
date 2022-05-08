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

int main() {
  fast_cin();

  ll n, m;
  cin >> n >> m;
  map <p64, ll> z;
  while(m--) {
    ll x, y, c;
    cin >> x >> y >> c; x--; y--;
    if (x == y) continue;
    if (z[{x, y}] == 0) z[{x, y}] = c;
    else z[{x, y}] = min(z[{x, y}], c);
  }

  vvp64 g(n);
  for (auto& i : z) {
    g[i.fi.fi].pb({i.fi.se, i.se});
    g[i.fi.se].pb({i.fi.fi, i.se});
  }

  v64 d(n, INF), p(n, -1);
  d[0] = 0;

  priority_queue <p64> q;
  q.push({0, 0});

  while(!q.empty()) {
    ll v = q.top().se, curD = -q.top().fi;
    q.pop();
    if (curD > d[v]) continue;

    for (auto& [u, w] : g[v]) {
      if (d[v] + w < d[u]) {
        d[u] = d[v] + w;
        p[u] = v;
        q.push({-d[u], u});
      }
    }
  } ll x = n - 1;
  if (d[n - 1] == INF) {
    cout << -1;
    return 0;
  }
  v64 path;
  while(x != -1) {
    path.pb(x);
    x = p[x];
  } reverse(all(path));
  for (auto& i : path) cout << i + 1 << ' ';

}