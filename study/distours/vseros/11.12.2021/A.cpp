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

int main() {
  fast_cin();

  ll n, m, x, y, k;
  cin >> n >> m >> x >> y >> k;


  v64 X, Y;

  ll maxX = -INF, minX = INF, maxY = -INF, minY = INF;

  for (ll i = 1; i <= n; i++) {
    ll j = i + k - 1;
    if (i <= x && j >= x && j <= n) X.pb(i);
  } for (ll i = 1; i <= m; i++) {
    ll j = i + k - 1;
    if (i <= y && j >= y && j <= m) Y.pb(i);
  } for (auto& i : X) {
    maxX = max(maxX, i);
    minX = min(minX, i);
  } for (auto& i : Y) {
    maxY = max(maxY, i);
    minY = min(minY, i);
  } maxX += k - 1;
  maxY += k - 1;


  bool cornored = ((x == 1 && y == 1) || (x == 1 && y == m) || (x == n && y == 1) || (x == n && y == m));

  bool allLeft = (maxY == y);
  bool allRight = (minY == y);
  bool allUp = (maxX == x);
  bool allDown = (minX == x);

  if (n < m) { // n > m
    swap(n, m);
    swap(x, y);
  }


//  if ((x == 1 || x == n || y == 1 || y == m) && m < k) cout << k - 1 << ln;
//  cout << k << ln;


  if (sz(X) + sz(Y) <= 1) cout << k - 1 << ln;
  else cout << k << ln;
//  if (cornored || (m < k && x != 1 && x != n)) cout << k << ln;
//  else cout << k + 1 << ln;










}