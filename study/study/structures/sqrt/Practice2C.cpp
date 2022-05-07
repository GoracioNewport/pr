#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
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
  v64 a(n);
  for (auto &i : a) cin >> i;
  // ll len = sqrt(n - 1) + 1;
  // v64 d(len, -1);
  ll len = sqrt(n) + 1;
  v64 d(n / len + 1, -1);
  forn(i,n) d[i / len] = max(d[i / len], a[i]);
  while(q--) {
    ll t;
    cin >> t;
    if (t == 1) {
      ll i, x;
      cin >> i >> x;
      a[i] = x;
      d[i / len] = a[i];
      ll l = (i / len) * len;
      ll r = min(l + len, n - 1);
      // cout << l << ' ' << r << endl;
      for (ll j = l; j <= r; j++) d[i / len] = max(d[i / len], a[j]);
      // for (auto &i : d) cout << i << ' ';
      // cout << endl;
    } else {
      ll x;
      cin >> x;
      ll ind = -1;
      for (ll i = 0; i < sz(d); i++) {
        if (d[i] >= x) {
          ind = i;
          break;
        }
      } if (ind == -1) cout << -1 << ln;
      else {
        ll l = ind * len;
        ll r = min(l + len, n - 1);
        for (ll i = l; i <= r; i++) {
          if (a[i] >= x) {
            cout << i << ln;
            break;
          }
        }

      }
    }
  }


}
