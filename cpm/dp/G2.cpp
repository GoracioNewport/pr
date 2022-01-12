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

enum { OPEN, CLOSE };

string Max(string a, string b) {
  if (sz(a) > sz(b)) return a;
  else return b;
}

bool isValid(ll i, ll j, ll n) {
  return (i <= j && i >= 0 && j >= 0 && i < n && j < n);
}

int main() {
  fast_cin();

  string s;
  cin >> s;
  ll n = sz(s);

  map <char, char> m = {
      {'(', ')'},
      {'[', ']'},
      {'{', '}'},
  };

  map <char, bool> type = {
      {'(', OPEN },
      {'[', OPEN },
      {'{', OPEN },
      {')', CLOSE },
      {']', CLOSE },
      {'}', CLOSE },
  };

  vector <vector <string>> dp(n, vector <string> (n, ""));
  for (ll len = 2; len <= n; len++) {
    for (ll l = 0; l < n - len + 1; l++) {
      ll r = l + len - 1;
      { // Пересчитываемся из dp[l + 1][r];
        if (type[s[l]] == CLOSE) dp[l][r] = Max(dp[l][r], dp[l + 1][r]);
        for (ll i = l + 1; i <= r; i++) {
          if (m[s[l]] != s[i]) continue;
          string x = s[l] + (isValid(l + 1, i - 1, n) ? dp[l + 1][i - 1] : "") + s[i] + (isValid(i + 1, r, n) ? dp[i + 1][r] : "");
          dp[l][r] = Max(dp[l][r], x);
        }
      }
      { // Пересчитываемся из dp[l][r - 1]
        if (type[s[r]] == OPEN) dp[l][r] = Max(dp[l][r], dp[l][r - 1]);
        for (ll i = l; i < r; i++) {
          if (m[s[i]] != s[r]) continue;
          string x = (isValid(l, i - 1, n) ? dp[l][i - 1] : "") + s[i] + (isValid(i + 1, r - 1, n) ? dp[i + 1][r - 1] : "") + s[r];
          dp[l][r] = Max(dp[l][r], x);
        }
      }
    }
  } cout << dp[0][n - 1] << ln;

}