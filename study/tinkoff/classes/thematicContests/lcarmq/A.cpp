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

vv64 p, up; // up[v][i] = предок для вершины v на расстоянии (1 << i);
v64 used, add, he;
vp64 path;
v64 leadPower;
ll globCnt = 0, ans = 0, maxL, MAXL = 20;


struct sparceTableMin {
  vvp64 t;
  ll n;

  sparceTableMin(vp64& a) {
    n = sz(a);

    leadPower.assign(n + 1, 0);
    forsn(i,2,n + 1) leadPower[i] = leadPower[i / 2] + 1;
    maxL = leadPower.back() + 1;

    t.assign(n, vp64 (maxL + 1, {INF, 0}));
    forn(i,n) t[i][0] = a[i];
    for (ll len = 1; len <= maxL  ; len++) {
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

void dfs(ll v, ll h, ll par) {
  path.pb({h, v});
  used[v] = 1;
  he[v] = h;
  up[v][0] = par;

  for (ll l = 1; l <= MAXL; l++) up[v][l] = up[up[v][l - 1]][l - 1];

  for (auto& u : p[v]) {
    if (!used[u]) {
      dfs(u, h + 1, v);
      path.pb({h, v});
    }
  }
}

void dfsAns(ll v, ll c) {
  used[v] = true;
  c += add[v];
  ll child = 0;
  for (auto& u : p[v]) {
    if (!used[u]) {
      dfsAns(u, c);
      child++;
    }
  } ans = max(ans, c);
}

ll getVByDist(ll v, ll len) {
//  cout << len << ln;
  for (ll l = MAXL; l >= 0; l--) {
    if (len >= (1 << l)) {
      len -= (1 << l);
      v = up[v][l];
    }
  } return v;
}

int main() {
  fast_cin();

  ll n;
  cin >> n;
  p.resize(n, v64());
  used.resize(n);
  he.resize(n, 0);


  up.assign(n, v64(MAXL + 1, 0));

  forn(i,n-1) {
    ll x, y;
    cin >> x >> y; x--; y--;
    p[x].pb(y);
    p[y].pb(x);
  } dfs(0, 0, 0);
//  for (auto& i : path) cout << i.se + 1 << ' ' << i.fi << ln;


  v64 m(n, -1);
  forn(i,sz(path)) if (m[path[i].se] == -1) m[path[i].se] = i;

  sparceTableMin t(path);

//  for (auto& i : m) cout << i << ' ';
//  cout << ln;


  ll q;
  cin >> q;

  add.resize(n, 0);

  while(q--) {
    ll a, b;
    cin >> a >> b; a--; b--;
    ll i = m[a];
    ll j = m[b];
    if (j < i) swap(i, j);
    ll lca = t.getMin(i, j).se;

    if (lca == a) {
      globCnt++;
      add[b]++;
      ll c = getVByDist(b, he[b] - he[a] - 1);
      add[c]--;

//      cout << "LCA A" << ln << c + 1 << ln;

    } else if (lca == b) {
      globCnt++;
      add[a]++;
      ll c = getVByDist(a, he[a] - he[b] - 1);
      add[c]--;

//      cout << "LCA B" << ln << c + 1 << ln;

    } else {
      add[a]++;
      add[b]++;
    }
  } forn(i,n) used[i] = 0;
  dfsAns(0, 0);
  cout << ans + globCnt << ln;

}