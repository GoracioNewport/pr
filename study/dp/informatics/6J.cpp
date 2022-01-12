//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
//#pragma GCC optimize("unroll-loops")
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

vv64 dp;
vp64 a;

void f(ll n, ll m) {
  if (dp[n][m] == 0) return;

  else if (dp[n][m] == dp[n - 1][m]) f(n - 1, m);
  else {
    f(n - 1, m - a[n - 1].fi);
    cout << n << ln;
  }
}

int main() {
  fast_cin();

  ll n, m;
  cin >> n >> m;
  a.resize(n);
  for (auto &i : a) cin >> i.fi;
  for (auto &i : a) cin >> i.se;
  dp.resize(n + 1, v64 (m + 1, 0)); // dp[i][j] - first i elements and W j.
  forsn(i,1,n + 1) {
    forsn(j,1,m + 1) {
      dp[i][j] = dp[i - 1][j];
      if (j >= a[i - 1].fi) dp[i][j] = max(dp[i][j], dp[i - 1][j - a[i - 1].fi] + a[i - 1].se);
    }
  }

//  cout << dp[n][m] << ln;

//  forsn(j,1,m) {
//    if (dp[n][j] != dp[n][j + 1]) cout << j << ' ';
//  }

  f(n,m);

//  for (auto &i : dp) {
//    for (auto &j : i) cout << j << ' ';
//    cout << ln;
//  }


}