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

  ll t;
  cin >> t;
  while(t--) {
    bool good = true;
    ll n, m;
    cin >> n >> m;
//    bool p[n + 1][n + 1];
//    vector <vector <bool>> p(n, vector <bool> (n, 0));
//    forn(i,n) forn(j,n) p[i][j] = 0;
//    while(m--) {
//      ll x, y;
//      cin >> x >> y; x--; y--;
//      if (p[x][y] || p[y][x] || x == y) {
//        good = false;
//      }
//      p[x][y] = 1;
//      p[y][x] = 1;
//    }

    set <p64> p;
    while(m--) {
      ll x, y;
      cin >> x >> y; x--; y--;
      if (x == y) good = false;
      ll s = sz(p);
      p.insert({x,y});
      p.insert({y,x});
      if (sz(p) != s + 2) good = false;
    }
    cout << (good ? "YES" : "NO") << ln;
  }

}