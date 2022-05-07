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

  ll n, m;
  cin >> n >> m;
  ll k;
  cin >> k;
  vv32 isDiagonal(n, v32 (m, 0));
  while(k--) {
    ll x, y;
    cin >> x >> y; x--; y--;
    isDiagonal[x][y] = 1;
  } vector <vector <double>>  dp(n + 1, vector <double> (m + 1, 0));
  forn(i,n + 1) dp[i][0] = i * 100;
  forn(i,m + 1) dp[0][i] = i * 100;
  forsn(i,1,n + 1) {
    forsn(j,1,m + 1) {
      dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 100;
      if (isDiagonal[i - 1][j - 1]) dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + hypot(100,100));
    }
  } cout << fixed << setprecision(0) << dp[n][m] << ln;
//  for (auto &i : dp) {
//    for (auto &j : i) {
//      cout << j << ' ';
//    } cout << ln;
//  }


}