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
  ll Or;
  ll And;
};

struct Tree {
  vector <node> t;
  ll n;

//  const ll NULL_ELEMENT = 18446744073709551615;
  const ll NULL_ELEMENT = -1;

  Tree (ll n) {
    t.assign(4 * n, {0, 0});
  }

  void segmentOr(ll v, ll l, ll r, ll L, ll R, ll x) {
//    cout << v << ' ' << l << ' ' << r << endl;
    if (l >= R || r <= L) return;
    if (l >= L && r <= R) {
      t[v].Or |= x;
      t[v].And |= x;
      return;
    } ll m = (l + r) / 2;
    segmentOr(2 * v + 1, l, m, L, R, x);
    segmentOr(2 * v + 2, m, r, L, R, x);
    t[v].Or = t[2 * v + 1].Or | t[2 * v + 2].Or | t[v].Or;
    t[v].And = (t[2 * v + 1].And & t[2 * v + 2].And) | t[v].And;
  }

  ll getAnd(ll v, ll l, ll r, ll L, ll R) {
    if (l >= R || r <= L) return NULL_ELEMENT;
    if (l >= L && r <= R) return t[v].And;
    ll m = (l + r) / 2;
    ll andLeft = getAnd(2 * v + 1, l, m, L, R);
    ll andRight = getAnd(2 * v + 2, m, r, L, R);
    return (andLeft & andRight) | t[v].And;
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
      tree.segmentOr(0,0,n,l,r,x);
//      for (auto &i : tree.t) cout << i.And << ' ';
//      cout << ln;
    } else cout << tree.getAnd(0,0,n,l,r) << ln;
  }

}

