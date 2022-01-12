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
  ll N = n + m - 1;
  v64 a(N), b(N);
  for (auto& i : a) cin >> i;
  for (auto& i : b) cin >> i;

  reverse(all(b));
  if (n == 1) {
    ll ans = 0;
    forn(i,N) ans += min(a[i], b[i]);
    cout << ans << ln;
    return 0;
  }

  vv64 diagonalA(n, v64 (m)), diagonalB(n, v64 (m));
  vvp64 cellsA(N, vp64()), cellsB(N, vp64());
  forn(i,n) {
    forn(j,m) {
      diagonalA[i][j] = i + j;
      diagonalB[i][j] = j - i + n - 1;
      cellsA[i + j].pb({i,j});
      cellsB[j - i + n - 1].pb({i,j});
    }
  }

//  for (auto& i : diagonalA) {
//    for (auto& j : i) cout << j << ' ';
//    cout << ln;
//  } cout << ln;
//
//  for (auto& i : diagonalB) {
//    for (auto& j : i) cout << j << ' ';
//    cout << ln;
//  } cout << ln;
//
//  for (auto& i : cellsA) {
//    for (auto& j : i) cout << j.fi << ' ' << j.se << ", ";
//    cout << ln;
//  } cout << ln;
//
//  for (auto& i : cellsB) {
//    for (auto& j : i) cout << j.fi << ' ' << j.se << ", ";
//    cout << ln;
//  } cout << ln;

  ll ans = INF;

  for (ll I = 0; I < (1 << N); I++) {
    v64 used(N);
    vv64 p(n, v64 (m));
    for (ll j = 0; j < N; j++) if ((1 << j) & I) used[j] = 1;
    ll s = 0;
    for (ll j = 0; j < N; j++) {
      if (used[j]) {
        s += a[j];
        for (auto& i : cellsA[j]) p[i.fi][i.se] = 1;
      }
    }

//    cout << I << ln;
//    for (auto& i : p) {
//      for (auto& j : i) cout << j << ' ';
//      cout << ln;
//    }

    v64 usedP(N, 0);
    forn(i,n) {
      forn(j,m) {
        if (p[i][j] == 0) usedP[diagonalB[i][j]] = 1;
      }
    } forn(i,N) if (usedP[i]) s += b[i];
    ans = min(ans, s); //cout << s << ln << ln;

  } cout << ans << ln;

}