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

ll mod = 998244353;

int main() {
  fast_cin();

  ll t;
  cin >> t;

  v64 powers(5e5 + 1, 1);
  forsn(i,1,5e5 + 1) powers[i] = (powers[i - 1] * 2) % mod;

  while(t--) {
    ll n;
    cin >> n;
    v64 a(n);
    vv64 inds(n + 2);
    forn(i,n) {
      cin >> a[i];
      if (a[i] <= n) inds[a[i]].pb(i);
    } vv64 dp(n, v64 (2));
    ll cnt = 0;
    for (auto& i : inds[0]) dp[i][0] = powers[cnt++];
    cnt = 0;
    for (auto& i : inds[1]) dp[i][1] = powers[cnt++];

    for (ll x = 1; x < n; x++) {
      // Пересчет dp[j][0], для всех j таких что a[j] = x;
      ll sum = 0, j = 0;
      cnt = 0;
      for (auto& i : inds[x]) {
        while(j < sz(inds[x - 1]) && inds[x - 1][j] < i) {
          sum = (sum + dp[inds[x - 1][j]][0]) % mod, j++;
          cnt = 0;
        }
        dp[i][0] = (sum * powers[cnt++]) % mod;
      }
      // Пересчет dp[j][1], для всех j таких что a[j] = x + 1;

      sum = 0, j = 0, cnt = 0;
      for (auto& i : inds[x + 1]) {
        while(j < sz(inds[x - 1]) && inds[x - 1][j] < i) {
          sum = (sum + dp[inds[x - 1][j]][0]) % mod, j++;
        }
        dp[i][1] = (sum * powers[cnt++]) % mod;
      }
    } ll ans = 0;
    for (auto& i : dp) ans = (ans + i[0] + i[1]) % mod;



    cout << ans << ln;
  }

}

// 1
// 4
// 0 2 1 0

// ans: 7