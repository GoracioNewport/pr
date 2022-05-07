// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
// #pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

// Author: @GoracioNewport

using namespace std;

typedef int ll;
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

ll N;
ll maxN = 2e6;

struct Node {
  ll sum, l, r;
  Node () {
    l = r = -1;
    sum = 0;
  }
};

struct Tree {
  vector <Node> t;
  ll ind = 1;

  Tree() {
    t.emplace_back(Node());
  }

  void touchChildren(ll v, ll l, ll r) {
    if (l + 1 == r) return;
    if (t[v].l == -1) {
      t.emplace_back(Node());
      t[v].l = ind++;
    } if (t[v].r == -1) {
      t.emplace_back(Node());
      t[v].r = ind++;
    }
  }

  void setX(ll v, ll l, ll r, ll i, ll x) {
    if (l + 1 == r) {
      t[v].sum = x;
      return;
    } ll m = (l + r) / 2;
    touchChildren(v,l,r);
    if (i < m) setX(t[v].l, l, m, i, x);
    else setX(t[v].r, m, r, i, x);
    t[v].sum = t[t[v].l].sum + t[t[v].r].sum;
  }

  ll getSum(ll v, ll l, ll r, ll L, ll R) {
    if (l >= L && r <= R) return t[v].sum;
    if (l >=   R || r <= L) return 0;
    ll m = (l + r) / 2;
    touchChildren(v,l,r);
    return getSum(t[v].l, l, m, L, R) + getSum(t[v].r, m, r, L, R);
  }
};

struct Fenwick {
  vector <Tree> t;
  ll n;

  Fenwick(ll _n) {
    n = _n + 1;
    t.assign(n + 1, Tree());
  }

  void update(ll i, ll x) {
    i++;
    for(; i < n; i += i & -i) t[i].setX(0,0,N,x,1);
  }

  ll getSum(ll r, ll x) {
    r++;
    ll ans = 0;
    for(; r > 0; r -= r & -r) ans += t[r].getSum(0, 0, N, x + 1, N);
    return ans;
  }
};

int main() {
  fast_cin();

  ll n;
  cin >> n;
  vp64 q(n);
  v64 c;
  for (auto& i : q) {
    cin >> i.fi >> i.se;
    i.fi--;
    c.pb(i.se);
  } sort(all(c));
  auto it = unique(all(c));
  c.erase(it, c.end());
  map <ll, ll> z;
  forn(i,sz(c)) z[c[i]] = i;
  for (auto& i : q) {
    i.se = z[i.se];
  } N = sz(c);
  Fenwick tree(n);

//  tree.update(0, 2);
//  tree.update(1, 1);
//
//  cout << tree.getSum(1, 1) << ln;



  for (auto& i : q) {
    cout << tree.getSum(i.fi, i.se) << ' ';
    tree.update(i.fi, i.se);
  }






}