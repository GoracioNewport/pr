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


ll n, m;

v64 moves = {2, 3, 5};

void calc(ll i, ll j, ll k, vector <vector < vector <bool>>>& dp, vector <vector < vector <bool>>>& isCalculated, vector <vector <vector <ll>>>& mover) {
  ll child = 0;

  isCalculated[i][j][k] = true;
  if (i + moves[k] < n) {
    child++;
    if (!isCalculated[i + moves[k]][j][(k + 1) % 3]) calc(i + moves[k], j, (k + 1) % 3, dp, isCalculated, mover);
  } if (j + moves[k] < m) {
    child++;
    if (!isCalculated[i][j + moves[k]][(k + 1) % 3]) calc(i, j + moves[k], (k + 1) % 3, dp, isCalculated, mover);
  } if (child == 0) {
    mover[i][j][k] = -1;
    dp[i][j][k] = false;
    return;
  }

  if (i + moves[k] < n && !dp[i + moves[k]][j][(k + 1) % 3]) {
    mover[i][j][k] = 0;
    dp[i][j][k] = true;
  }
  if (j + moves[k] < m && !dp[i][j + moves[k]][(k + 1) % 3]) {
    mover[i][j][k] = 1;
    dp[i][j][k] = true;
  } isCalculated[i][j][k] = true;
}

int main() {
  fast_cin();

  ll t;
  cin >> t;
  while(t--) {
    cin >> n >> m;

    vector <vector <vector <bool>>> dp(n, vector <vector <bool>> (m, vector <bool> (3, 0)));
    vector <vector <vector <bool>>> isCalculated(n, vector <vector <bool>> (m, vector <bool> (3, 0)));
    vector <vector <vector <ll>>> mover(n, vector <vector <ll>> (m, vector <ll> (3, -1)));

    for (ll i = max(0ll, n - 3); i < n; i++) {
      for (ll j = max(0ll, m - 3); j < m; j++) {
        dp[i][j][0] = false;
        isCalculated[i][j][0] = true;
      }
    } for (ll i = max(0ll, n - 4); i < n; i++) {
      for (ll j = max(0ll, m - 4); j < m; j++) {
        dp[i][j][1] = false;
        isCalculated[i][j][1] = true;
      }
    } for (ll i = max(0ll, n - 6); i < n; i++) {
      for (ll j = max(0ll, m - 6); j < m; j++) {
        dp[i][j][2] = false;
        isCalculated[i][j][2] = true;
      }
    }



    calc(0, 0, 0, dp, isCalculated, mover);
    cout << (dp[0][0][0] ? "Alice" : "Bob") << ln;

    ll ind = 0;
    n = 0;
    m = 0;
    while(mover[n][m][ind] != -1) {
      if (mover[n][m][ind] == 0) {
        cout << "DOWN" << ln;
        n += moves[ind];
      }
      else {
        cout << "RIGHT" << ln;
        m += moves[ind];
      } ind = (ind + 1) % 3;
    }



    for(auto& i : dp) {
      for (auto& j : i) cout << j[0] << ' ';
      cout << ln;
    }

  }

}