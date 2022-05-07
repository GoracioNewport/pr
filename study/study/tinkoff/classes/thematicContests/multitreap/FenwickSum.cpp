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

struct Fenwick {
  v64 t;
  ll n;

  Fenwick(v64& a) {
    n = sz(a) + 1;
    t.assign(n, 0);
    forn(i,n - 1) update(i, a[i]);
  }

  void update(ll i, ll x) {
    i++;
    for(; i < n; i += i & -i) t[i] += x;
  }

  ll sum(ll r) {
    r++;
    ll ans = 0;
    for(; r > 0; r -= r & -r) ans += t[r];
    return ans;
  }

  ll sum(ll l, ll r) {
    return sum(r) - sum(l - 1);
  }
};

int main() {
  fast_cin();

  ll n, m;
  cin >> n >> m;
  v64 a(n);
  for (auto& i : a) cin >> i;
  Fenwick f(a);
  while(m--) {
    ll t, l, r;
    cin >> t >> l >> r;
    if (t == 1) {
      f.update(l, -a[l] + r);
      a[l] = r;
    } else cout << f.sum(l, r - 1) << ln;
  }

}