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

vv64 p, P;
vvp64 mul;
v64 used, Used, closest, powers;
vp64 path;

struct sparceTableMin {
  vvp64 t;
  v64 leadPower;
  ll n, maxL;
  sparceTableMin() {};
  sparceTableMin(vp64& a) {
    n = sz(a);
    leadPower.assign(n + 1,0);
    forsn(i,2,n + 1) leadPower[i] = leadPower[i / 2] + 1;
    maxL = leadPower.back() + 1;

    t.assign(n, vp64 (maxL + 1, {INF, INF}));
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

sparceTableMin t;

p64 lca(ll a, ll b) {
  a = closest[a];
  b = closest[b];
  if (a > b) swap(a, b);
  return t.getMin(a, b);
}

void dfsInit(ll v, ll h = 0) {
  used[v] = true;
  path.pb({h, v});
  for (auto& u : p[v]) {
    if (!used[u]) {
      dfsInit(u, h + 1);
      path.pb({h, v});
    }
  }
}

ll Ans = true;

void dfsIn(ll v, ll c) {
  Used[v] = c;
  for (auto& u : P[v]) {
    if (Used[u] == 0) dfsIn(u, c ^ 1);
    else if (Used[u] == c) Ans = false;
  }
}

ll mod = 1e9 + 7;

ll dfsAns(ll v, set <p64>& q, ll h = 0) {
  used[v] = true;

  ll locAns = 1;

  unordered_map <ll, ll> m;
  vp64 pairs;

  bool hasVertWay = false;

  for (auto& u : p[v]) {
    if (used[u]) continue;
    ll x = dfsAns(u, q, h + 1);
    locAns = (locAns * x) % mod;
    bool goUp = false;
    for (auto& i : q) {
      ll hx = -i.fi;
      if (hx < h) {
        goUp = true;
        break;
      } if (m[i.se] == 0) m[i.se] = u + 1;
      else pairs.pb({min(u + 1, m[i.se]), max({u + 1, m[i.se]})});
    } auto it = q.lower_bound({-h, INF});
    if (it != q.begin()) q.erase(q.begin(), it);
    if (goUp) pairs.pb({u + 1, INF});
    if (goUp) hasVertWay = true;
  } v64 vs;
  for (auto& i : pairs) {
    vs.pb(i.fi);
    vs.pb(i.se);
  } sort(all(vs));
  vs.erase(unique(all(vs)), vs.end());

  unordered_map <ll, ll> z;
  forn(i,sz(vs)) z[vs[i]] = i;
  P.clear();
  Used.clear();
  ll n = sz(vs);
  P.resize(n, v64());
  Used.resize(n, 0);
  ll cnt = 0;

  for (auto& i : pairs) {
    P[z[i.fi]].pb(z[i.se]);
    P[z[i.se]].pb(z[i.fi]);
  }

  for (auto& i : mul[v]) {
    p64 l = lca(v, i.fi);
    q.insert({l.fi, i.se});
  }

  Ans = true;
  forn(i,n) {
    if (Used[i] == 0) {
      dfsIn(i, (i + 1) * 2);
      cnt++;
    }
  } if (!Ans) return 0;

  locAns = locAns * powers[cnt] % mod;
  locAns = locAns * powers[(sz(p[v]) - (v == 0 ? 0 : 1)) - (sz(vs) - hasVertWay)] % mod;
  return locAns;

}

int main() {
  fast_cin();

  ll n, m;
  cin >> n >> m;
  p.assign(n, v64());
  used.assign(n, 0);
  mul.assign(n, vp64());
  powers.resize(4 * 1e5, 1);
  forsn(i,1,sz(powers)) powers[i] = powers[i - 1] * 2 % mod;
  forn(i,n - 1) {
    ll x, y;
    cin >> x >> y; x--; y--;
    p[x].pb(y);
    p[y].pb(x);
  } dfsInit(0);
  t = sparceTableMin(path);
  closest.resize(sz(path), -1);
  forn(i,sz(path)) if (closest[path[i].se] == -1) closest[path[i].se] = i;

  while(m--) {
    ll x, y;
    cin >> x >> y; x--; y--;
    mul[x].pb({y, m});
    mul[y].pb({x, m});
  }

  set <p64> A;
  fill(all(used), 0);
  cout << dfsAns(0, A) << ln;
}