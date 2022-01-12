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

ll mod = 2222401062715751347;

int main() {
  fast_cin();

  string s;
  cin >> s;
  ll n = sz(s);
  v64 a(n);
  forn(i,n) a[i] = (s[i] - 'a');
  v64 z(26), h(n + 1);

  z[1] = 1;
  forsn(i,2,26) z[i] = (z[i - 1] * 2) % mod;
  forn(i,n) h[i + 1] = (h[i] + z[a[i]]) % mod;

  for(ll len = 1; len <= n; len++) {
    if (n % len) continue;
    ll H = h[len];
    bool good = true;
    for(ll j = 0; j < n; j += len) {
      ll x = (h[j + len] - h[j] + mod) % mod;
      if (H != x) good = false;
    } if (good) {
      cout << n / len << ln;
      return 0;
    }
  }

}