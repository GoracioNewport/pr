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

  ll n, a1, k, b, m;
  cin >> n >> a1 >> k >> b >> m;
  v64 a(n);
  a[0] = a1;
  forn(i,n - 1) a[i + 1] = (a[i] * k + b) % m;
  v64 dp(n + 1, INF), pos(n + 1, -1), prev(n + 1, -1);
  dp[0] = -INF;
  ll ans = 0;
  forn(i,n) {
    ll j = upper_bound(all(dp), a[i]) - dp.begin();
    if (dp[j - 1] < a[i] && dp[j] > a[i]) {
      dp[j] = a[i];
      pos[j] = i;
      prev[i] = pos[j - 1];
      ans = max(ans, j);
    }
  }

  v64 path;
  ll p = pos[ans];
  while(p != -1) {
    path.pb(a[p]);
    p = prev[p];
  } reverse(all(path));
  for (auto &i : path) cout << i << ' ';

}