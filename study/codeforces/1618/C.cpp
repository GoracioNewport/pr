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

ll gcd(ll a, ll b) {
  if (b == 0) return a;
  else return gcd(b, a % b);
}

int main() {
  fast_cin();

  ll t;
  cin >> t;
  while(t--) {
    ll n;
    cin >> n;
    v64 a(n);
    for (auto& i : a) cin >> i;
    ll x = a[0];
    ll y = a[1];
    forsn(i,2,n) {
      if (i % 2 == 0) x = gcd(x, a[i]);
      else y = gcd(y, a[i]);
    } vector <bool> b(n), c(n);
    forn(i,n) {
      b[i] = (a[i] % x == 0);
      c[i] = (a[i] % y == 0);
    }

    bool goodB = true, goodC = true;
    forn(i,n - 1) {
      if (b[i] == b[i + 1]) goodB = false;
    } forn(i,n - 1) {
      if (c[i] == c[i + 1]) goodC = false;
    }

    if (goodB) cout << x << ln;
    else if (goodC) cout << y << ln;
    else cout << 0 << ln;
  }

}