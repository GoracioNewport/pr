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

bool DEBUG = false;

const ll mod = 1791791791, k = 239;
v64 ks;

ll subHash(ll l, ll r, v64 &h) {
  return ((h[r] - ((h[l] * ks[r - l]) % mod) + mod) % mod);
}


int main() {
  fast_cin();

  ll n, k;
  cin >> n >> k;
  string s; cin >> s;

  vector <string> m(n);

  if (n > k) {
    n = k;
    s = s.substr(0, k);
  }

  string p = "";
  for (ll i = 0; i < n; i++) {
    p += s[i];
    while(sz(m[i]) < k) m[i] += p;
  } for (auto &i : m) i = i.substr(0, k);

  vv64 h(n, v64 (k + 1, 0));
  ks.resize(k + 1, 1);

  for (ll i = 0; i < n; i++) {
    ks[i + 1] = (ks[i] * k) % mod;
    for (ll j = 0; j < k; j++) {
      ll x = (m[i][j] - 'a' + 1);
      h[i][j + 1] = ((h[i][j] * k) + x) % mod;
    }
  }

  if (DEBUG) {
    for (auto &i : h) {
      for (auto &j : i) cout << j << ' ';
      cout << ln;
    }
  }

  string Max = "";
  forn(i,k) Max += "z";
  v64 hMax (k + 1, 0);

  for (ll i = 0; i < k; i++) {
    ll x = ('z' - 'a' + 1);
    hMax[i + 1] = (hMax[i] * k + x) % mod;
  }

  if (DEBUG) for (auto &i : m) cout << i << ln;

  for (ll i = 0; i < n; i++) {
    if (DEBUG) cout << "-------------" << ln;
    ll l = 0;
    ll r = k;
    while(l + 1 < r) {
      ll M = (l + r) / 2;
      if (subHash(0, M, hMax) == subHash(0, M, h[i])) l = M;
      else r = M;
    }

    if (DEBUG) {
      cout << "COMPARE: " << ln;
      cout << m[i] << ln;
      cout << Max << ln;
      cout << "IND: " << l << ln;
    }

    if (m[i][l] < Max[l]) {
      Max = m[i];
      hMax = h[i];
      if (DEBUG) cout << "NEW MIN: " << Max << ln;
    }
  } cout << Max << ln;



}