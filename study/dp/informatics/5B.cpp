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

  ll n;
  cin >> n;
  v64 a(n);
  for (auto &i : a) cin >> i;
  ll m;
  cin >> m;
  v64 b(m);
  for (auto &i : b) cin >> i;
  vvp64 dp(n + 1, vp64 (m + 1, {0, -1}));
  forsn(i,1,n + 1) {
    forsn(j,1,m + 1) {
      if (a[i - 1] == b[j - 1]) dp[i][j] = {dp[i - 1][j - 1].fi + 1, 0};
      else {
        dp[i][j].fi = max(dp[i - 1][j].fi, dp[i][j - 1].fi);
        if (dp[i][j].fi == dp[i - 1][j].fi) dp[i][j].se = 1;
        else dp[i][j].se = 2;
      }
    }
  } p64 cur = {n, m};
  vp64 ans;
  while(dp[cur.fi][cur.se].se != -1) {
    if (!dp[cur.fi][cur.se].se) {
      ans.pb({cur.fi, a[cur.fi - 1]});
      cur.fi--; cur.se--;
    } else if (dp[cur.fi][cur.se].se == 1) cur.fi--;
    else cur.se--;
  } sort(all(ans));
  for (auto &i : ans) cout << i.se << ' ';

}