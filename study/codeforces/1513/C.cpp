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

const ll MAX_N = 3e5;

const ll mod = 1e9 + 7;

int main() {
  fast_cin();

  ll t;
  cin >> t;

  v64 dp(MAX_N + 1, 1);
  v64 cur(10, 0);
  cur[9] = 1;
  forsn(i,1,MAX_N + 1) {

    v64 nCur(10, 0);

    nCur[1] = cur[0];
    nCur[2] = cur[1];
    nCur[3] = cur[2];
    nCur[4] = cur[3];
    nCur[5] = cur[4];
    nCur[6] = cur[5];
    nCur[7] = cur[6];
    nCur[8] = cur[7];
    nCur[9] = cur[8];
    nCur[0] = cur[9];
    nCur[1] = (nCur[1] + cur[9]) % mod;

    cur = nCur;

    ll s = 0;
    for (auto &i : cur) s += i;
    dp[i] = s % mod;
  }


  while(t--) {
    string s;
    ll m;
    cin >> s >> m;

    ll ans = 0;

    for(auto &i : s) {
      ll x = i - '0';
      ll lm = m;
      lm -= (9 - x);
      if (lm > 0) ans += dp[lm];
      else ans++;

      ans %= mod;
    } cout << ans << ln;

  }

}