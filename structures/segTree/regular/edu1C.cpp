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

struct Tree {
    v64 a;
    vp64 t;
    ll n;

    Tree (v64 &_a) {
      a = _a;
      n = sz(a);
      t.assign(4 * n, {0,0});
      build(0,0,n);
    }

    void build(ll v, ll l, ll r) {
      if (l + 1 == r) {
        t[v] = {a[l], 1};
        return;
      } ll m = (l + r) / 2;
      build(2 * v + 1, l, m);
      build(2 * v + 2, m, r);
      t[v] = {min(t[2 * v + 1].fi, t[2 * v + 2].fi), 0};
      if (t[2 * v + 1].fi == t[v].fi) t[v].se += t[2 * v + 1].se;
      if (t[2 * v + 2].fi == t[v].fi) t[v].se += t[2 * v + 2].se;
    }

    void updateSingle(ll v, ll l, ll r, ll i, ll x) {
      if (l + 1 == r) {
        t[v] = {x, 1};
        a[i] = x;
        return;
      } ll m = (l + r) / 2;
      if (i < m) updateSingle(2 * v + 1, l, m, i, x);
      else updateSingle(2 * v + 2, m, r, i, x);
      t[v] = {min(t[2 * v + 1].fi, t[2 * v + 2].fi), 0};
      if (t[2 * v + 1].fi == t[v].fi) t[v].se += t[2 * v + 1].se;
      if (t[2 * v + 2].fi == t[v].fi) t[v].se += t[2 * v + 2].se;
    }

    p64 getMin(ll v, ll l, ll r, ll L, ll R) {
      if (l >= R || r <= L) return {INF, 0};
      if (l >= L && r <= R) return t[v];
      ll m = (l + r) / 2;
      p64 left = getMin(2 * v + 1, l, m, L, R);
      p64 right = getMin(2 * v + 2, m, r, L, R);
      p64 ans = {min(left.fi, right.fi), 0};
      if (left.fi == ans.fi) ans.se += left.se;
      if (right.fi == ans.fi) ans.se += right.se;
      return ans;
    }
};

int main() {
  fast_cin();

  ll n, m;
  cin >> n >> m;
  v64 a(n);
  for (auto &i : a) cin >> i;
  Tree tree(a);
  while(m--) {
    ll t, l, r;
    cin >> t >> l >> r;
    if (t == 1) tree.updateSingle(0,0,n,l,r);
    else {
      p64 ans = tree.getMin(0,0,n,l,r);
      cout << ans.fi << ' ' << ans.se << ln;
    }
  }
}