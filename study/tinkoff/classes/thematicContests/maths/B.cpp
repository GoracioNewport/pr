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

ll gcd(ll a, ll b, ll& x0, ll& y0) {
  if (a == 0) {
    x0 = 0;
    y0 = 1;
    return b;
  } ll x1, y1;
  ll d = gcd(b % a, a, x1, y1);
  x0 = y1 - (b / a) * x1;
  y0 = x1;
  return d;
}

int main() {
  fast_cin();

  ll a, b, c, x0, y0;
  cin >> a >> b >> c;
  ll g = gcd(a, b, x0, y0);
  if (c % g) {
    cout << "Impossible" << ln;
    return 0;
  } x0 = x0 * (c / g);
  y0 = y0 * (c / g);

  // x = x0 + k * (c / g);
  // y = y0 - k * (c / g);

//  cout << x0 << ' ' << y0 << ln;

  if (x0 > 0) {
    ll k = -(x0 / (b / g));
    cout << x0 + k * (b / g) << ' ' << y0 - k * (a / g) << ln;
  } else {
    ll k = ceil((ld)-x0 / (ld)(b / g));
    cout << x0 + k * (b / g) << ' ' << y0 - k * (a / g) << ln;
  }


}