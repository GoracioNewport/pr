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

int main() {
  fast_cin();

  ll n;
  cin >> n;
  vv64 a(n, v64 (n));
  for (auto& i : a) for (auto& j : i) cin >> j;
  forn(i,n) a[i][i] = INF;
  vvp64 dp((1 << n), vp64 (n, {INF, -1}));
  forn(i,n) dp[(1 << i)][i] = {0, -1};

  for (ll i = 0; i < (1 << n); i++) {
    for (ll j = 0; j < n; j++) { // откуда идем
      if (!((1 << j) & i)) continue;
      for (ll k = 0; k < n; k++) { // куда идем
        if ((1 << k) & i) continue;
        dp[i | (1 << k)][k] = min(dp[i | (1 << k)][k], {dp[i][j].fi + a[j][k], k});
      }
    }
  } p64 ans = {INF, 0};
  forn(i,n) ans = min(ans, {dp[(1 << n) - 1][i].fi, i});
  cout << ans.fi << ln;
  ll state = (1 << n) - 1;
  v64 path;
  while(ans.se != -1) {
    path.pb(ans.se);
    ll x = ans.se;
    ans.se = dp[state][ans.se].se;
    state = state & (((1 << 30) - 1) ^ (1 << x));
  } reverse(all(path));
  for (auto& i : path) cout << i << ' ';

}