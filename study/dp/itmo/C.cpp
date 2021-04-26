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
  vp64 dp(n, {0,0}); // len, prev;
  dp[0] = {1, -1};
  forsn(i,1,n) {
    p64 ma = {-1,-1};
    forn(j,i) if (a[j] < a[i] && dp[j].fi > ma.fi) ma = {dp[j].fi, j};
    if (ma.fi != -1) dp[i] = {ma.fi + 1, ma.se};
    else dp[i] = {1, -1};
  } ll ans = 0, prev = 0;
  forn(i,n) {
    if (dp[i].fi > ans) {
      ans = dp[i].fi;
      prev = i;
    }
  }
  cout << ans << ln;
  v64 an;
  while(prev != -1) {
//    cout << a[prev] << ' ';
    an.pb(a[prev]);
    prev = dp[prev].se;
  } reverse(all(an));
  for (auto &i : an) cout << i << ' ';

}