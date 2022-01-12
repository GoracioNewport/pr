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

struct b {
  ll len;
  bool possible;
  string p;
  bool operator< (b a) {
    return len < a.len;
  }
};

int main() {
  fast_cin();

  string s1, s2;
  cin >> s1 >> s2;
  ll n = sz(s1), m = sz(s2);
  vector <vector <b>> dp(n + 1, vector <b> (m + 1, {0, false, ""}));
  dp[0][0].possible = true;
  forsn(i,1,n + 1) {
    if (dp[i - 1][0].possible && s1[i - 1] == '*') dp[i][0].possible = true;
  } forsn(i,1,m + 1) {
    if (dp[0][i - 1].possible && s2[i - 1] == '*') dp[0][i].possible = true;
  }
  forsn(i,1,n + 1) {
    forsn(j,1,m + 1) {
      vector <b> pos;
      if (s1[i - 1] == s2[j - 1] && isalpha(s1[i - 1])) {
        b x = dp[i - 1][j - 1];
        x.len++;
        x.p += s1[i - 1];
        pos.pb(x);
      } else if (s1[i - 1] == '?' && s2[j - 1] == '?') {
        b x = dp[i - 1][j - 1];
        x.len++;
        x.p += 'a';
        pos.pb(x);
      } else if (s1[i - 1] == '*' && s2[j - 1] == '*') {
        pos.pb(dp[i - 1][j - 1]);
        pos.pb(dp[i][j - 1]);
        pos.pb(dp[i - 1][j]);
      }
      else if (s1[i - 1] == '?' && isalpha(s2[j - 1])) {
        b x = dp[i - 1][j - 1];
        x.len++;
        x.p += s2[j - 1];
        pos.pb(x);
      } else if (isalpha(s1[i - 1]) && s2[j - 1] == '?') {
        b x = dp[i - 1][j - 1];
        x.len++;
        x.p += s1[i - 1];
        pos.pb(x);
      } else if (s1[i - 1] == '*' && isalpha(s2[j - 1])) {
         b x = dp[i - 1][j - 1];
         b y = dp[i - 1][j];
         b z = dp[i][j - 1];
         x.len++;
         z.len++;
         x.p += s2[j - 1];
         z.p += s2[j - 1];
         pos.pb(x);
         pos.pb(y);
         pos.pb(z);
      } else if (isalpha(s1[i - 1]) && s2[j - 1] == '*') {
        b x = dp[i - 1][j - 1];
        b y = dp[i - 1][j];
        b z = dp[i][j - 1];
        x.len++;
        y.len++;
        x.p += s1[i - 1];
        y.p += s1[i - 1];
        pos.pb(x);
        pos.pb(y);
        pos.pb(z);
      } else if (s1[i - 1] == '*' && s2[j - 1] == '?') {
        b x = dp[i - 1][j - 1];
        b y = dp[i - 1][j];
        b z = dp[i][j - 1];
        x.len++;
        z.len++;
        x.p += 'a';
        z.p += 'a';
        pos.pb(x);
        pos.pb(y);
        pos.pb(z);
      } else if (s1[i - 1] == '?' && s2[j - 1] == '*') {
        b x = dp[i - 1][j - 1];
        b y = dp[i - 1][j];
        b z = dp[i][j - 1];
        x.len++;
        y.len++;
        x.p += 'a';
        y.p += 'a';
        pos.pb(x);
        pos.pb(y);
        pos.pb(z);
      } vector <b> posFin;
      for (auto &i : pos) {
        if (i.possible) posFin.pb(i);
      } sort(all(posFin));
      if (sz(posFin)) {
        dp[i][j] = posFin[0];
      }
    }
  } cout << (dp[n][m].possible ? dp[n][m].p : "No solution!") << ln;

}