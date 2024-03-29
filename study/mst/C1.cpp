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

v64 p, r;
ll n;

void init() {
  p.resize(n);
  r.resize(n, 0);
  forn(i, n) p[i] = i;
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
  vector <pair <double , pair <ll, ll>>> edg;
  vp64 ps(n);
  init();
  for(auto &i : ps) cin >> i.fi >> i.se;
  forn(i, n) {
    forsn(j, i + 1, n) {
      double x = (abs(ps[i].fi - ps[j].fi));
      double y = (abs(ps[i].se - ps[j].se));
      double len = sqrt(x * x + y * y);
      edg.pb({len, {i, j}});
    }
  } sort(all(edg));

  double ans = 0;

  for (auto &i : edg) {
    // cout << i.fi << ' ' << i.se.fi << ' ' << i.se.se << endl;
    if (findP(i.se.fi) != findP(i.se.se)) {
      ans += i.fi;
      unionSet(i.se.fi, i.se.se);
    }
  } cout << setprecision(10) << fixed << ans << endl;

}
