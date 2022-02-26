#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

// Author: @GoracioNewport
  
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

  int m;
  cin >> m;

  int n = 2e7;

  v32 cnt(n + 1);

  ll t = chrono::high_resolution_clock().now().time_since_epoch().count();

  while(m--) {
    int x; cin >> x;

    for (int i = 1; i * i <= x; i++) {
      if (x % i == 0) {
        cnt[i]++;
        if (i * i != x) cnt[x / i]++;
      }
    }
  }


  v32 lp(n + 1), primes;



  for (int i = 2; i <= n; i++) {
    if (lp[i] == 0) {
      lp[i] = i;
      primes.pb(i);
    } for (auto &x : primes) {
      if (i * x > n || x > lp[i]) break;
      lp[i * x] = x;
    }
  }

  v64 dp(n + 1);
  forn(i,n + 1) dp[i] = (ll)cnt[i] * (ll)i;

  for (int i = n; i >= 1; i--) {
//    for (ll j = 2; j * i <= n; j++) {
//      dp[i] = max(dp[i], dp[i * j] + (cnt[i] - cnt[i * j]) * i);
//    }

    int x = i;
    while(x > 1) {
      dp[i / lp[x]] = max(dp[i / lp[x]], dp[i] + (ll)(i / lp[x]) * (ll)(cnt[i / lp[x]] - cnt[i]));
      x = x / lp[x];
    }
  } cout << dp[1] << ln;


//  cout << fixed << setprecision(20) << (chrono::high_resolution_clock().now().time_since_epoch().count() - t) / 1e9 << " secs" << ln;

}
