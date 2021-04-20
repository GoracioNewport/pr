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
  vv64 d(n, v64 (n, 0));
  for (auto &i : d) for (auto &j : i) cin >> j;
  vvp64 dp((1 << n), vp64 (n, {INF, -1}));
  forn(i,n) dp[0][i] = {0, -1};
  forn(i,n) dp[(1 << i)][i] = {0, -1};
  for(ll i = 1; i < (1 << n); i++) {
    for (ll l = 0; l < n; l++) {
      if (!((1 << l) & i)) continue;
      v64 v;
      for (ll j = 0; j < n; j++) if ((1 << j) & i && j != l) v.pb(j);
      if (!sz(v)) continue;
      p64 ans = {INF, -1};
      for (auto &z : v) { // i - текущий набор битов, включая l. l - последний посещенный город. z - посещенный перед этим город.
        if (dp[(i & ~(1 << l))][z].fi + d[l][z] < ans.fi) {
          ans.fi = dp[(i & ~(1 << l))][z].fi + d[l][z];
          ans.se = z;
        }
      }
      dp[i][l] = ans;
    }
  } ll ans = INF;
  p64 prev = {(1 << n) - 1, -1};
  forn(i,n) {
    if (dp[(1 << n) - 1][i].fi < ans) {
      ans = dp[(1 << n) - 1][i].fi;
      prev.se = i;
    }
  } v64 vans;
  forn(i,n) {
    vans.pb(prev.se);
    ll p = prev.se;
    prev.se = dp[prev.fi][prev.se].se;
    prev.fi = prev.fi & ~(1 << p);
  } reverse(all(vans));
  cout << ans << ln;
  for (auto &i : vans) cout << i + 1 << ' ';

}