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
v64 ks;

ll subHash(v64& h, ll l, ll r) { // [l, r)
  return ((h[r] - ((h[l] * ks[r - l]) % mod) + mod) % mod);
}

bool DEBUG = false;

int main() {
  fast_cin();

  string t;
  cin >> t;

  ll n = sz(t);

  v64 h(n + 1, 0);
  ks.resize(n + 1, 1);
  forn(i,n) {
    ks[i + 1] = (ks[i] * k) % mod;
    h[i + 1] = (h[i] * k + (t[i] - 'a' + 1)) % mod;
  }

  if (DEBUG) {
    for (auto& i : h) cout << i << ' ';
    cout << ln;
  }

  vector <unordered_map <ll, ll>> z((ll)1e5, unordered_map <ll, ll> ());

  ll m, Q;
  cin >> m >> Q;
  forn(Z,m) {
    string s;
    cin >> s;
    ll H = 0;
    forn(i,sz(s)) {
      H = (H * k + (s[i] - 'a' + 1)) % mod;
      z[i][H]++;
    }
  }

//  ll ind = 0;
//  for (auto& i : z) {
//    cout << ++ind << ln;
//    for (auto& j : i) {
//      cout << j.fi << ' ' << j.se << ln;
//    }
//  }

  for (ll len = 1; len <= Q; len++) {
    if (DEBUG) cout << "LEN: " << len << ln;
    ll ans = 0;
    for (ll i = 0; i < n - len + 1; i++) { // begin point of subtraction
      if (DEBUG) cout << 0 << ' ' << i << ' ' << i + len << ' ' << n << ln;
      ll H = (subHash(h, 0, i) * ks[n - (i + len)] + subHash(h, i + len, n)) % mod;
      if (DEBUG) cout << H << ln;
      ans = max(ans, z[n - len - 1][H]);
    } if (!DEBUG) cout << ans << ' ';
  }

}

//abcdef
//3 5
//abcefx
//abcdfab
//abcdf