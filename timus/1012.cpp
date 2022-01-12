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

  ll n, k, m;
  cin >> n >> k >> m;
  vv64 dp((n + 2), v64 (2));
  dp[0][0] = 0;
  dp[0][1] = (k - 1) % m;
  dp[1][0] = (dp[0][1]) % m;
  dp[1][1] = (dp[0][1] * (k - 1)) % m;
  forsn(i,2,n) {
  	dp[i][0] = ((dp[i - 1][1] + dp[i - 1][0] - dp[i - 2][1]) + m) % m;
  	dp[i][1] = ((dp[i - 1][1] + dp[i - 1][0]) % m) * (k - 1) % m;
  } cout << (dp[n - 1][0] + dp[n - 1][1]) % m << ln;


}	