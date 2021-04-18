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

ll n, m;
vv64 p, pr;
v64 used;
v64 topSorted;
v64 points;

void dfs(ll v) {
  // cout << v << endl;
  used[v] = true;
  for (auto &i : p[v]) if (!used[i]) dfs(i);
  topSorted.pb(v);
}

void topSort() {
  forn(i, n) if (!used[i]) dfs(i);
  reverse(topSorted.begin(), topSorted.end());
}

void dfsSCC(ll v) {
  used[v] = true;
  points.pb(v);
  for (auto &i : pr[v]) if (!used[i]) dfsSCC(i);
}

int main() {
  fast_cin();
  
  cin >> n >> m;

  vp64 edg;
  used.resize(n, false);
  p.resize(n, v64(0));;
  pr.resize(n, v64(0));

  forn(i, m) {
    ll x, y;
    cin >> x >> y;
    if (x != y) edg.pb({x - 1, y - 1});
  } 
  
  sort (all(edg));
  auto last = unique(edg.begin(), edg.end());
  edg.resize(last - edg.begin());

  for(auto &i : edg) {
    p[i.fi].pb(i.se);
    pr[i.se].pb(i.fi);
  } map <ll, ll> scc;
  
  // for (auto &i : pr) {
  //   for (auto &j : i) {
  //     cout << j << ' ';
  //   } cout << endl;
  // }


  topSort();
  forn(i,n) used[i] = false;

  // for (auto &i : topSorted) {
  //   cout << i << ' ';
  // } cout << endl;

  // for (auto &i : used) cout << i << ' ';
  // cout << endl;
  
  for(auto &i : topSorted) {
    if (!used[i]) {
      dfsSCC(i);
      for (auto &j : points) scc[j] = i;
      points.clear();
    }
  } 
  
  vp64 edgSCC;
  
  // for (auto &i : scc) {
  //   cout << i.se << " - " << i.fi << endl;
  // }

  for (auto &i : edg) {
    if (scc[i.fi] != scc[i.se]) edgSCC.pb({scc[i.fi], scc[i.se]});
  } 
  
  sort(all(edgSCC));
  last = unique(edgSCC.begin(), edgSCC.end());
  edgSCC.resize(last - edgSCC.begin());
  
  cout << sz(edgSCC) << endl; 


}
