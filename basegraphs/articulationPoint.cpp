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

vv64 p;
set <ll> ans;
vector <bool> used;
v64 tin, fup;
ll timer = 0;

void dfs(ll v, ll ps = -1) {
  // cout << v << endl;
  used[v] = true;
  tin[v] = fup[v] = timer++;
  ll child = 0;
  for (auto &u : p[v]) {
    if (u == ps) continue;
    if (used[u]) fup[v] = min(fup[v], tin[u]);
    else {
      dfs(u, v);
      fup[v] = min(fup[v], fup[u]);
      if (fup[u] >= tin[v] && ps != -1) {
        // cout << "ADD " << v << ' ' << u << endl;
        ans.insert(v);
      } child++;
    }
  } if (ps == -1 && child > 1) ans.insert(v);
}

int main() {
  fast_cin();
  
  ll n, m;
  cin >> n >> m;
  p.resize(n, v64 (0));
  tin.resize(n, 0);
  fup.resize(n, 0);
  used.resize(n, false);
  forn(i, m) {
    ll x, y;
    cin >> x >> y;
    x--;
    y--;
    p[x].pb(y);
    p[y].pb(x);
  } 
  
  // cout << "OK" << endl;
  
  forn(i, n) if (!used[i]) dfs(i);
  cout << sz(ans) << endl;
  for (auto &i : ans) cout << i + 1 << ln;
}
