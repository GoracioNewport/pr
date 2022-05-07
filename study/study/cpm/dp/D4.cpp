// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
// #pragma GCC optimize("unroll-loops")
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

int main() {
  fast_cin();

  ll n, m;
  cin >> n >> m;

  if (m > n) swap(n, m);

  vv64 dp(n, v64 ((1 << m), 0));
  forn(j,(1 << m)) dp[0][j] = 1;

  forsn(i,1,n) {
  	forn(j,(1 << m)) { // предыдущая маска
  		vector <bool> usedJ(m);
  		forn(J,m) if (j & (1 << J)) usedJ[J] = true;
  		forn(k,(1 << m)) { // текущая маска
  			vector <bool> usedK(m);
  			forn(K,m) if (k & (1 << K)) usedK[K] = true;
  			bool good = true;
  			forn(i,m - 1) if ((usedJ[i] == usedJ[i + 1]) && (usedJ[i + 1] == usedK[i + 1]) && (usedK[i + 1] == usedK[i])) good = false;
  			if (good) dp[i][k] = (dp[i][k] + dp[i - 1][j]) % mod;
  		}
  	}
  } ll ans = 0;
  forn(i,(1 << m)) ans = (ans + dp[n - 1][i]) % mod;
  cout << ans << ln;


}
