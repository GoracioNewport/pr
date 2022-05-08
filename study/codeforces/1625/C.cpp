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

  ll n, l, K;
  cin >> n >> l >> K;
  vp64 d(n);
  for (auto& i : d) cin >> i.fi;
  for (auto& i : d) cin >> i.se;

  d.pb({l, 0});

  vv64 dp(n + 1, v64 (K + 1, INF));
  dp[0][0] = 0;
  forn(i,n) dp[i + 1][0] = dp[i][0] + (d[i + 1].fi - d[i].fi) * d[i].se;

  for (ll i = 1; i <= n; i++) {
    for (ll j = 0; j < i; j++) {
      for (ll k = 1; k <= K; k++) {
        if (k - (i - j - 1) >= 0) dp[i][k] = min(dp[i][k], dp[j][k - (i - j - 1)] + (d[i].fi - d[j].fi) * d[j].se);
      }



    }
  } cout << *min_element(all(dp.back()));



}

//4 10 3
//0 3 4 8
//5 8 3 6

