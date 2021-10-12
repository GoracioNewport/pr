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

  ll x;
  cin >> x;
  vp64 ans;

//  ll t = chrono::high_resolution_clock::now().time_since_epoch().count();

  for (ll m = 1; m < 1e5; m++) {
    { // a = m, a < b
      ll a = m;
      ll b = (a + x) / (2 * a + 1);
      if (!(b < 0 || (a + x) % (2 * a + 1) != 0 || a >= b)) {
        ll y = 2 * a;
        if (x + y == a * (b + 1) + (a + 1) * b) ans.pb({a, b});
      }
    }
    { // b = m, b <= a
      ll b = m;
      ll a = (b + x - 1) / (2 * b + 1);
      if (!(b < 0 || (b + x - 1) % (2 * b + 1) != 0 || b > a)) {
        ll y = 2 * b - 1;
        if (x + y == a * (b + 1) + (a + 1) * b) ans.pb({a, b});
      }
    }
  } cout << sz(ans) << ln;
  for (auto &i : ans) cout << i.fi << ' ' << i.se << ln;

//  cout << chrono::high_resolution_clock::now().time_since_epoch().count() - t << ln;

}