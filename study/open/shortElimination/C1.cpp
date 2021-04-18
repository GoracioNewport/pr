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

vv64 paths;
vv64 p;
vector <bool> used;

void dfs(ll i, vector <ll> path) {
  // cout << i << endl;
  path.pb(i);
  paths.pb(path);
  // cout << "My path: \n";
  // for (auto &i : path) cout << i << ' ';
  // cout << endl;
  used[i] = true;
  // cout << "Trying points...\n";
  forn(j, sz(p[i])) {
    // cout << i << ' ' << p[i][j] << endl;
    if (!used[p[i][j]]) dfs(p[i][j], path);
  }
}

int main() {
  fast_cin();
  
  ll n, q;
  cin >> n >> q;

  p.resize(n, vector <ll> (0, {}));
  
  for (int i = 0; i < n - 1; i++) {
    ll u, v;
    cin >> u >> v;
    p[u - 1].pb(v - 1);
    p[v - 1].pb(u - 1);
  } for (int i = 0; i < n; i++) sort(all(p[i]));
  ll c = 0;

  // cout << "EDGES\n";

  // forn(i, sz(p)) {
  //   cout << i << " - ";
  //   for (auto &j : p[i]) {
  //     cout << j << ' ';
  //   } cout << endl;
  // }

  // cout << "---------\n";

  used.resize(n);

  forn(i,n) {
    // cout << "DFS " << i << endl;
    forn(j, sz(used)) used[j] = false;
    dfs(i, {});
  } sort(all(paths));

  // cout << "---------\n";

  for (auto &i : paths) {
    for (auto &j : i) cout << j << ' ';
    cout << endl;
  }

  forn(z, q) {
    ll k;
    cin >> k;
    cout << paths[k - 1][0] + 1 << ' ' << paths[k - 1].back() + 1 << endl; 
  }
}
