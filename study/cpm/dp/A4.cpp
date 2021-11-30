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

  freopen("salesman.in", "r", stdin);
  freopen("salesman.out", "w", stdout);

  ll n, m;
  cin >> n >> m;
  vv64 a(n, v64(n, INF));
  forn(i,m) {
  	ll x, y, c;
  	cin >> x >> y >> c;
  	x--; y--;
  	a[x][y] = c;
  	a[y][x] = c;
  } 

  vv64 dp((1 << n), v64(n, INF)); // dp[i][j] - подмножество i, закончилось в j
  for(ll i = 0; i < n; i++) dp[(1 << i)][i] = 0;
  for(ll i = 0; i < (1 << n); i++) {
  	for(ll j = 0; j < n; j++) { // Куда мы пойдем 
  		if ((1 << j) & i) continue;
  		for (ll k = 0; k < n; k++) { // Откуда пойдем
  			if (!((1 << k) & i) || (j == k)) continue;
  			// cout << i << ' ' << j << ' ' << k << ' ' << a[k][j] << ' ' << dp[i][k] << ln;
  			dp[i | (1 << j)][j] = min(dp[i | (1 << j)][j], dp[i][k] + a[k][j]);
  		}
  	}
  } ll ans = INF;
  forn(i,n) ans = min(ans, dp[(1 << n) - 1][i]);
  cout << (ans == INF ? -1 : ans) << ln;


  // forn(i, (1 << n)) {
  // 	cout << "---" << i << ln;
  // 	forn(j,n) {
  // 		cout << j + 1 << ' ' << dp[i][j] << ln;
  // 	}
  // }

}
