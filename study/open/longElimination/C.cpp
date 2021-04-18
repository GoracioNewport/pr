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
typedef vector<vector<p32> > vvp32;
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

ll n, m, k, s;
vvp32 p;
v64 used;
v32 z;

void dfs(int v, ll l) {
  // cout << "DFS " << v << endl;
  if (z[v]) l = 0;
  used[v] = l;
  for (auto &i : p[v]) if (used[i.fi] > (l + i.se) && (l + i.se <= s)) dfs(i.fi, l + i.se);
}

int main() {
  fast_cin();
  cin >> n >> m >> k >> s;
  p.resize(n, vp32 ());
  used.resize(n, INF);
  z.resize(n, 0);
  forn(i,m) {
    int u, v, c;
    cin >> u >> v >> c;
    u--;
    v--;
    p[u].pb({v,c});
    p[v].pb({u,c});
  } forn(i,k) {
    int a;
    cin >> a;
    a--;
    z[a] = 1;
  } dfs(0, 0);
  v32 ans;
  forn(i,n) if (used[i] <= s) ans.pb(i);
  cout << sz(ans) << endl;
  sort(all(ans));
  for (auto &i : ans) cout << i + 1 << ' ';
  cout << endl;
  // for (auto &i : used) cout << i << ' ';
  // cout << endl;
}
