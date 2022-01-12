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
    v64 a, t;
    ll n;
    Tree (v64 &_a) {
      a = _a;
      n = sz(a);
      t.assign(4 * n, 0);
//      build(0,0,n);
    }

    void build(ll v, ll l, ll r) {
      if (l + 1 == r) {
        t[v] = a[l];
        return;
      } ll m = (l + r) / 2;
      build(2 * v + 1, l, m);
      build(2 * v + 2, m, r);
      t[v] = t[2 * v + 1] + t[2 * v + 2];
    }

    void add(ll v, ll l, ll r, ll L, ll R, ll x) {
      if (l >= R || r <= L) return;
      if (l >= L && r <= R) {
        t[v] += x;
        return;
      } ll m = (l + r) / 2;
      add(2 * v + 1, l, m, L, R, x);
      add(2 * v + 2, m, r, L, R, x);
//      t[v] = t[2 * v + 1] + t[2 * v + 2];
    }

    ll getX(ll v, ll l, ll r, ll i) {
      if (l + 1 == r) return t[v];
      ll m = (l + r) / 2;
      if (i < m) return getX(2 * v + 1, l, m, i) + t[v];
      else return getX(2 * v + 2, m, r, i) + t[v];
    }
};

int main() {
  fast_cin();

  ll n, m;
  cin >> n >> m;
  v64 a(n);
//  for (auto &i : a) cin >> i;
  Tree tree(a);
  while(m--) {
    ll t;
    cin >> t;
    if (t == 1) {
      ll l, r, x;
      cin >> l >> r >> x;
      tree.add(0,0,n,l,r,x);
    } else {
      ll i;
      cin >> i;
      cout << tree.getX(0,0,n,i) << ln;
    }
  }

}