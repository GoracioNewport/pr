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

ll mod = 1791791791, k = 239;

v64 h, ks;

ll subHash(ll l, ll r) {
  return ((h[r] - ((h[l] * ks[r - l]) % mod) + mod) % mod);
}

int main() {
  fast_cin();

  string s;
  cin >> s;
  ll n = sz(s);
  ks.resize(n + 1, 1);
  h.resize(n + 1, 0);

  forn(i,n) {
    ll x = (s[i] - 'a' + 1);
    ks[i + 1] = (ks[i] * k) % mod;
    h[i + 1] = (h[i] * k + x) % mod;
  }

  v64 q;

  for(ll len = 1; len <= n - 2; len++) {
    ll h1 = subHash(0, len);
    ll h2 = subHash(n - len, n);
    if (h1 == h2) q.pb(len);
  } ll l = -1;
  ll r = sz(q);

  while(l + 1 < r) {
    ll m = (l + r) / 2;
    ll h1 = subHash(0, q[m]);
    bool good = false;
    forsn(i, 1, n - q[m]) {
      ll h2 = subHash(i, i + q[m]);
      if (h1 == h2) good = true;
    } if (good) l = m;
    else r = m;
  } cout << (l == -1 ? "Just a legend" : s.substr(0, q[l])) << ln;




}