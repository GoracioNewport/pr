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

  ll n;
  cin >> n;
  vp64 b(n);
  for(auto& i : b) {
  	cin >> i.fi >> i.se;
  } sort(all(b));
  reverse(all(b));

  vp64 a;
  ll maxH = 0;
  for (auto& i : b) {
  	if (i.se > maxH) {
  		maxH = i.se;
  		a.pb(i);
  	}
  } sort(all(a));
  n = sz(a);

  v64 dp(n + 1, INF);
  dp[0] = 0;

  forsn(i,1,n + 1) {
  	for(ll j = 0; j < i; j++) dp[i] = min(dp[i], dp[j] + a[i - 1].fi * a[j].se);
  } cout << dp.back() << ln;

  for (auto& i : dp) cout << i << ' ';
  cout << ln;

  // for (auto& i : a) cout << i.fi << ' ' << i.se << ln;
}