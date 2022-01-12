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

ll subhash(ll l, ll r) {
  return ((h[r + 1] - ((h[l] * ks[r - l + 1]) % mod) + mod) % mod);
}

int main() {
  fast_cin();

  ll n;
  string s;
  bool good = true;
  cin >> n >> s;
  if (n % 2 == 0) good = false;

  ll cnt = 0;

  h.resize(n + 1, 0);
  ks.resize(n + 1, 1);
  forn(i,n) {
    ks[i + 1] = (ks[i] * k) % mod;
    ll x = (s[i] - 'a' + 1);
    h[i + 1] = (h[i] * k + x) % mod;
  }

  bool uniq = true;
  string sample;
  ll sHash = -1;
  ll m = n / 2;

  forn(i,n) {
    if (!good || !uniq) break;
    ll x, y;
    if (i < m) {
      ll x1 = subhash(0, i - 1);
      ll x2 = subhash(i + 1, m);
      x = (x1 * ks[m - (i + 1) + 1] + x2) % mod;
      y = subhash(m + 1, n - 1);
    } else if (i > m) {
      x = subhash(0, m - 1);
      ll y1 = subhash(m, i - 1);
      ll y2 = subhash(i + 1, n - 1);
      y = (y1 * ks[(n - 1) - (i + 1) + 1] + y2) % mod;
    } else if (i == m) {
      x = subhash(0, m - 1);
      y = subhash(m + 1, n - 1);
    } if (x == y) {
      if (sHash == -1) {
        sHash = x;
        if (i < m) sample = s.substr(m + 1);
        else sample = s.substr(0, m);
      } else {
        if (sHash != x) uniq = false;
      }
    } // cout << i << ' ' << x << ' ' << y << ln;
  } if (sHash == -1) good = false;

  if (!good) cout << "NOT POSSIBLE" << ln;
  else if (!uniq) cout << "NOT UNIQUE" << ln;
  else cout << sample << ln;




}