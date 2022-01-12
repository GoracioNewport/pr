//#pragma GCC optimize("Ofast")if 
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

ll mod = (1 << 30) + 1;

bool bit(ll x, ll i) {
	return ((x & (1 << i)) > 0);
}

int main() {
  fast_cin();

  ll n, m;
  cin >> n >> m;

  if (m < n) swap(n, m); // n < m

  if (n == 1) {
  	ll ans = 1;
  	forn(i,m) ans = (ans * 2) % mod;
  	cout << ans << ln;
  	return 0;
  }

  vector <vector <vector <ll>>> dp(n, vv64 (m, v64 ((1 << (n + 2)))));

  forn(i, (1 << (n + 2))) {
  	if (bit(i, 0) == bit(i, 1) && bit(i, 1) == bit(i, n) && bit(i, n) == bit(i, n + 1)) dp[1][1][i] = 0;
  	else dp[1][1][i] = 1;
  }

  forsn(j,1,m) {
  	forsn(i,0,n) {
  		if (i <= 1 && j == 1) continue;
  		// if (j == 1) {

  		// } else {
	  		forn(k, (1 << (n + 2))) {
	  			if (i != 0 && ((bit(k, 0) == bit(k, 1)) && (bit(k, 1) == bit(k, n)) && (bit(k, n) == bit(k, n + 1)))) dp[i][j][k] = 0;
	  			else {
	  				ll prevO = (1 | (k << 1)) & ((1 << (n + 2)) - 1);
	  				ll prevZ = (k << 1) & ((1 << (n + 2)) - 1);

	  				if (i == 0) {

	  					dp[i][j][k] = (dp[n - 1][j - 1][prevO] + dp[n - 1][j - 1][prevZ]) % mod;
	  				} else {
		  				// cout << j << ' ' << i << ' ' << k << ' ' << prevO << ' ' << dp[i - 1][j][prevO] << ' ' << prevZ << ' ' << dp[i - 1][j][prevZ] << endl; 
		  				dp[i][j][k] = (dp[i - 1][j][prevO] + dp[i - 1][j][prevZ]) % mod; 
	  				}
	  			}
	  		}
	  	// }
  	}
  } ll ans = 0;
  forn(i, (1 << (n + 2))) ans = (dp[n - 1][m - 1][i] + ans) % mod;
  cout << ans << ln;

  // forn(i,n) {
  // 	forn(j,m) {
  // 		cout << accumulate(all(dp[i][j]), 0ll) << ' ';
  // 	} cout << ln;
  // }
  
}
