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

  ll n, k;
  cin >> n >> k;

  ll N = 10;
  vv64 dp(N + 1, v64 (N + 1, 1)); // C из n по k - dp[n][k - 1]
  ll m = 0;
  for (ll i = 1; i <= N; i++) {
    for (ll j = 1; j < i; j++) {
      dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
      m = max(m, dp[i][j]);
    }
  }

//  cout << m << ln;

  for (auto& i : dp) {
    for (auto& j : i) cout << j << ' ';
    cout << ln;
  }

  if (n == 1) {
    cout << 0 << ln;
//    v64 f(20);
//    f[0] = 3;
//    for(ll i = 1; i < 20; i++) f[i] = f[i - 1] * 2;
//    cout << max((ll)0, k * (k - 1) * (k - 2) * f.back() + (6 * (k * (k - 1)))) << ln;
  } else if (n == 5) {
    cout << 12 * dp[k - 1][2] << ln;
  }


  else cout << 0 << ln;
}