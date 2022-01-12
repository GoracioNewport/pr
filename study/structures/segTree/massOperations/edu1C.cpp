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
  v64 a,t;
  ll n;
  Tree (ll n) {
    a.resize(n, 0);
    t.assign(4 * n, 0);
  }

  ll apply(ll a, ll b) {
    return (b == INF ? a : b);
  }

  void push(ll v, ll l, ll r) {
    if (l + 1 == r) return;
    t[2 * v + 1] = apply(t[2 * v + 1], t[v]);
    t[2 * v + 2] = apply(t[2 * v + 2], t[v]);
    t[v] = INF;
  }

  void assign(ll v, ll l, ll r, ll L, ll R, ll x) {
    push(v,l,r);
    if (l >= R || r <= L) return;
    if (l >= L && r <= R) {
      t[v] = x;
      return;
    } ll m = (l + r) / 2;
    assign(2 * v + 1, l, m, L, R, x);
    assign(2 * v + 2, m, r, L, R, x);
  }

  ll getX(ll v, ll l, ll r, ll i) {
    push(v,l,r);
    if (l + 1 == r) return (t[v] == INF ? 0 : t[v]);
    ll m = (l + r) / 2;
    if (i < m) return getX(2 * v + 1, l, m, i);
    else return getX(2 * v + 2, m, r, i);
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
      ll l, r, x;
      cin >> l >> r >> x;
      tree.assign(0,0,n,l,r,x);
    } else {
      ll i;
      cin >> i;
      cout << tree.getX(0,0,n,i) << ln;
    }

  }


}