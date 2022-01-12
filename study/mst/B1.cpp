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

vv64 p;
v64 pr, r;
ll n;

void init() {
  pr.resize(n, 0);
  r.resize(n, 0);
  forn(i, n) pr[i] = i;
}

ll findP(ll v) {
  return (pr[v] == v) ? v : pr[v] = findP(pr[v]);
}

void unionSet(ll a, ll b) {
  a = findP(a);
  b = findP(b);
  if (a == b) return;
  if (r[a] > r[b]) swap(a, b);
  if (r[a] == r[b]) r[b]++;
  pr[a] = b;
}


int main() {
  fast_cin();
  cin >> n;
  p.resize(n + 1, v64 (n + 1, 0));
  forn(i, n) forn(j, n) cin >> p[i][j];
  forn(i, n) {
    ll a;
    cin >> a;
    p[n][i] = a;
    p[i][n] = a;
  } vector <pair <ll, pair <ll,ll>>> edg;
  n++;
  init();
  forn(i, n) forsn(j, i + 1, n) edg.pb({p[i][j], {i, j}});
  sort(all(edg));
  ll ans = 0;
  for(auto &i : edg) {
    if (findP(i.se.fi) != findP(i.se.se)) {
      unionSet(i.se.fi, i.se.se);
      ans += i.fi;
    }
  } cout << ans << endl;
  

}
