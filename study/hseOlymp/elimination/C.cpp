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

ll mod = 1e9 + 7;

ll binPow(ll a, ll n) {
  if (n == 0) return 1;
  else if (n % 2 == 0) {
    ll b = binPow(a, n / 2);
    return (b * b) % mod;
  } else return (binPow(a, n - 1) * a) % mod;
}

int main() {
  fast_cin();

  ll n;
  cin >> n;
  v64 cnt(n);
  forn(i,n - 1) {
    ll x, y;
    cin >> x >> y; x--; y--;
    cnt[x]++;
    cnt[y]++;
  } ll m = 0;
  for (auto& i : cnt) m = max(m, i);
  if (m <= 2) {
    ll ans = 0;
    for (ll len = 0; len < n; len++) {
//      cout << len << ' ' << (n - len) * (len == 0 ? 1 : 2) * binPow(2, n - len - 1) << ln;
      ans = (ans + (((n - len) * (len == 0 ? 1 : 2) * binPow(2, n - len - 1))) % mod) % mod;
    } cout << ans << ln;
    return 0;
  }

  cout << ((binPow(2, n - 3) * (n - 1) * (n - 2) % mod) + (binPow(2, n - 2) * (n - 1) * 2 % mod) + (binPow(2, n - 1) * n % mod)) % mod << ln;

}