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

int main() {
  fast_cin();

  ll n, k;
  cin >> n >> k;
  vp64 dp(n, {-INF, -1});
  dp[0] = {0, -1};
  v64 a(n);
  forn(i,n - 2) cin >> a[i + 1];
  a[0] = a[n - 1] = 0;

  for(ll i = 0; i < n - 1; i++) {
  	for(ll j = i + 1; j <= min(i + k, n - 1); j++) {
  		dp[j].fi = max(dp[j].fi, dp[i].fi + a[j]);
  		if (dp[j].fi == dp[i].fi + a[j]) dp[j].se = i;
  	}
  } cout << dp[n - 1].fi << ln;
  v64 ans;
  ll b = dp[n - 1].se;
  while(b != -1) {
  	ans.pb(b);
  	b = dp[b].se;
  } cout << sz(ans) << ln;
  reverse(all(ans));
  ans.pb(n - 1);
  for (auto &i : ans) cout << i + 1 << ' ';
  cout << ln;
}
