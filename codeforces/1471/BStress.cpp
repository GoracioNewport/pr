#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

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

ll solve(ll n, ll x, v64 a) {
  ll ans = 0;
  for (auto i : a) {
    if (i % x != 0) break;
    while (i % x == 0) {
      forn(j, x) a.pb(i / x);
      i /= x;
    }
  } for (auto &i : a) ans += i;
  return ans;
}

ll smart(ll n, ll x, v64 a) {
  ll ans = 0;
  bool f = false;
  forn(i, n) {
    ll b = a[i];
    while (b % x == 0) {
      b /= x;
      ans += a[i];
      if (f) break;
    } if (b == a[i]) break;
    if (b > 1) f = true;
  } forn(i, n) ans += a[i];
  return ans;
}

int main() {
  fast_cin();

  while (true) {
    ll n = rand() % 10;
    ll x = rand() % 10 + 1;
    v64 a(n);
    for (auto &i : a) {
      i = rand() % 100;
    } if (smart(n, x, a) != solve(n, x, a)) {
      cout << n << ' ' << x << endl;
      for (auto &i : a) cout << i << ' ';
      cout << endl;
      cout << smart(n, x, a) << endl;
      cout << solve(n, x, a) << endl;
      break;
    }
  }

}
