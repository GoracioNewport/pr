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

struct node {
  ll add;
  ll sum;
  ll len;
  ll l;
  ll r;
};

struct Tree {
  vector <node> t;
  ll n;
  Tree (ll n) {
    t.assign(4 * n, {0,0,0});
    build(0,0,n);
  }

  void build(ll v, ll l, ll r) {
    t[v].len = r - l;
    t[v].l = l;
    t[v].r = r - 1;
    if (l + 1 == r) return;
    ll m = (l + r) / 2;
    build(2 * v + 1, l, m);
    build(2 * v + 2, m, r);
  }

  void add(ll v, ll l, ll r, ll L, ll R, ll x) {
    if (l >= R || r <= L) return;
    if (l >= L && r <= R) {
      t[v].add += x;
      t[v].sum += (x * t[v].len);
      return;
    } ll m = (l + r) / 2;
    add(2 * v + 1, l, m, L, R, x);
    add(2 * v + 2, m, r, L, R, x);
    t[v].sum = (t[2 * v + 1].sum + t[2 * v + 2].sum) + (t[v].add * t[v].len);
  }

  ll getSum(ll v, ll l, ll r, ll L, ll R) {
    if (l >= R || r <= L) return 0;
    if (l >= L && r <= R) return t[v].sum;
    ll m = (l + r) / 2;
    return (getSum(2 * v + 1, l, m, L, R) + getSum(2 * v + 2, m, r, L, R)) + (t[v].add * (min(R, r) - max(L,l)));
  }

};

int main() {
  fast_cin();

  ll n, m;
  cin >> n >> m;
  Tree tree(n);
  while(m--) {
    ll t, l, r;
    cin >> t >> l >> r;
    if (t == 1) {
      ll x;
      cin >> x;
      tree.add(0,0,n,l,r,x);
//      for (auto &i : tree.t) cout << i.l << ' ' << i.r << ' ' << i.add << ' ' << i.sum << ln;
    } else cout << tree.getSum(0,0,n,l,r) << ln;
  }

}