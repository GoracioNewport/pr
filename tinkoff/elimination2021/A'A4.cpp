//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
//#pragma GCC optimize("unroll-loops")
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
  v64 a(3 * n);
  for (auto &i : a) cin >> i;
  v64 b = a;
  reverse(all(b));

  v64 dp;
  multiset <ll> m;
  ll X = 0;
  forn(i,n) {
    m.insert(b[i]);
    X += b[i];
  } dp.pb(X);
  forsn(i,n,2 * n) {
    X += b[i];
    m.insert(b[i]);
    X -= *prev(m.end());
    m.erase(prev(m.end()));
    dp.pb(X);
  } reverse(all(dp));

  m.clear();
  X = 0;
  forn(i,n) {
    m.insert(a[i]);
    X += a[i];
  } ll ans = X - dp[0]  ;
  forsn(i,n, 2 * n) {
    X += a[i];
    m.insert(a[i]);
    X -= *m.begin();
    m.erase(m.begin());
    ans = max(ans, X - dp[i - n + 1]);
  } cout << ans << ln;




}