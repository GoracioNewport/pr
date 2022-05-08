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

struct Tree {
  vv64 t;
  v64 a;
  ll n;

  Tree(v64& _a) {
    a = _a;
    n = sz(a);
    t.assign(4 * n, v64 ());
    build(0, 0, n);
  }

  void build(ll v, ll l, ll r) {
    if (l + 1 == r) {
      t[v] = {a[l]};
      return;
    } ll m = (l + r) / 2;
    build(2 * v + 1, l, m);
    build(2 * v + 2, m, r);

    ll j = 0;
    for(ll i = 0; i < sz(t[2 * v + 1]); i++) {
      while(j < sz(t[2 * v + 2]) && t[2 * v + 2][j] < t[2 * v + 1][i]) t[v].pb(t[2 * v + 2][j++]);
      t[v].pb(t[2 * v + 1][i]);
    } for (ll i = j; i < sz(t[2 * v + 2]); i++) t[v].pb(t[2 * v + 2][i]);
  }

  ll getSum(ll v, ll l, ll r, ll L, ll R, ll x, ll y) {
    if (l >= L && r <= R) return upper_bound(all(t[v]), y) - lower_bound(all(t[v]), x);
    if (l >= R || r <= L) return 0;
    ll m = (l + r) / 2;
    return getSum(2 * v + 1, l, m, L, R, x, y) + getSum(2 * v + 2, m, r, L, R, x, y);
  }

};

int main() {
  fast_cin();

  ll n, m;
  cin >> n >> m;
  v64 a(n);
  for (auto& i : a) cin >> i;
  Tree tree(a);
  while(m--) {
    ll l, r, x, y;
    cin >> l >> r >> x >> y;
    cout << tree.getSum(0, 0, n, l - 1, r, x, y) << ln;
  }
}