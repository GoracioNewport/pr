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
v64 topSorted;
v64 used;
v64 points;


void dfs (ll v) {
  used[v] = true;
  for (auto &u : p[v]) if (!used[u]) dfs(u);
  topSorted.pb(v);
}

void topSort() {
  topSorted.clear();
  forn(i, n * 2) used[i] = 0;
  forn(i, n * 2) if (!used[i]) dfs(i);
  reverse(topSorted.begin(), topSorted.end());
}

void dfsSCC (ll v) {
  // cout << "AAAA\n";
  used[v] = true;
  points.pb(v);
  for (auto &u : pr[v]) if (!used[u]) dfsSCC(u);
}

ll getV (ll v, ll neg) {
  return ((v * 2) + 1 - neg);
}

int main() {
  fast_cin();

  while (cin >> n >> m) {
    p.clear();
    topSorted.clear();
    used.clear();
    points.clear();
    p.clear();
    pr.clear();
    p.resize(n * 2, v64 (0));
    pr.resize(n * 2, v64 (0));
    used.resize(n * 2, 0);
    vp64 edg;
    vp64 edgr;
    
    forn(i, m) {
      ll i1, e1, i2, e2;
      cin >> i1 >> e1 >> i2 >> e2; // i1 - первая переменная, e1 - ее отрицание, i2 - вторая переменная, e2 - ее отрицание

      // a || b  === (!a -> b) && (!b -> a)
      // e -> 0 - отрицаиние, 1 - нет отрицания
      // (!i1 -> i2)
      // (!i2 -> i1)
      ll x = getV(i1, e1);
      ll y = getV(i2, e2);
      
      ll nx = x;
      ll ny = y;
      if (x % 2 == 0) nx++;
      else nx--;
      if (y % 2 == 0) ny++;
      else ny--;


      if (nx != y) edg.pb({nx, y});
      if (ny != x) edg.pb({ny, x});
      if (x != ny) edgr.pb({x, ny});
      if (y != nx) edgr.pb({y, nx});
    } sort(all(edg));
    sort(all(edgr));
    auto last = unique(edg.begin(), edg.end());
    edg.resize(last - edg.begin());
    last = unique(edgr.begin(), edgr.end());
    edgr.resize(last - edgr.begin());
    for(auto &i : edg) p[i.fi].pb(i.se);
    for(auto &i : edgr) pr[i.fi].pb(i.se);
    
    topSort();
    v64 ans (n * 2, 0);

    // for (auto &i : topSorted) cout << i << ' ';
    // cout << endl;

    forn(i, sz(used)) used[i] = 0;

    ll ind = 0;
    for (auto &i : topSorted) {
      if (!used[i]) {
        dfsSCC(i);
        for (auto &j : points) ans[j] = ind;
        points.clear();
        ind++;
      }
    } 
    
    // for (auto &i : ans) cout << i << ' ';
    // cout << endl;
    
    for (ll i = 0; i < 2 * n; i += 2) {
      cout << (ans[i] > ans[i^1]);
    } cout << endl;
  }

}
