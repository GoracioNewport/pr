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

struct node {
    ll min;
    ll max;
    ll len;
};

struct Tree {
    vector <node> t;
    ll n;

    const ll NEUTRAL_ELEMENT = INF;

    Tree (ll _n) {
      n = _n;
      t.assign(4 * n, {NEUTRAL_ELEMENT,NEUTRAL_ELEMENT,0});
      build(0,0,n);
    }

    void build(ll v, ll l, ll r) {
      t[v].len = r - l;
      if (l + 1 == r) return;
      ll m = (l + r) / 2;
      build(2 * v + 1, l, m);
      build(2 * v + 2, m, r);
    }

    void buildHome(ll v, ll l, ll r, ll i, ll x) {
//      cout << v << ' ' << l << ' ' << r << ln;
      if (l + 1 == r) {
        t[v].min = t[v].max = x;
        return;
      } ll m = (l + r) / 2;
      if (i < m) buildHome(2 * v + 1, l, m, i, x);
      else buildHome(2 * v + 2, m, r, i, x);
      t[v].min = min(t[2 * v + 1].min, t[2 * v + 2].min);
      t[v].max = max(t[2 * v + 1].max, t[2 * v + 2].max);
    }

    ll earthquake(ll v, ll l, ll r, ll L, ll R, ll x) {
      if (l >= R || r <= L || t[v].min > x) return 0;
      if (l >= L && r <= R) {
        if (t[v].max <= x) {
          t[v].min = NEUTRAL_ELEMENT;
          t[v].max = NEUTRAL_ELEMENT;
          return t[v].len;
        } else if (l + 1 == r) return 0;
      } ll m = (l + r) / 2;
      ll e1 = earthquake(2 * v + 1, l, m, L, R, x);
      ll e2 = earthquake(2 * v + 2, m, r, L, R, x);
      t[v].min = min(t[2 * v + 1].min, t[2 * v + 2].min);
      t[v].max = max(t[2 * v + 1].max, t[2 * v + 2].max);
      return e1 + e2;
    }
};

int main() {
  fast_cin();

  ll n, m;
  cin >> n >> m;
  Tree tree(n);
  while(m--) {
    ll t;
    cin >> t;
    if (t == 1) {
      ll i, h;
      cin >> i >> h;
      tree.buildHome(0,0,n,i,h);
    } else {
      ll l, r, p;
      cin >> l >> r >> p;
      cout << tree.earthquake(0,0,n,l,r,p) << ln;
    }
  }

}