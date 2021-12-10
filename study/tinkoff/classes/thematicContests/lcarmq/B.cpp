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

vv64 p1, p2;
v64 used1, used2, path1, path2;

enum { BEGIN, DOT, END };

struct event {
  ll x, y1, y2, type;
  bool operator< (const event& o) const {
    if (x != o.x) return x < o.x;
    else return type < o.type;
  }
};

struct Tree {
  v64 t;
  ll n;
  Tree (ll _n) {
    n = _n;
    t.assign(4 * n, 0);
  }

  void addX(ll v, ll l, ll r, ll i, ll x) {
    if (l + 1 == r) {
      t[v] += x;
      return;
    } ll m = (l + r) / 2;
    if (i < m) addX(2 * v + 1, l, m, i, x);
    else addX(2 * v + 2, m, r, i, x);
    t[v] = t[2 * v + 1] + t[2 * v + 2];
  }

  ll getSum(ll v, ll l, ll r, ll L, ll R) {
    if (l >= L && r <= R) return t[v];
    if (l >= R || r <= L) return 0;
    ll m = (l + r) / 2;
    return getSum(2 * v + 1, l, m, L, R) + getSum(2 * v + 2, m, r, L, R);
  }
};

void dfs(ll v, vv64& p, v64& used, v64& path) {
  used[v] = true;
  path.pb(v);
  for (auto& u : p[v]) if(!used[u]) dfs(u, p, used, path);
  path.pb(v);
}

int main() {
  fast_cin();

  ll n;
  cin >> n;
  used1.resize(n);
  used2.resize(n);
  p1.resize(n, v64());
  p2.resize(n, v64());

  ll root1, root2;

  forn(i,n) {
    ll x;
    cin >> x;
    if (x == 0) {
      root1 = i;
      continue;
    }
    x--;
    p1[i].pb(x);
    p1[x].pb(i);
  }

  forn(i,n) {
    ll x;
    cin >> x;
    if (x == 0) {
      root2 = i;
      continue;
    }
    x--;
    p2[i].pb(x);
    p2[x].pb(i);
  } dfs(root1, p1, used1, path1);
  dfs(root2, p2, used2, path2);

  vp64 c1(n, {-1, -1}), c2(n, {-1, -1});

  forn(i,sz(path1)) {
    if (c1[path1[i]].fi == -1) c1[path1[i]].fi = i;
    else c1[path1[i]].se = i;
  } forn(i,sz(path2)) {
    if (c2[path2[i]].fi == -1) c2[path2[i]].fi = i;
    else c2[path2[i]].se = i;
  }

  vector <pair <p64, p64>> rects;
  vp64 dots;

  vector <event> q;

  forn(i,n) {
    p64 bl = {min(c1[i].fi, c1[i].se), min(c2[i].fi, c2[i].se)};
    p64 tr = {max(c1[i].fi, c1[i].se), max(c2[i].fi, c2[i].se)};
    q.pb({bl.fi, bl.se, tr.se, BEGIN });
    q.pb({tr.fi, bl.se, tr.se, END });
    q.pb({bl.fi, bl.se, bl.se, DOT});
  } sort(all(q));

  ll ans = 0;
  n *= 2;
  Tree tree(n);
  for (auto& i : q) {
    if (i.type == BEGIN) ans -= tree.getSum(0, 0, n, i.y1, i.y2 + 1);
    else if (i.type == END) ans += tree.getSum(0, 0, n, i.y1, i.y2 + 1) - 1;
    else tree.addX(0, 0, n, i.y1, 1);
  } cout << ans << ln;


}