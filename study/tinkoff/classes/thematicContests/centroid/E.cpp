// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
// #pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

// Author: @GoracioNewport

using namespace std;

typedef int ll;
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
#define INF 1e9
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

vv64 p;
vector <unordered_map <ll, ll>> colorDist, vDist;
v64 level, parent, color;

ll dfs(ll v, ll size, ll& center, ll P = -1) {
  ll sum = 1;
  for (auto& u : p[v]) if (level[u] == -1 && u != P) sum += dfs(u, size, center, v);
  if (center == -1 && (sum * 2 >= size || P == -1)) center = v;
  return sum;
}

void dfsColor(ll v, ll d, ll center, ll P = -1) {
  vDist[center][v] = d;
  if (colorDist[center][color[v]] == 0) colorDist[center][color[v]] = d;
  else colorDist[center][color[v]] = min(d, colorDist[center][color[v]]);
  for (auto& u : p[v]) if (level[u] == -1 && u != P) dfsColor(u, d + 1, center, v);
}

void buildCentroid(ll v, ll depth, ll size, ll prev) {
  ll center = -1;
  dfs(v, size, center);
  level[center] = depth;
  parent[center] = prev;
  vDist[center][center] = 0;
  for (auto& u : p[center]) if (level[u] == -1) dfsColor(u, 1, center);
  for (auto& u : p[center]) if (level[u] == -1) buildCentroid(u, depth + 1, size / 2, center);
}

int main() {
  fast_cin();

  ll n;
  cin >> n;
  p.resize(n, v64());
  level.resize(n, -1);
  parent.resize(n);
  color.resize(n);
  colorDist.resize(n);
  vDist.resize(n);

  forn(i,n - 1) {
    ll x; cin >> x;
    p[i + 1].pb(x);
    p[x].pb(i + 1);
  } for (auto& i : color) cin >> i;
  buildCentroid(0, 0, n, -1);

  ll q;
  cin >> q;
  while(q--) {
    ll v, c;
    cin >> v >> c;
    ll ans = INF;

    ll x = v;

    while(x != -1) {
      ll distX = (x == v ? 0 : (vDist[x][v] == 0 ? INF : vDist[x][v]));
      ll distY = (color[x] == c ? 0 : (colorDist[x][c] == 0 ? INF : colorDist[x][c]));
      ans = min(ans, distX + distY);
      x = parent[x];
    } cout << (ans == INF ? -1 : ans) << ' ';
  }

}