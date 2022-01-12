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

vvp64 p;
v64 used, ind, ans;
vp64 path;
vector <vector <pair <ll, p64>>> mul; // <x, <id, mul>>

ll maxN = 1e6 + 1;

struct sparceTableMin {
  vvp64 t;
  v64 leadPower;
  vp64 a;
  ll n, maxL;

  sparceTableMin(vp64& _a) {
    a = _a;
    n = sz(a);

    leadPower.resize(n + 1, 0);
    forsn(i,2,n + 1) leadPower[i] = leadPower[i / 2] + 1;
    maxL = leadPower.back() + 1;

    t.resize(n, vp64 (maxL + 1, {INF, INF}));
    forn(i,n) t[i][0] = a[i];

    for (ll len = 1; len <= maxL; len++) {
      for (ll i = 0; i < n - (1 << len) + 1; i++) {
        t[i][len] = min(t[i][len - 1], t[i + (1 << (len - 1))][len - 1]);
      }
    }
  }

  p64 getMin(ll l, ll r) {
    ll len = leadPower[r - l + 1];
    return min(t[l][len], t[r - (1 << len) + 1][len]);
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

void dfs(ll v, ll h) {
  used[v] = true;
  path.pb({h, v});
  for (auto& u : p[v]) {
    if (!used[u.fi]) {
      dfs(u.fi, h + 1);
      path.pb({h, v});
    }
  }
}

void dfsAns(ll v, Tree& t) {
  used[v] = true;
  for (auto& c : mul[v]) ans[c.se.fi] += (t.getSum(0, 0, maxN, 0, c.fi + 1)) * c.se.se;
  for (auto& u : p[v]) {
    if (!used[u.fi]) {
      t.addX(0, 0, maxN, u.se, 1);
      dfsAns(u.fi, t);
      t.addX(0, 0, maxN, u.se, -1);
    }
  }
}

void init(ll n) {
  ind.resize(n, -1);
  forn(i,sz(path)) if (ind[path[i].se] == -1) ind[path[i].se] = i;
}

ll lca(ll a, ll b, sparceTableMin& t) {
  ll i = ind[a];
  ll j = ind[b];
  if (i > j) swap(i, j);
  return t.getMin(i, j).se;
}

int main() {
  fast_cin();

  ll n, q;
  cin >> n >> q;
  p.resize(n, vp64());
  used.resize(n);
  mul.resize(n, vector <pair <ll, p64>> ());
  ans.resize(q);
  forn(i,n - 1) {
    ll x, y, c;
    cin >> x >> y >> c; x--; y--;
    p[x].pb({y, c});
    p[y].pb({x, c});
  } dfs(0, 0);
  sparceTableMin t(path);
  init(n);

  forn(i,q) {
    ll a, b, x;
    cin >> a >> b >> x; a--; b--;
    ll l = lca(a, b, t);
    mul[a].pb({x, {i, 1}});
    mul[b].pb({x, {i, 1}});
    mul[l].pb({x, {i, -2}});
  } Tree tr(maxN);
  forn(i,n) used[i] = 0;
  dfsAns(0, tr);

  for (auto& i : ans) cout << i << ln;

}