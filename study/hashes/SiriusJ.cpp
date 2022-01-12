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

struct block {
    v64 b;
    v64 h;
    ll seg;
    ll len;
    ll l;
    ll r;
};

v64 qs, qsum;
const ll mod = 1791791791, q = 239;

int main() {
  fast_cin();

  ll n;
  cin >> n;
  v64 a(n);
  for (auto &i : a) cin >> i;
  ll len = sqrt(n) + 1;
  vector <block> d(n / len + 1);
  qs.resize(n + 1, 1);
  qsum.resize(n + 2, 0);
  forn(i,n) qs[i + 1] = qs[i] * q % mod;
  forn(i,n + 1) qsum[i + 1] = qsum[i] + qs[i];
  forn(i,n) d[i / len].b.pb(a[i]);
  forn(i,sz(d)) {
    d[i].len = len;
    d[i].seg = INF;
    d[i].l = i * len;
    d[i].r = d[i].l + len - 1;
  } d.back().len = (n - (len * (sz(d) - 1)));
  d.back().r = d.back().l + d.back().len - 1;
  for (auto &i : d) {
    i.h.resize(n + 1, 0);
    forn(j,i.len) {
      ll x = (i.b[j] - 'a' + 1);
      i.h[j + 1] = ((i.h[j] * q) % mod + x) % mod;
    }
  } ll q;
  cin >> q;
  while(q--) {
    ll t, l, r, k;
    cin >> t >> l >> r >> k; l--; r--;
    if (t) {

    } else {
      for (ll i = l; i <= r;) {
        if (i % len == 0 && i + len <= (r + 1)) {

        }
      }
    }
  }
}