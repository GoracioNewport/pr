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

vvp64 p;
v64 used;
vector <pair <ll, p64>> path;

ll cnt = 0;

void dfs(ll v, p64 parent) { // < color, cnt >
  used[v] = true;
  for (auto &u : p[v]) {
    if (!used[u.fi]) {
      path.pb({u.se, {v, cnt}});
      dfs(u.fi, {u.se, cnt++});
    }
  } path.pb({parent.fi, {v, parent.se}});
}

struct block {
  ll len, sum;
};

struct sqrtD {
  ll l, r, len, n; // [l, r]
  vector <bool> a, b;
  v64 cnt;
  vector <block> t;

  sqrtD(ll _n) {
    n = _n;
    len = sqrt(n);
    t.resize(n / len + 1, {0, 0});
    forn(i,n) t[i / len].len++;
    a.resize(n, 0);
    b.resize(n, 0);
    cnt.resize(n, 0);
    l = 0;
    r = -1;
  }

  void toggleX(ll i, ll x) { // color, id

    if (b[x]) {
      cnt[i]--;
      if (cnt[i] == 0) {
        t[i / len].sum--;
        a[i] = 0;
      }
    } else {
      cnt[i]++;
      if (cnt[i] == 1) {
        t[i / len].sum++;
        a[i] = 1;
      }
    } b[x] = !b[x];

  }

  ll getFirst() {
    for (ll i = 0; i < n;) {
      if (t[i / len].sum == t[i / len].len) i += len;
      else {
        if (a[i] == 0) return i;
        i++;
      }
    } return n;
  }
};

ll LEN;

bool comp(pair <p64, ll> a, pair <p64, ll> b) {
  return make_pair(a.fi.fi / LEN, a.fi.se) < make_pair(b.fi.fi / LEN, b.fi.se);
}


int main() {
  fast_cin();

  ll n, q;
  cin >> n >> q;
  p.resize(n, vp64());
  used.resize(n);
  forn(i,n - 1) {
    ll x, y, v;
    cin >> x >> y >> v; x--; y--;
    p[x].pb({y,v});
    p[y].pb({x,v});
  } dfs(0, {-1, -1});
  path.pop_back();

//  for (auto& i : path) cout << i.fi << ' ';
//  cout << ln;
//  for (auto& i : path) cout << i.se.fi + 1 << ' ';
//  cout << ln;
//  for (auto& i : path) cout << i.se.se + 1 << ' ';
//  cout << ln;


  v64 d(n, INF);
  forn(i,sz(path)) d[path[i].se.fi] = min(d[path[i].se.fi], i);

//  for (auto& i : d) cout << i << ' ';
//  cout << ln;

  vector <pair <p64, ll>> Q; // cords, ind
  ll MAXN = n + 10;
  LEN = sqrt(n + 1);
  sqrtD sd(MAXN);
  v64 ans(q);
  forn(i,q) {
    ll u, v;
    cin >> u >> v; u--; v--;
    if (d[u] <= d[v] - 1) Q.pb({{d[u], d[v] - 1}, i});
    else Q.pb({{d[v], d[u] - 1}, i});
  } sort(all(Q), comp);



//  for (auto& i : Q) cout << i.fi << ' ' << i.se << ln;

  // HANDLE EQUAL!!!


  for (auto& i : Q) {

    if (i.fi.fi > i.fi.se) {
      ans[i.se] = 0;
      continue;
    }


    while(sd.r < i.fi.se) {
      sd.r++;
      if (path[sd.r].fi < MAXN) sd.toggleX(path[sd.r].fi, path[sd.r].se.se);
    } while (sd.l > i.fi.fi) {
      sd.l--;
      if (path[sd.l].fi < MAXN) sd.toggleX(path[sd.l].fi, path[sd.l].se.se);
    } while(sd.r > i.fi.se) {
      if (path[sd.r].fi < MAXN) sd.toggleX(path[sd.r].fi, path[sd.r].se.se);
      sd.r--;
    } while(sd.l < i.fi.fi) {
      if (path[sd.l].fi < MAXN) sd.toggleX(path[sd.l].fi, path[sd.l].se.se);
      sd.l++;
    } ans[i.se] = sd.getFirst();
  } for (auto& i : ans) cout << i << ln;


}