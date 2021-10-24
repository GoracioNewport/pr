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

bool DEBUG = false;
ll mod = 1e9 + 7;

ll getAns(string s) {
  ll n = sz(s);
  vector <vector <vector <ll>>> dp(n, vv64 (10, v64 (3, 0))); // k = 0 если мы уже меньше числа s, k = 1 если мы равны, k = 2 если больше
  for(ll j = 1; j < 10; j++) {
    if (j < (s[0] - '0')) dp[0][j][0] = 1;
    else if (j == (s[0] - '0')) dp[0][j][1] = 1;
    else dp[0][j][2] = 1;
  } for (ll i = 1; i < n; i++) {
    for (ll j = 0; j < 10; j++) {
      for (ll k = 1; k <= j; k++) {

        if (j < (s[i] - '0')) dp[i][j][0] = (dp[i][j][0] + dp[i - 1][k][1] + dp[i - 1][k][0]) % mod;
//        else if (j == (s[i] - '0')) dp[i][j][0] = (dp[i][j][0] + dp[i - 1][k][0]) % mod;
        else dp[i][j][0] = (dp[i][j][0] + dp[i - 1][k][0]) % mod;

        if (s[i] - '0' == j) dp[i][j][1] = (dp[i][j][1] + dp[i - 1][k][1]) % mod;

        if (j <= (s[i] - '0')) dp[i][j][2] = (dp[i][j][2] + dp[i - 1][k][2]) % mod;
//        else if (j == (s[i] - '0')) dp[i][j][2] = (dp[i][j][2] + dp[i - 1][k][2] + dp[i - 1][k][1]) % mod;
        else dp[i][j][2] = (dp[i][j][2] + dp[i - 1][k][2] + dp[i - 1][k][1]) % mod;

      }
    }
  } ll ans = 0;
//  forn(i,10) {
//    if (DEBUG) cout << i << ' ' << dp[n - 1][i][0] << ' ' << dp[n - 1][i][1] << ln;
//    ans += (dp[n - 1][i][0] + dp[n - 1][i][1]);
//  }

  forn(i,n) {
    forn(j,10) {
      if (i == n - 1) ans = (ans + dp[i][j][0] + dp[i][j][1]) % mod;
      else ans = (ans + dp[i][j][0] + dp[i][j][1] + dp[i][j][2]) % mod;
    }
  }

  return ans;
}

ll solveStupid(string L, string R) {
  ll l = stoll(L);
  ll r = stoll(R);
  ll ans = 0;
  for (ll i = l; i <= r; i++) {
    string s = to_string(i);
    bool good = true;
    forn(j,sz(s) - 1) if (s[j] > s[j + 1]) good = false;
    ans += good;
  } return ans;
}

int main() {
  fast_cin();

  string L, R;
  cin >> L >> R;
//  cout << solveStupid(L, R);
  ll ans = getAns(R) - getAns(L) + 1;
  forn(i,sz(L) - 1) {
    if (L[i] > L[i + 1]) {
      ans--;
      break;
    }
  }
  cout << (ans + mod) % mod << ln;

//  cout << solveStupid(L, R);

}