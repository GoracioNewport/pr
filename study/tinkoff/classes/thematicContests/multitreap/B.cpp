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

struct Fenwick {
  v64 t; // cnt of zeros
  ll n, logn;

  Fenwick(v64& a) {
    n = sz(a) + 1;
    logn = 0;
    while((1 << logn) < n) logn++;
    t.assign(n, 0);
    forn(i,n-1) if (a[i] == 0) update(i, 1);
  }

  void update(ll i, ll x) {
    i++;
    for(; i < n; i += i & -i) t[i] += x;
  }

  ll getSum(ll r) {
    r++;
    ll ans = 0;
    for(; r > 0; r -= r & -r) ans += t[r];
    return ans;
  }

  ll getSum(ll l, ll r) {
    return getSum(r) - getSum(l - 1);
  }

  ll lower_bound(ll s) {
    ll k = 0;
    for (ll l = logn; l >= 0; l--) {
      if (k + (1 << l) < n && t[k + (1 << l)] < s) {
        k += (1 << l);
        s -= t[k];
      }
    } return k;
  }

};

int main() {
  fast_cin();

  ll n;
  cin >> n;
  v64 a(n);
  for (auto& i : a) cin >> i;
  Fenwick tree(a);
  ll q;
  cin >> q;
  while(q--) {
    char cmd;
    cin >> cmd;
    if (cmd == 'u') {
      ll i, x;
      cin >> i >> x; i--;
      if (a[i] != 0 && x == 0) tree.update(i, 1);
      if (a[i] == 0 && x != 0) tree.update(i, -1);
      a[i] = x;
    } else {
      ll l, r, k;
      cin >> l >> r >> k;
      k += tree.getSum(0, l - 2);
//      cout << k << ln;
      ll x = tree.lower_bound(k);
      cout << (x < r ? x + 1 : -1) << ln;
    }
  }


}