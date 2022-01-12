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

int main() {
  fast_cin();

  ll n, k;
  cin >> n >> k;
  v64 a(n);
  for (auto& i : a) cin >> i;
  v64 dp(n + 1);
  forn(i,n) {
    dp[i + 1] = dp[i] ^ a[i];
  } ll ans = 0;

  vp64 q(k);
  for (auto& i : q) cin >> i.fi >> i.se;
  if (k == 1) {
    if (dp.back() >= q[0].fi && dp.back() <= q[0].se) ans++;
  } else if (k == 2) {
    for (ll i = 1; i < n; i++) { // начало второго блока
      if ((dp[i] >= q[0].fi && dp[i] <= q[0].se) && ((dp.back() ^ dp[i]) >= q[1].fi && (dp.back() ^ dp[i]) <= q[1].se)) ans++;
    }
  } else if (k == 3) {
    for (ll i = 1; i < n - 1; i++) {
      for (ll j = i + 1; j < n; j++) {
        if ((dp[i] >= q[0].fi && dp[i] <= q[0].se) && ((dp[j] ^ dp[i]) >= q[1].fi && (dp[j] ^ dp[i]) <= q[1].se) && ((dp.back() ^ dp[j]) >= q[2].fi && (dp.back() ^ dp[j]) <= q[2].se)) ans++;
      }
    }
  } else if (k == 4) {
    for (ll i = 1; i < n - 2; i++) {
      for (ll j = i + 1; j < n - 1; j++) {
        for (ll k = j + 1; k < n; k++) {
          if ((dp[i] >= q[0].fi && dp[i] <= q[0].se) && ((dp[j] ^ dp[i]) >= q[1].fi && (dp[j] ^ dp[i]) <= q[1].se) && ((dp[k] ^ dp[j]) >= q[2].fi && (dp[k] ^ dp[j]) <= q[2].se) && ((dp.back() ^ dp[k]) >= q[3].fi && (dp.back() ^ dp[k]) <= q[3].se)) ans++;
        }
      }
    }
  } cout << ans << ln;

}