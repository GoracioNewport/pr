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
  v64 t;
  ll n;
  Tree (ll _n) {
    n = _n;
    t.assign(4 * n, 0);
  }

  void setX(ll v, ll l, ll r, ll i, ll x) {
    if (l + 1 == r) {
      t[v] += x;
      return;
    } ll m = (l + r) / 2;
    if (i < m) setX(2 * v + 1, l, m, i, x);
    else setX(2 * v + 2, m, r, i, x);
    t[v] = t[2 * v + 1] + t[2 * v + 2];
  }

  ll getSum(ll v, ll l, ll r, ll L, ll R) {
    if (l >= L && r <= R) return t[v];
    if (l >= R || r <= L) return 0;
    ll m = (l + r) / 2;
    return getSum(2 * v + 1, l, m, L, R) + getSum(2 * v + 2, m, r, L, R);
  }
};

int main() {
  fast_cin();

  ll n, m, q;
  cin >> n >> m >> q;
  Tree tree(m);
  while(q--) {
    ll t;
    cin >> t;
    if (t == 0) {
      ll a, b, x;
      cin >> a >> b >> x;
      tree.setX(0,0,m, x - 1,1);
    } else {
      ll r, x;
      cin >> r >> x;
      ll s = tree.getSum(0,0,m,0, x);
//      cout << x << ' ' << s << ln;
      if (r == 1) cout << (s % 2 ? 2 : 1) << ln;
      else cout << (s % 2 ? 1 : 2) << ln;

    }
  }

}