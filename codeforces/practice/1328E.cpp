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

v64 fathers, depth, tin, tout, used;
vv64 p;
ll timer = 0;

void preDfs(ll v, ll d, ll prev) {
  tin[v] = timer++;
  fathers[v] = prev;
  depth[v] = d;
  used[v] = 1;

  for (auto &u : p[v]) if (!used[u]) preDfs(u, d + 1, v);

  tout[v] = timer++;
}

bool comp(ll a, ll b) {
  return depth[a] < depth[b];
}

int main() {
  fast_cin();

  ll n, m;
  cin >> n >> m;
  fathers.resize(n);
  depth.resize(n);
  tin.resize(n);
  tout.resize(n);
  used.resize(n);
  p.resize(n);
  forn(i, n - 1) {
    ll x, y;
    cin >> x >> y; x--; y--;
    p[x].pb(y);
    p[y].pb(x);
  } preDfs(0, 0, -1);

  while(m--) {
    ll k;
    cin >> k;
    v64 q;
    forn(i,k) {
      ll x;
      cin >> x;
      x--;
      x = fathers[x];
      if (x != -1) q.pb(x);
    } sort(all(q), comp);
    bool good = true;
//    for (auto &i : q) cout << i << ' ';
//    cout << ln;
    forn(i,sz(q) - 1) {
//      cout << tin[q[i]] << ' ' << tin[q[i + 1]] << ' ' << tout[q[i]] << ' ' << tout[q[i + 1]] << ln;
      if ((tin[q[i]] > tin[q[i + 1]]) || (tout[q[i]] < tout[q[i + 1]])) good = false;
    } cout << (good ? "YES" : "NO") << ln;
  }


}