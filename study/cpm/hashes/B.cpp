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

ll k = 239, mod = 1791791791;

ll subHash(ll l, ll r, v64&h, v64&ks) {
	return ((h[r] - ((h[l] * ks[r - l]) % mod) + mod) % mod);
}

bool isPalindrome(ll l, ll r, v64&h, v64&hr, v64& ks) {
	ll n = sz(h) - 1;
	ll H1 = subHash(l, r + 1, h, ks);
	ll H2 = subHash(n - r - 1, n - l, hr, ks);
	// cout << "PAL: " << l << ' ' << r << ' ' << H1 << ' ' << H2 << ln;
	return (H1 == H2);


}

int main() {
  fast_cin();

  string s;
  cin >> s;

  ll n = sz(s);
  v64 h(n + 1, 0);
  v64 hr(n + 1, 0);
  v64 ks(n + 1, 1);

  forn(i,n) {
  	ks[i + 1] = (ks[i] * k) % mod;
  	h[i + 1] = (h[i] * k + (s[i] - 'a' + 1)) % mod;
  	hr[i + 1] = (hr[i] * k + (s[n - i - 1] - 'a' + 1)) % mod;
  }

  // for (auto& i : h) cout << i << ' ';
 	// cout << ln;

 	// for (auto& i : hr) cout << i << ' ';
 	// cout << ln;

  vv64 dp(n, v64(n, 0));
  forn(i,n) dp[i][i] = 1;

  for (ll len = 2; len <= n; len++) {
  	for (ll l = 0; l < n - len + 1; l++) {
  		ll r = l + len - 1;
  		dp[l][r] = dp[l + 1][r] + dp[l][r - 1] - dp[l + 1][r - 1] + isPalindrome(l, r, h, hr, ks);
  	}
  } 

  ll q;
  cin >> q;
  while(q--) {
  	ll l, r;
  	cin >> l >> r; l--; r--;
  	cout << dp[l][r] << ln;
  }


  // for (auto& i : dp) {
  // 	for (auto& j : i) cout << j << ' ';
  // 		cout << ln;
  // }



}
