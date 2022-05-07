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

  ll n, m;
  cin >> n >> m;
  vv64 a(n, v64(m));
  for (auto& i : a) for (auto& j : i) cin >> j;

  if (n != 2) {
    vp64 path;
    if (n % 2 && m % 2) {
      cout << -1 << ln;
      return 0;
    }


    if (n % 2) {
      for (ll i = n - 1; i >= 0; i--) path.pb({i, 0});
      for (ll j = 1; j < m - 1; j++) {
        if (j % 2) for (ll i = 0; i < n - 1; i++) path.pb({i,j});
        else for (ll i = n - 2; i >= 0; i--) path.pb({i,j});
      } for (ll i = 0; i < n; i++) path.pb({i,m - 1});
      for (ll j = m - 2; j > 0; j--) path.pb({n - 1, j});
    } else {
      for (ll j = 0; j < m; j++) path.pb({0, j});
      for (ll i = 1; i < n - 1; i++) {
        if (i % 2) for (ll j = m - 1; j > 0; j--) path.pb({i,j});
        else for (ll j = 1; j < m; j++) path.pb({i,j});
      } for (ll j = m - 1; j >= 0; j--) path.pb({n - 1, j});
      for (ll i = n - 2; i > 0; i--) path.pb({i, 0});
    } for (auto& i : path) {
      cout << i.fi + 1 << ' ' << i.se + 1 << ln;
    } return 0;
  }

  for (ll i = 0; i < m; i++) {
    { // Top -> right

      ll s = 0;
      ll good = true;
      vp64 path;
      for (ll j = i; j < m; j++) {
        s += a[0][j];
        path.pb({0,j});
        if (s < 0) good = false;
      } for (ll j = m - 1; j >= 0; j--) {
        s += a[1][j];
        path.pb({1,j});
        if (s < 0) good = false;
      } for (ll j = 0; j < i; j++) {
        s += a[0][j];
        path.pb({0,j});
        if (s < 0) good = false;
      }

      if (good) {
        for (auto& c : path) cout << c.fi + 1 << ' ' << c.se + 1 << ln;
        return 0;
      }

    }
    { // Top -> left
      ll s = 0;
      ll good = true;
      vp64 path;
      for (ll j = i; j >= 0; j--) {
        s += a[0][j];
        path.pb({0,j});
        if (s < 0) good = false;
      } for (ll j = 0; j < m; j++) {
        s += a[1][j];
        path.pb({1,j});
        if (s < 0) good = false;
      } for (ll j = m - 1; j > i; j--) {
        s += a[0][j];
        path.pb({0,j});
        if (s < 0) good = false;
      }

      if (good) {
        for (auto& c : path) cout << c.fi + 1 << ' ' << c.se + 1 << ln;
        return 0;
      }

    }
    { // Bottom -> right
      ll s = 0;
      ll good = true;
      vp64 path;
      for (ll j = i; j < m; j++) {
        s += a[1][j];
        path.pb({1,j});
        if (s < 0) good = false;
      } for (ll j = m - 1; j >= 0; j--) {
        s += a[0][j];
        path.pb({0,j});
        if (s < 0) good = false;
      } for (ll j = 0; j < i; j++) {
        s += a[1][j];
        path.pb({1,j});
        if (s < 0) good = false;
      }

      if (good) {
        for (auto& c : path) cout << c.fi + 1 << ' ' << c.se + 1 << ln;
        return 0;
      }
    }
    { // Bottom -> left
      ll s = 0;
      ll good = true;
      vp64 path;
      for (ll j = i; j >= 0; j--) {
        s += a[1][j];
        path.pb({1,j});
        if (s < 0) good = false;
      } for (ll j = 0; j < m; j++) {
        s += a[0][j];
        path.pb({0,j});
        if (s < 0) good = false;
      } for (ll j = m - 1; j > i; j--) {
        s += a[1][j];
        path.pb({1,j});
        if (s < 0) good = false;
      }

      if (good) {
        for (auto& c : path) cout << c.fi + 1 << ' ' << c.se + 1 << ln;
        return 0;
      }
    }
  } cout << -1 << ln;

}