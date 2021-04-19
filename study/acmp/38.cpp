// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
// #pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

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
    v64 a(n);
    for (auto &i : a) cin >> i;
    vvp64 dp(n, vp64 (n, {0, 0}));
	forn(i, n) dp[i][i] = {a[i], 0};
	forsn(len, 2, n + 1) {
		forn(l, n - len + 1) {
			ll r = l + len - 1;
			// cout << len << ' ' << l << ' ' << r << endl; 
			if ((r - l) % 2) { // Ходит второй 
				if ((dp[l + 1][r].fi - (dp[l + 1][r].se + a[l])) > (dp[l][r - 1].fi - (dp[l][r - 1].se + a[r]))) {
					dp[l][r] = dp[l][r - 1];
					dp[l][r].se += a[r];
				} else {
					dp[l][r] = dp[l + 1][r];
					dp[l][r].se += a[l];
				}
			} else { // Ходит первый
				if ((dp[l + 1][r].se - (dp[l + 1][r].fi + a[l])) > (dp[l][r - 1].se - (dp[l][r - 1].fi + a[r]))) {
					dp[l][r] = dp[l][r - 1];
					dp[l][r].fi += a[r];
				} else {
					dp[l][r] = dp[l + 1][r];
					dp[l][r].fi += a[l];
				}
			}
		}
	} 

	// for (auto &i : dp) {
	// 	for (auto &j : i) {
	// 		cout << j.fi << ' ' << j.se << ", ";
	// 	} cout << endl;
	// }


	if (n % 2) {
		if ((dp[0][n - 1].fi - dp[0][n - 1].se) > 0) cout << 1 << endl;
		else if ((dp[0][n - 1].fi - dp[0][n - 1].se) < 0) cout << 2 << endl;
		else cout << 0 << endl;
	} else {
		if ((dp[0][n - 1].fi - dp[0][n - 1].se) < 0) cout << 1 << endl;
		else if ((dp[0][n - 1].fi - dp[0][n - 1].se) > 0) cout << 2 << endl;
		else cout << 0 << endl;
	}

}
