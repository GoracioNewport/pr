#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

// Author: @GoracioNewport

using namespace std;

//typedef long long ll;
typedef int ll;
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
#define INF 2e9
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

int main() {
  fast_cin();

  ll n;
  cin >> n;
  v64 a(n);
  for (auto &i : a) cin >> i;
  v64 dp((1 << n), INF);
  dp[0] = 0;

//  ll gS = 0;
//  for (auto &i : a) gS += i;

//  for (ll i = 0; i < n; i++) {
//    ll ind = 0;
//    ll p = (i - 1 + n) % n;
//    ll c = i;
//    ll ne = (i + 1) % n;
//    ind += (1 << p);
//    ind += (1 << c);
//    ind += (1 << ne);
//    dp[ind] = 0;
//  }

  for(ll i = 1; i < (1 << n); i++) {
    v64 used(n);
    for (ll j = 0; j < n; j++) if ((1 << j) & i) used[j] = 1;
    ll cnt = 0;
    for (auto &i : used) cnt += i;
//    if (cnt < 4) continue;

//    for (auto &i : used) cout << i;
//    cout << ln;

    ll mi = INF;

    ll s = 0;
    forn(i,n) if (used[i]) s += a[i];

    for (ll j = 0; j < n; j++) {

//      v64 u = used;

      ll p = (j - 1);
      ll c = j;
      ll ne = (j + 1);
      if (j == 0) p = n - 1;
      if (j == n - 1) ne = 0;

      ll S = s;
      if (used[p]) S -= a[p];
      if (used[c]) S -= a[c];
      if (used[ne]) S -= a[ne];

      ll ind = i;
      if (used[p]) ind -= (1 << p);
      if (used[c]) ind -= (1 << c);
      if (used[ne]) ind -= (1 << ne);

//      u[p] = 0;
//      u[c] = 0;
//      u[ne] = 0;



//      forn(z,n) if (u[z]) ind += (1 << z);

      mi = min(mi, dp[ind] + S);
    }

    dp[i] = mi;

  } cout << dp[(1 << n) - 1] << ln;

}