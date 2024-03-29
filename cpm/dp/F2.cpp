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
  vector <ld> a(n);
  for (auto& i : a) cin >> i;

  vector <vector <ld>> dp(n, vector <ld> (n, 0));
  forn(i,n) dp[i][i] = a[i];
  forn(i, n - 1) dp[i][i + 1] = (a[i] + a[i + 1]) / 2;
  for(ll len = 3; len <= n; len++) {
    for(ll l = 0; l < n - len + 1; l++) {
      ll r = l + len - 1;
      for(ll i = l + 1; i < r; i++) {
        dp[l][r] = max(dp[l][r], max(
            (((dp[l][i - 1] + a[i]) / 2) + dp[i + 1][r]) / 2,
            (dp[l][i - 1] + ((a[i] + dp[i + 1][r]) / 2)) / 2));
      } dp[l][r] = max(dp[l][r], max(
          (dp[l][r - 1] + a[r]) / 2,
          (a[l] + dp[l + 1][r]) / 2));
    }
  } cout << setprecision(20) << fixed << dp[0][n - 1] << ln;

}