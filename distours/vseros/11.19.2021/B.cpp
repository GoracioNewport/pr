#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
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

bool DEBUG = false;

int main() {
  fast_cin();

  int n;
  cin >> n;
  vp64 a(n);
  v64 dp(n, INF);
  for (auto& i : a) cin >> i.fi >> i.se;
  dp[n - 1] = 0; // squared

  for (int i = n - 2; i >= 0; i--) {
    ld g = -INF;

    for (ll j = i + 1; j < n; j++) {
      ld x = atan2(a[j].se - a[i].se, a[j].fi - a[i].fi);
      if (x < g) continue;
      g = max(g, x);
      dp[i] = min(dp[i], max((a[j].fi - a[i].fi) * (a[j].fi - a[i].fi) + (a[j].se - a[i].se) * (a[j].se - a[i].se), dp[j]));
    }
  } cout << fixed << setprecision(20) << sqrt(dp[0]) << ln;


}

//3
//0 10
//1 15
//2 10