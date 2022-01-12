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

vector <pair <ll, pair <ll,ll>>> edg;
vvp64 pr;
ll n, m, k;
v64 p, r;
v64 used;
ll ans = -1;


void init() {
  p.resize(n, 0);
  r.resize(n, 0);
  forn(i,n) p[i] = i;
}

ll findP(ll v) {
  return (p[v] == v) ? v : p[v] = findP(p[v]);
}

void unionSet(ll a, ll b) {
  // cout << "HI" << endl;
  a = findP(a);
  b = findP(b);
  if (a == b) return;
  if (r[a] > r[b]) swap(a,b);
  if (r[a] == r[b]) r[b]++;
  p[a] = b;
}

void dfs(ll v, ll m, ll f) {
  if (v == f) ans = m;
  used[v] = true;
  for(auto &i : pr[v]) {
    ll u = i.fi;
    ll w = i.se;
    if (!used[u]) dfs(u, min(m, w), f);
  }
}

int main() {
  fast_cin();
  
  cin >> n >> m >> k;
  forn(i,m) {
    ll x, y, w;
    cin >> x >> y >> w;
    x--;
    y--;
    edg.pb({w, {x, y}});
  } sort(edg.begin(), edg.end(), [](auto a, auto b) { return a.fi > b.fi; }); 
  pr.resize(n, vp64(0));
  // cout << "OK" << endl;
  init();
  for(auto &i : edg) {
    if (findP(i.se.fi) != findP(i.se.se)) {
      unionSet(i.se.fi, i.se.se);
      pr[i.se.fi].pb({i.se.se, i.fi});
      pr[i.se.se].pb({i.se.fi, i.fi});
    }
  } used.resize(n, 0);
  forn(z,k) {
    ll x, y;
    cin >> x >> y;
    x--;
    y--;
    forn(i,n) used[i] = 0;
    ans = -1;
    dfs(x, INF, y);
    cout << ans << ln;
  }

}
