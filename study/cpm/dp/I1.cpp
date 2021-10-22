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
  ll n;
  cin >> n;
  v64 a(n);
  for (auto& i : a) cin >> i;
  reverse(all(a));

  v64 p(n, -1), dp(n + 1, INF), ind_dp(n + 1, -1);
  dp[0] = -INF;

  forn(i,n) {
    ll l = 0, r = n + 1;
    // dp[l]: dp[l] < a[i] и l - max

    while (r - l > 1) { // [l; r)
      ll m = (r + l) / 2;
      if (dp[m] <= a[i])
        l = m;
      else
        r = m;
    }

    dp[l + 1] = a[i];
    ind_dp[l + 1] = i;
    p[i] = ind_dp[l];
  }

  ll i = 1;
  while (i < n && dp[i + 1] != INF)
    ++i;

  i = ind_dp[i]; // индекс (из a) последнего элемента самой длинной ВП
  vector<ll> ans;
  ans.push_back(i );
  while (p[i] != -1) {
    i = p[i];
    ans.push_back(i);
  }

//  reverse(ans.begin(), ans.end());
  cout << sz(ans) << ln;
  for (auto& i : ans) cout << n - i << ' ';
}