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
  
ll n;
v64 p, r;
void init() {
  p.resize(n + 1, 0);
  r.resize(n + 1, 0);
  forn(i, n + 1) p[i] = i;
}

ll findP(ll v) {
  return (p[v] == v) ? v : p[v] = findP(p[v]);
}

void unionSet(ll a, ll b) {
  a = findP(a);
  b = findP(b);
  if (a == b) return;
  if (r[a] > r[b]) swap(a, b);
  if (r[a] == r[b]) r[b]++;
  p[a] = b;
}

int main() {
  fast_cin();

  cin >> n;
  vp64 pz(n);
  v64 ks(n);  
  v64 cs(n);
  for(auto &i : pz) cin >> --i.fi >> --i.se;
  for(auto &i : cs) cin >> --i;
  for(auto &i : ks) cin >> --i;
  vector <pair <ll, pair <ll,ll>>> edg;
  forn(i,n) forsn(j, i + 1, n) edg.pb({((abs(pz[i].fi - pz[j].fi) + abs(pz[i].se - pz[j].se)) * (ks[i] + ks[j])), {i, j}});
  forn(i,n) edg.pb({cs[i], {i, n}});
  init();
  sort(all(edg));
  ll ans = 0;
  v64 ansEl;
  vp64 ansRo;
  for(auto &i : edg) {
    if (findP(i.se.fi) != findP(i.se.se)) {
      unionSet(i.se.fi, i.se.se);
      ans += i.fi;
      if (max(i.se.fi, i.se.se) == n) ansEl.pb(min(i.se.fi, i.se.se));
      else ansRo.pb({i.se.fi, i.se.se});
    }
  } cout << ans << ln;
  // cout << "OK" << endl;
  cout << sz(ansEl) << ln;
  for (auto &i : ansEl) cout << i + 1 << ' ';
  cout << endl;
  cout << sz(ansRo) << ln;
  for (auto &i : ansRo) cout << i.fi + 1 << ' ' << i.se + 1 << ln;
  cout << endl;
}
