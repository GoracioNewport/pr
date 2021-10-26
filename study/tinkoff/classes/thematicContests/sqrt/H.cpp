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

void dfs(ll v, p64 parent) { // < color, <> >
  used[v] = true;
  for (auto &u : p[v]) {
    if (!used[u.fi]) {
      path.pb({u.se, {v, u.fi}});
      dfs(u.fi, {u.se, v});
    }
  } path.pb({parent.fi, {v, parent.se}});
}

struct block {
  ll len, sum;
};

struct sqrtD {
  ll l, r, len, n; // [l, r]
  vector <bool> a;
  vector <block> t;

  sqrtD(ll _n) {
    n = _n;
    len = sqrt(n);
    t.resize(n / len + 1, {0, 0});
    forn(i,n) t[i / len].len++;
    a.resize(n, 0);
    l = 0;
    r = -1;
  }

  void toggleX(ll i, ll x) {
    t[i / len].sum -= a[i];
    a[i] = !a[i];
    t[i / len].sum += a[i];
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

bool comp(p64 a, p64 b) {
  return make_pair(a.fi / LEN, a.se) < make_pair(b.fi / LEN, b.se);
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

  for (auto& i : path) cout << i.fi << ' ';
  cout << ln;
  for (auto& i : path) cout << i.se.fi + 1 << ' ';
  cout << ln;
//  for (auto& i : path) cout << i.se.se + 1 << ' ';
//  cout << ln;

  v64 d(n, INF);
  forn(i,sz(path)) d[path[i].se.fi] = min(d[path[i].se.fi], i);

//  for (auto& i : d) cout << i << ' ';
//  cout << ln;

  vp64 Q;
  LEN = sqrt(n + 1);
  sqrtD sd(n + 1);
  while(q--) {
    ll u, v;
    cin >> u >> v; u--; v--;
    if (d[u] <= d[v] - 1) Q.pb({d[u], d[v] - 1});
    else Q.pb({d[v], d[u] - 1});
  } sort(all(Q), comp);



  for (auto& i : Q) cout << i.fi << ' ' << i.se << ln;

  // HANDLE EQUAL!!!

  for (auto& i : Q) {

    if (i.fi > i.se) {
      cout << 0 << ln;
      continue;
    }


    while(sd.r < i.se) {
      sd.r++;
      if (path[sd.r].fi <= n) sd.toggleX(path[sd.r].fi);
    } while (sd.l > i.fi) {
      sd.l--;
      if (path[sd.l].fi <= n) sd.toggleX(path[sd.l].fi);
    } while(sd.r > i.se) {
      if (path[sd.r].fi <= n) sd.toggleX(path[sd.r].fi);
      sd.r--;
    } while(sd.l < i.fi) {
      if (path[sd.l].fi <= n) sd.toggleX(path[sd.l].fi);
      sd.l++;
    } cout << sd.getFirst() << ln;
  }


}