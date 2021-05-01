// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
// #pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

// Author: @GoracioNewport

using namespace std;

typedef int ll;
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
#define INF (ll)2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

enum { ADD, REPLACE };

struct block {
  ll ans;
  bool left;
  bool type;
  ll ind;
  bool operator <(const block &o) const {
    return ans < o.ans;
  }
};

string s;
ll n;
vector <vector <block>> dp;
string path;

map <char, char> p = {
    {'[', ']'},
    {'(', ')'},
    {']', '['},
    {')', '('}
};

// ([(]

string f(ll i, ll j) {
//  cout << i << ' ' << j << ln;
  string l = "";
  if (i > j) return l;
  if (i == j) {
    if (s[i] == '(' || s[i] == '[') return {s[i], p[s[i]]};
    else return {p[s[i]], s[i]};
  }
  if (dp[i][j].left && !dp[i][j].type) { // LEFT ADD
    ll k = dp[i][j].ind;
    l += s[i] + f(i + 1, k) + p[s[i]] + f(k + 1, j);
  } else if (dp[i][j].left && dp[i][j].type) { // LEFT REPLACE
    ll k = dp[i][j].ind;
    l += s[i] + f(i + 1, k - 1) + p[s[i]] + f(k + 1, j);
  } else if (!dp[i][j].left && !dp[i][j].type) { // RIGHT ADD
    ll k = dp[i][j].ind;
    l += f(i, k) + p[s[j]] + f(k + 1, j - 1) + s[j];
  } else { // RIGHT REPLACE
    ll k = dp[i][j].ind;
    l += f(i, k - 1) + p[s[j]] + f(k + 1, j - 1) + s[j];
  } return l;
}

int main() {
  fast_cin();
  cin >> s;
  n = sz(s);
  dp.resize(n, vector <block> (n, {0,0,0,0}));
  map <pair <char, char>, bool> match = {
      {{'(', ')'}, true},
      {{'[', ']'}, true},
  };

  forn(i,n) {
    dp[i][i].ans = 1;
    dp[i][i].left = true;
    dp[i][i].type = ADD;
    if (s[i] == '(' || s[i] == '[') dp[i][i].ind = i;
    else dp[i][i].ind = i - 1;
  }

  for (ll len = 2; len <= n; len++) {
    for (ll i = 0; i < n - len + 1; i++) {
      ll j = i + len - 1;
      block ans = {INF, 0,0,0};
      // dp[i + 1][j]
      if (s[i] == ')' || s[i] == ']') {
        ans = dp[i + 1][j];
        ans.ans++;
        ans.left = true;
        ans.type = ADD;
        ans.ind = i - 1;
      } else {
        { // ADD
          for (ll k = i; k < j; k++) {
            block New;
            New.ans = dp[i + 1][k].ans + dp[k + 1][j].ans + 1;
            New.left = true;
            New.type = ADD;
            New.ind = k;
            ans = min(ans, New);
          }
        }

        { // REPLACE
          for (ll k = i + 1; k < j; k++) {
            if (!match[{s[i], s[k]}]) continue;
            block New;
            New.ans = dp[i + 1][k - 1].ans + dp[k + 1][j].ans;
            New.left = true;
            New.type = REPLACE;
            New.ind = k;
            ans = min(ans, New);
          } if (match[{s[i], s[j]}]) {
            block New;
            New.ans = dp[i + 1][j - 1].ans;
            New.left = true;
            New.type = REPLACE;
            New.ind = j;
            ans = min(ans, New);
          }
        }
      }

      // dp[i][j - 1]

      if (s[j] == '(' || s[j] == '[') {
        ans = dp[i][j - 1];
        ans.ans++;
        ans.left = false;
        ans.type = ADD;
        ans.ind = j;
      } else {
        { // ADD
          for (ll k = i - 1; k < j; k++) {
            block New;
            New.ans = dp[i][k].ans + dp[k + 1][j - 1].ans + 1;
            New.left = false;
            New.type = ADD;
            New.ind = k;
            ans = min(ans, New);
          }
        }

        { // REPLACE
          for (ll k = i + 1; k < j; k++) {
            if (!match[{s[k], s[j]}]) continue;
            block New;
            New.ans = dp[i][k - 1].ans + dp[k + 1][j - 1].ans;
            New.left = false;
            New.type = REPLACE;
            New.ind = k;
            ans = min(ans, New);
          } if (match[{s[i], s[j]}]) {
            block New;
            New.ans = dp[i + 1][j - 1].ans;
            New.left = false;
            New.type = REPLACE;
            New.ind = i;
            ans = min(ans, New);
          }
        }
      } dp[i][j] = ans;
    }
  }

  cout << f(0, n - 1) << ln;

//  for (auto &i : dp) {
//    for (auto &j : i) cout << j.ans << ' ' << j.left << ' ' << j.type << ' ' << j.ind << " - ";
//    cout << ln;
//  }

}