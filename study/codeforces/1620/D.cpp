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

  ll t;
  cin >> t;
  while(t--) {
    ll n;
    cin >> n;
    v64 a(n);
    ll m = 0;
    for (auto& i : a) {
      cin >> i;
      m = max(m, i / 3);
    } ll ans = INF;
    for (ll i = max(0ll, m - 5); i <= m + 5; i++) {
      for (ll j = 0; j <= 3; j++) {
        for (ll k = 0; k <= 3; k++) {
          bool good = true;
          for (auto& Q : a) {

            bool found = false;
            for (ll x = 0; x <= j; x++) {
              for (ll y = 0; y <= k; y++) {
                ll left = Q - x - 2 * y;
                if (left >= 0 && left % 3 == 0 && (left / 3) <= i) found = true;
              }
            } if (!found) good = false;
          } if (good) {
            ans = min(ans, i + j + k);
//            if (ans == i + j + k) cout << i << ' ' << j << ' ' << k << ln;
          }
        }
      }
    } cout << ans << ln;
  }

}