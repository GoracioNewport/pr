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
ll mod = 1791791791;
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

const ll k = 239;
ll n, m;
//v64 ks;
//vv64 h;

bool DEBUG = false;

int main() {
  fast_cin();


  cin >> n >> m;
  vector <string> s(n);
  for (auto &i : s) cin >> i;

//  ks.resize(m + 1, 1);
//  h.resize(n, v64 (m + 1, 0));
//  forn(i,m) ks[i + 1] = (ks[i] * k) % mod;
//  forn(i,n) {
//    forn(j,m) {
//      ll x = (s[i][j] - '?' + 1);
//      h[i][j + 1] = ((h[i][j] * k) + x) % mod;
//    }
//  }

  vector <map <string, ll>> has((1 << m), map <string, ll> ());
  for (auto &i : s) {
    for(ll j = 0; j < (1 << m); j++) {
      string c = i;
//      ll H = 0;

//      bool die = false;
//      forn(k, m) if ((j & (1 << k)) && (i[k] == '?')) die = true;
//      if (die) continue;

      forn(k, m) {
        if (j & (1 << k)) c[k] = '?';
//        ll x = (c[k] - '?' + 1);
//        H = ((H * k) + x) % mod;
      } has[j][c]++;
    }
  }

  ll ans = 0;

  for (auto &i : s) {
    ll msk = 0;
    forn(j,m) if (i[j] == '?') msk |= (1 << j);

    ll locAns = 0;

    if (DEBUG) cout << "Count: " << i << ln;

//    cout << i << ln;
//    cout << msk << ln;

    for(ll j = msk; j < (1 << m); j = (j + 1) | msk) {
//      cout << j << ln;
      string c = i;
//      ll H = 0;

      forn(k, m) {
        if (j & (1 << k)) c[k] = '?';
//        ll x = (c[k] - '?' + 1);
//        H = ((H * k) + x) % mod;
      } locAns += has[msk][c];
      if (DEBUG) {
        cout << "Mask: " << j << ln;
        cout << c << ln;
        cout << has[msk][c] << ln;
      }
    } ans += locAns - 1;
    if (DEBUG) cout << "Total: " << locAns << ln;
  } cout << ans / 2 << ln;

}