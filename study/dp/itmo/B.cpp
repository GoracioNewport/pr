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
#define ln '\n'
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
  vvp64 dp(n, vp64 (m, {-INF, -1}));
  vv64 a(n, v64 (m));
  for (auto &i : a) for (auto &j : i) cin >> j;
  dp[0][0] = {a[0][0], -1};
	forsn(i,1,n) dp[i][0] = {dp[i - 1][0].fi + a[i][0], 1};
	forsn(i,1,m) dp[0][i] = {dp[0][i - 1].fi + a[0][i], 0};
	forsn(i,1,n) {
		forsn(j,1,m) {
			dp[i][j].fi = max(dp[i - 1][j].fi, dp[i][j - 1].fi) + a[i][j];
			if (dp[i][j].fi == dp[i - 1][j].fi + a[i][j]) dp[i][j].se = 1;
			else dp[i][j].se = 0;
		}
	} cout << dp[n - 1][m - 1].fi << ln;
	string ans;
	p64 cur = {n - 1, m - 1};
	forn(i, n + m - 2) {
		ans.pb(dp[cur.fi][cur.se].se ? 'D' : 'R');
		// cout << ans << ln;
		if (dp[cur.fi][cur.se].se) cur.fi--;
		else cur.se--;
	} reverse(all(ans));
	cout << ans << ln;

	// for (auto &i : dp) {
	// 	for (auto &j : i) cout << j.fi << ' ';
	// 	cout << ln;
	// }
}
