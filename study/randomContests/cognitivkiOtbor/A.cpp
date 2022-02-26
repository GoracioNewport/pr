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

  ll ans = 0;
  for (ll a = 0; a < 12; a++) {
    for (ll b = 0; b < 12; b++) {
      for (ll c = 0; c < 12; c++) {
        if (a == b || b == c || a == c) continue;
        if ((a % 3) == (b % 3) || (b % 3) == (c % 3) || (c % 3) == (a % 3)) continue;
        v64 q = {a, b, c};
        sort(all(q));
        ll i = q[0];
        ll j = q[1];
        ll k = q[2];
        ld A = 180.0 * ((ld)(j - i) / 12.0);
        ld B = 180.0 * ((ld)(k - j) / 12.0);
        ld C = 180.0 * ((ld)((i + 12) - k) / 12.0);
        if (max(A, max(B, C)) < 90.0) ans++;
        cout << A << ' ' << B << ' ' << C << ln;
      }
    }
  } cout << ans << ln;

}