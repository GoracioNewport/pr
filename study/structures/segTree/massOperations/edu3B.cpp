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
  ll sum;
  ll len;
  ll l;
  ll r;
  bool inverted;
};

struct Tree {
  vector <node> t;
  ll n;
  Tree (ll _n) {
    n = _n;
    t.assign(4 * n, {0,0, 0,0,false});
    build(0,0,n);
  }

  void build(ll v, ll l, ll r) {
    t[v].len = r - l;
    t[v].l = l;
    t[v].r = r;
    if (l + 1 == r) return;
    ll m = (l + r) / 2;
    build(2 * v + 1, l, m);
    build(2 * v + 2, m, r);
  }

  void push(ll v, ll l, ll r) {
    if (l + 1 == r || !t[v].inverted) return;
    t[2 * v + 1].sum = t[2 * v + 1].len - t[2 * v + 1].sum;
    t[2 * v + 2].sum = t[2 * v + 2].len - t[2 * v + 2].sum;
    t[2 * v + 1].inverted = !t[2 * v + 1].inverted;
    t[2 * v + 2].inverted = !t[2 * v + 2].inverted;
    t[v].inverted = false;
  }

  void invert(ll v, ll l, ll r, ll L, ll R) {
    push(v,l,r);
    if (l >= R || r <= L) return;
    if (l >= L && r <= R) {
      t[v].sum = t[v].len - t[v].sum;
      t[v].inverted = !t[v].inverted;
//      t[2 * v + 1].inverted = !t[2 * v + 1].inverted;
//      t[2 * v + 2].inverted = !t[2 * v + 2].inverted;
      return;
    } ll m = (l + r) / 2;
    invert(2 * v + 1, l, m, L, R);
    invert(2 * v + 2, m, r, L, R);
    t[v].sum = t[2 * v + 1].sum + t[2 * v + 2].sum;
  }

  ll findK(ll v, ll l, ll r, ll x) {
    push(v,l,r);
//    cout << "Enter " << v << ", sum: " << t[v].sum << ", x: " << x << ln;
    if (l + 1 == r) return l;
    ll m = (l + r) / 2;
    if (t[2 * v + 1].sum > x) return findK(2 * v + 1, l, m, x);
    else return findK(2 * v + 2, m, r, x - t[2 * v + 1].sum);
  }


};

int main() {
  fast_cin();

  ll n, m;
  cin >> n >> m;
  Tree tree(n);
  while(m--) {
//    cout << "----" << ln;
    ll t;
    cin >> t;
    if (t == 1) {
      ll l, r;
      cin >> l >> r;
      tree.invert(0,0,n,l,r);
    } else {
      ll k;
      cin >> k;
//      for (auto &i : tree.t) cout << i.l << ' ' << i.r - 1 << ' ' << i.sum << ln;
      cout << tree.findK(0,0,n,k) << ln;
    }
  }


}