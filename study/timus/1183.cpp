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

map <char, char> p = {
    {'[', ']'},
    {'(', ')'},
    {']', '['},
    {')', '('}
};

map <pair <char, char>, bool> match {
    {{'(', ')'}, true},
    {{'[', ']'}, true}
};

// ([(]

string f(ll i, ll j) {
  if (i > j) return "";
  string q = "";
  if (dp[i][j].left && dp[i][j].type == ADD) { // LEFT ADD
    ll k = dp[i][j].ind;
    q += s[i - 1] + f(i + 1, k) + p[s[i - 1]] + f(k + 1, j);
  } else if (dp[i][j].left && dp[i][j].type == REPLACE) { // LEFT REPLACE
    ll k = dp[i][j].ind;
    q += s[i - 1] + f(i + 1, k - 1) + p[s[i - 1]] + f(k + 1, j);
  } else if (!dp[i][j].left && dp[i][j].type == ADD) { // RIGHT ADD
    ll k = dp[i][j].ind;
    q += f(i, k) + p[s[j - 1]] + f(k + 1, j - 1) + s[j - 1];
  } else if (!dp[i][j].left && dp[i][j].type == REPLACE) { // RIGHT REPLACE
    ll k = dp[i][j].ind;
    q += f(i, k - 1) + p[s[j - 1]] + f(k + 1, j - 1) + s[j - 1];
  } return q;
}

int main() {
//  fast_cin();

  cin >> s;
  n = sz(s);
  dp.resize(n + 2, vector <block> (n + 2));
  forsn(i,1,n + 1) {
    dp[i][i].ans = 1;
    dp[i][i].type = ADD;
    if (s[i - 1] == '(' || s[i - 1] == '[') {
      dp[i][i].ind = i;
      dp[i][i].left = true;
    } else {
      dp[i][i].ind = i - 1;
      dp[i][i].left = false;
    }
  }

  for (ll len = 2; len <= n; len++) {
    for (ll i = 1; i <= n - len + 1; i++) {
      ll j = i + len - 1;
      block ans = {INF, false, ADD, -1};

      { // LEFT


        if (s[i - 1] == ')' || s[i - 1] == ']') {
          block q;
          q.ans = dp[i + 1][j].ans + 1;
          q.left = false;
          q.type = ADD;
          q.ind = i - 1;
          ans = min(ans, q);
        } else {

          // ADD
          for (ll k = i; k <= j; k++) {
            block q;
            q.ans = dp[i + 1][k].ans + dp[k + 1][j].ans + 1;
            q.left = true;
            q.type = ADD;
            q.ind = k;
            ans = min(ans, q);
          }

          // REPLACE

          for (ll k = i + 1; k <= j; k++) {
            if (!match[{s[i - 1], s[k - 1]}]) continue;
            block q;
            q.ans = dp[i + 1][k - 1].ans + dp[k + 1][j].ans;
            q.left = true;
            q.type = REPLACE;
            q.ind = k;
            ans = min(ans, q);
          }
        }


      }


      { // RIGHT

        if (s[j - 1] == '(' || s[j - 1] == '[') {
          block q;
          q.ans = dp[i][j - 1].ans + 1;
          q.left = false;
          q.type = ADD;
          q.ind = j;
          ans = min(ans, q);
        } else {
          // ADD
          for (ll k = i - 1; k < j; k++) {
            block q;
            q.ans = dp[i][k].ans + dp[k + 1][j - 1].ans + 1;
            q.left = false;
            q.type = ADD;
            q.ind = k;
            ans = min(ans, q);
          }

          // REPLACE
          for (ll k = i; k < j; k++) {
            if (!match[{s[k - 1], s[j - 1]}]) continue;
            block q;
            q.ans = dp[i][k - 1].ans + dp[k + 1][j - 1].ans;
            q.left = false;
            q.type = REPLACE;
            q.ind = k;
            ans = min(ans, q);
          }
        }
      } dp[i][j] = ans;
    }
  }


//  cout << dp[1][n].ans << ln;
//
//  for (auto &i : dp) {
//    for (auto &j : i) cout << j.ans << ' ' << j.left << ' ' << j.type << ' ' << j.ind << " - ";
//    cout << endl;
//  }

  cout << f(1, n) << ln;

}

//3
//0 0 0 0 - 0 0 0 0 - 0 0 0 0 - 0 0 0 0 - 0 0 0 0 -
//0 0 0 0 - 1 1 0 1 - 2 1 0 1 - 3 1 0 1 - 0 0 0 0 -
//0 0 0 0 - 0 0 0 0 - 1 1 0 2 - 2 1 0 2 - 0 0 0 0 -
//0 0 0 0 - 0 0 0 0 - 0 0 0 0 - 1 1 0 3 - 0 0 0 0 -
//0 0 0 0 - 0 0 0 0 - 0 0 0 0 - 0 0 0 0 - 0 0 0 0 -