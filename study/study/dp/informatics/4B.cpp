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

struct Man {
    ll a, b, c;
};

int main() {
  fast_cin();

  ll n;
  cin >> n;
  vector <Man> a(n);
  for (auto &i : a) cin >> i.a >> i.b >> i.c;
  v64 dp(n + 1);
  if (n == 1) {
    cout << a[0].a << ln;
    return 0;
  }
  dp[1] = a[0].a;
  dp[2] = min(a[0].a + a[1].a, a[0].b);
  forsn(i,2,n) {
    dp[i + 1] = min(min(dp[i] + a[i].a, dp[i - 1] + a[i - 1].b), dp[i - 2] + a[i - 2].c);
  } cout << dp[n] << ln;

}