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
    ll n;
    v64 t;

    Tree (ll _n) {
      n = _n;
      t.assign(4 * n, 0);
//      a.resize(n, 0);
    }

    void setX(ll v, ll l, ll r, ll i, ll x) {
      if (l + 1 == r) {
        t[v] = x;
        return;
      } ll m = (l + r) / 2;
      if (i < m) setX(2 * v + 1, l, m, i, x);
      else setX(2 * v + 2, m, r, i, x);
      t[v] = min(t[2 * v + 1], t[2 * v + 2]);
    }

    ll getAns(ll v, ll l, ll r, ll i) {
      if (r <= i || t[v] > 0) {
        return INF;
      }
      if (l + 1 == r) {
        return l;
      }
      ll m = (l + r) / 2;
      ll f = getAns(2 * v + 1, l, m, i);
      if (f == INF) return getAns(2 * v + 2, m, r, i);
      else return f;
    }


};

int main() {
  fast_cin();

  ll q;
  cin >> q;
  ll n = 1e6;
  Tree tree(n);
  forn(i,q) {
    ll x; cin >> x;
    if (x > 0) {
      ll i = tree.getAns(0, 0, n, x - 1);
      tree.setX(0, 0, n, i, 1);
      cout << i + 1 << ln;
    } else tree.setX(0, 0, n, -(x) - 1, 0);

//    for (auto& i : tree.t) cout << i << ' ';
//    cout << ln;
  }
}