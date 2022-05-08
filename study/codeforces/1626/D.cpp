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
  v64 leadPower(2e5 + 1, 0);
  ll x = 1;

  forn(i,2e5 + 1) {
    leadPower[i] = x - i;
    if (i == x) x *= 2;
  }

  while(t--) {
    ll n;
    cin >> n;
    v64 a(n);
    for (auto& i : a) cin >> i;
    sort(all(a));


    v64 b;
    ll buf = 1;
    forn(i,n - 1) {
      if (a[i + 1] != a[i]) {
        b.pb(buf);
        buf = 1;
      } else buf++;
    } if (buf) b.pb(buf);

    v64 d = {0};
    partial_sum(all(b), back_inserter(d));

    n = sz(b);

    ll ans = INF;

    for (ll l1 = 0; l1 <= 40; l1++) {
      for (ll l2 = 0; l2 <= 40; l2++) {
        ll l = 0;
        ll r = n;
        while(l + 1 < r) {
          ll m = (l + r) / 2;
          if (d[m] <= (1 << l1)) l = m;
          else r = m;
        } ll x = l;

        l = x;
        r = n;
        while(l + 1 < r) {
          ll m = (l + r) / 2;
          if (d[m] - d[x] <= (1 << l2)) l = m;
          else r = m;
        } ll y = l;

        ll A = d[x];
        ll B = d[y] - d[x];
        ll C = d.back() - d[y];

        ans = min(ans, leadPower[A] + leadPower[B] + leadPower[C]);
      }
    } cout << ans << ln;

  }

}