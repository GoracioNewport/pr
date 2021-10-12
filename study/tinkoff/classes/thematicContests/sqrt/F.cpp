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
  v64 a(n);
  ll len = sqrt(m) * 2;
  for (auto &i : a) cin >> i;
  v64 d(n);
  ll ans = 0;
  vp64 Q(m);
  vv64 p(n, v64()), h(n, v64());
  vv64 has(n, v64());
  ll maxN = 1e5 + 1;

  forn(i,m) {
    cin >> Q[i].fi >> Q[i].se; Q[i].fi--; Q[i].se--;
    ll x = Q[i].fi, y = Q[i].se;
    d[x]++; d[y]++;
  } forn(i,n) {
    if (d[i] >= len) has[i].resize(maxN + 1, 0);
  } forn(i,m) {
    ll x = Q[i].fi, y = Q[i].se;
    if (a[x] != a[y]) ans += 2;

    if (d[x] >= len) {
      h[y].pb(x);
      has[x][a[y]]++;
    } else p[y].pb(x);
    if (d[y] >= len) {
      h[x].pb(y);
      has[y][a[x]]++;
    } else p[x].pb(y);
  }

//  for (auto &i : has) {
//    for (auto &j : i) cout << j << ' ';
//    cout << ln;
//  }
//
//  for (auto &i : d) cout << i << ' ';
//  cout << ln;

//  v64 heavyV;
//  forn(i,n) if (d[i] >= len) heavyV.pb(i);

  ll q;
  cin >> q;
  while(q--) {
    ll c, v;
    cin >> c >> v; c--;
    ll prev = a[c];
    a[c] = v;



    if (d[c] >= len) {
//      cout << "Heavy vertex" << endl;
      for (auto &i : h[c]) {
        has[i][prev]--;
        has[i][v]++;
      }

      ans -= (d[c] - has[c][prev]) * 2;
      ans += (d[c] - has[c][v]) * 2;

//      ans -= has[c][prev] * 2;
//      ans += has[c][v] * 2;


    } else {
//      cout << "Light vertex" << endl;
      for (auto &i : h[c]) {
        if (a[i] != prev) ans -= 2;
        if (a[i] != v) ans += 2;
        has[i][prev]--;
        has[i][v]++;
      } for (auto &i : p[c]) {
        if (a[i] != prev) ans -= 2;
        if (a[i] != v) ans += 2;
      }
    }

//    for (auto &i : has) {
//      for (auto &j : i) cout << j << ' ';
//      cout << ln;
//    }



    cout << ans / 2 << ln;

  }

}