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

ll mod = 1e8;

int main() {
  fast_cin();

  ll n1, n2, a, b;
  cin >> n1 >> n2 >> a >> b;
  vector <vector <vector <ll>>> dp(n1 + 1, vv64 (n2 + 1, v64 (2, 0)));

  forn(i,n1 + 1) {
    if (i <= a) dp[i][0][0] = 1;
  }

  forn(i, n2 + 1) {
    if (i <= b) dp[0][i][1] = 1;
  }

  forsn(i,1,n1 + 1) {
    forsn(j,1,n2 + 1) {
      dp[i][j][0] = ((((dp[i - 1][j][0] + dp[i][j - 1][1]) % mod) - dp[max((ll)0, i - a)][j][1]) + mod) % mod;
      dp[i][j][1] = ((((dp[i - 1][j][0] + dp[i][j - 1][1]) % mod) - dp[i][max((ll)0, j - b)][0]) + mod) % mod;
    }
  }

  cout << (dp[n1][n2][0] + dp[n1][n2][1]) % mod << ln;

}