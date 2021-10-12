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

v64 p, r;

void init(ll n) {
  p.resize(n);
  r.resize(n);
  forn(i,n) p[i] = i;
}

ll findP(ll v) {
  return (p[v] == v ? v : p[v] = findP(p[v]));
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

  ll n;
  cin >> n;
  vp64 x, y, a(n);
  ll ind = 0;
  for (auto &i : a) {
    cin >> i.fi >> i.se;
    x.pb({i.fi, ind});
    y.pb({i.se, ind++});
  } sort(all(x));
  sort(all(y));

  vector <pair <ll, p64>> e;
  forn(i,n - 1) {
    e.pb({x[i + 1].fi - x[i].fi, {x[i].se, x[i + 1].se}});
    e.pb({y[i + 1].fi - y[i].fi, {y[i].se, y[i + 1].se}});
  } sort(all(e));
  init(n);

  ll ans = 0;
  for (auto &i : e) {
    if (findP(i.se.fi) != findP(i.se.se)) {
      unionSet(i.se.fi, i.se.se);
      ans += i.fi;
    }
  } cout << ans << ln;

}