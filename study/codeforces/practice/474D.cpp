// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
// #pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

// Author: @GoracioNewport

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

  ll mod = 1e9 + 7;
  ll n = 10;

  ll t, k;
  cin >> t >> k;
  vv64 dp(n + 1, v64 (2, 0));
  forn(i,k) dp[i][1] = 1;
  forsn(i,k,n + 1) {
    dp[i][0] = (dp[i - 1][0] + dp[i - k][0]) % mod;
    dp[i][1] = (dp[i - 1][0] + dp[i - 1][1]) % mod;
  }
  v64 s(n + 2, 0);
  forn(i,n + 1) s[i + 1] = (s[i] + dp[i][0] + dp[i][1]) % mod;

  for (auto &i : dp) cout << i[0] + i[1]  << ' ';
  cout << ln;

  for (auto &i : s) cout << i << ' ';
  cout << ln;

  while(t--) {
    ll a, b;
    cin >> a >> b;
    cout << (s[b + 1] - s[a] + mod) % mod << ln;
  }

}