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

ll n, a, b, c;

ll A(ll n) {
  n /= 2;
  return n;
}

ll B(ll n) {
  n++;
  n /= 2;
  return n;
}

ll C(ll n) {
  n = max(0ll, n - 1);
  n /= 2;
  return n;
}

int main() {
  fast_cin();

  cin >> n >> a >> b >> c;
  vector <vector <vector <ll>>> dp(a + 1, vv64 (b + 1, v64 (c + 1, INF)));
  dp[0][0][0] = n;

  for (ll i = 0; i <= a; i++) {
    for (ll j = 0; j <= b; j++) {
      for (ll k = 0; k <= c; k++) {
        if (i > 0) dp[i][j][k] = min(dp[i][j][k], A(dp[i - 1][j][k]));
        if (j > 0) dp[i][j][k] = min(dp[i][j][k], B(dp[i][j - 1][k]));
        if (k > 0) dp[i][j][k] = min(dp[i][j][k], C(dp[i][j][k - 1]));
      }
    }
  } cout << dp[a][b][c] << ln;

}