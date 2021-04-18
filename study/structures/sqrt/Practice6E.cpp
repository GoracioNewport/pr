// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

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
  
  ll n, q;
  cin >> n >> q;
  v64 a(n, 0);
  ll len = sqrt(n) + 1;
  // cout << len << ln;
  v64 sig(n / len + 1, 0);
  sig.back() = INF;
  v64 Min(n / len + 1, 0);  
  while(q--) {
    ll t, l, r;
    cin >> t >> l >> r; r--;
    if (t == 1) {
      ll x;
      cin >> x;
      for(ll i = l; i <= r;) {
        if (i % len == 0 && i + len <= (r + 1)) {
          sig[i / len] = x;
          Min[i / len] = x;
          i += len;
        } else {
          if (i == l || i == (r / len) * len) {
            ll l1 = (i / len) * len;
            ll r1 = min(l1 + len, n);
            // cout << l1 << ' ' << r1 << ln;
            // cout << sig[i / len] << ln;
            ll newMin = INF;
            if (sig[i / len] == INF) {
              forsn(i,l1,r1) if (i < l || i > r) newMin = min(newMin, a[i]);
              // cout << "SHIT" << ln;
            } else {
              // cout << "-------" << ln;
              // cout << INF << ' ' << sig[i / len] << ' ' << (sig[i / len] == INF) << ln;
              // cout << "-------" << ln;
              // cout << "aaaaaa " << sig[i / len] << ln;
              forsn(i,l1,r1) a[i] = sig[i / len];
              newMin = sig[i / len];
            } newMin = min(newMin, x);
            // cout << newMin << ln;
            Min[i / len] = newMin;
            sig[i / len] = INF;
          } a[i] = x;
          i++;
        }
      } 
      // for (auto &i : a) cout << i << ' ';
      // cout << endl;
      // for (auto &i : sig) cout << i << ' ';
      // cout << endl;
      // for (auto &i : Min) cout << i << ' ';
      // cout << endl;
    } else {
      ll ans = INF;
      for(ll i = l; i <= r;) {
        if (i % len == 0 && i + len <= r) {
          ans = min(ans, Min[i / len]);
          i += len;
        } else {
          if (sig[i / len] == INF) ans = min(ans, a[i]);
          else ans = min(ans, sig[i / len]);
          i++;
        }
      } cout << ans << ln;
    }
  }

}
