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

  ll t;
  cin >> t;
  while(t--) {
    ll n;
    cin >> n;
    vp64 a(n);
    bool haso = false;
    v64 b(n);
    v64 c(n);
    for (auto &i : b) cin >> i;
    for (auto &i : c) cin >> i;
    ll ind = 0;
    for (auto &i : a) {
      ll x = b[ind];
      ll y = c[ind++];
      i = {x,y};
      if (i.fi == 1 && i.se == 1) haso = true;
    } if (!haso) a.pb({1,1});
    sort(all(a));
    for (auto &i : a) i.fi -= i.se - 1;
    ll ans = 0; // fi - str, se - row
//    for (auto &i : a) cout << i.fi << ' ' << i.se << ln;
    forn(i, sz(a) - 1) {
      auto f = a[i];
      auto s = a[i + 1];
      if (f.fi == s.fi) {
        if (f.fi % 2) ans += (s.se - f.se);
        else ans += 0;
      }
      else {
        if (f.fi % 2 == 0 && s.fi % 2 == 0) ans += (s.fi - f.fi) / 2;
        if (f.fi % 2 == 1 && s.fi % 2 == 1) ans += (s.fi - f.fi) / 2;
        if (f.fi % 2 == 1 && s.fi % 2 == 0) ans += (s.fi - f.fi) / 2;
        if (f.fi % 2 == 0 && s.fi % 2 == 1) ans += (s.fi - f.fi) / 2 + 1;
      }
    } cout << ans << ln;
  }

}