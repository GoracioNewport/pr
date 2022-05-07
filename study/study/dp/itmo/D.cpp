//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
//#pragma GCC optimize("unroll-loops")
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

ll mod = 1e9;

int main() {
  fast_cin();

  ll n;
  cin >> n;
  vv64 dp(n, v64 (10, 1));
  dp[0][0] = dp[0][8] = 0;
  forsn(i,1,n) {
  	dp[i][0] = (dp[i - 1][4] + dp[i - 1][6]) % mod;
  	dp[i][1] = (dp[i - 1][6] + dp[i - 1][8]) % mod;
  	dp[i][2] = (dp[i - 1][7] + dp[i - 1][9]) % mod;
  	dp[i][3] = (dp[i - 1][4] + dp[i - 1][8]) % mod;
  	dp[i][4] = (dp[i - 1][3] + dp[i - 1][9] + dp[i - 1][0]) % mod;
  	dp[i][5] = 0;
  	dp[i][6] = (dp[i - 1][1] + dp[i - 1][7] + dp[i - 1][0]) % mod;
  	dp[i][7] = (dp[i - 1][2] + dp[i - 1][6]) % mod;
  	dp[i][8] = (dp[i - 1][1] + dp[i - 1][3]) % mod;
  	dp[i][9] = (dp[i - 1][2] + dp[i - 1][4]) % mod;
  } cout << (dp[n - 1][0] + dp[n - 1][1] + dp[n - 1][2] + dp[n - 1][3] + dp[n - 1][4] + dp[n - 1][5] + dp[n - 1][6] + dp[n - 1][7] + dp[n - 1][8] + dp[n - 1][9]) % mod << ln;

}