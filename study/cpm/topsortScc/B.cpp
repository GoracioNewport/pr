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
v64 used, path;

void dfs(ll v) {
  used[v] = true;
  for (auto& u : p[v]) if (!used[u]) dfs(u);
  path.pb(v);
}

int main() {
  fast_cin();

  ll n, m;
  cin >> n >> m;
  vector <map <ll,ll>> r(n);
  p.resize(n, v64());
  used.resize(n);

  while(m--) {
    ll x, y;
    cin >> x >> y; x--; y--;
    p[x].pb(y);
    r[x][y]++;
  } forn(i,n) if (!used[i]) dfs(i);
  reverse(all(path));
  bool good = true;
  forn(i, n - 1) {
    if (r[path[i]][path[i + 1]] == 0) good = false;
  } if (good) {
    cout << "YES" << ln;
    for (auto& i : path) cout << i + 1 << ' ';
    cout << ln;
  } else cout << "NO" << ln;

}