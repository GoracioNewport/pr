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
  ll x = 0, y = 0;
  vv64 a(n, v64(m));
  vv64 used(n, v64(m));
  for (auto &i : a) {
    for (auto &j : i) cin >> j;
  }
  ll t;
  cin >> t; t--;
  ll ans = a[0][0];
  used[0][0] = 1;
  while(t--) {
    ll X;
    cin >> X;
    if (X == 1) y++;
    if (X == 2) x--;
    if (X == 3) y--;
    if (X == 4) x++;
    if (!used[x][y]) ans += a[x][y];
    used[x][y] = 1;
  } cout << ans << ln;

//  for (auto &i : used) {
//    for (auto &j : i) cout << j << ' ';
//    cout << ln;
//  }

}