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



bool comp (p64& a, p64& b) {
  return a.se < b.se;
}

int main() {
  fast_cin();

  ll n, m;
  cin >> n >> m;
  vv64 p(n, v64()); // все соседи
  vp64 a(n), q;
  forn(i,n) a[i].fi = i;


  forn(i,m) {
    ll x, y;
    cin >> x >> y; x--; y--;
    p[x].pb(y);
    p[y].pb(x);
    a[x].se++;
    a[y].se++;
    q.pb({x, y});
  } sort(all(a), comp);


  v64 pToO(n); // Pos of d[i];
  forn(i,n) pToO[a[i].fi] = i;

//  for (auto &i : a) cout << i.fi << ln;
//  cout << ln;
//  for (auto &i : pToO) cout << i << ln;

  vv64 P(n, v64()); // все соседи справа

  forn(i,m) {
    ll x = q[i].fi;
    ll y = q[i].se;

    if (pToO[y] < pToO[x]) swap(x,y);
    P[x].pb(y);
  }

//  forn(i,n) {
//    cout << i << " - ";
//    for (auto &j : P[i]) cout << j << ' ';
//    cout << ln;
//  }

  v64 t(n, 0);
  ll ans = 0;
  forn(A, n) {

    for (auto& B : P[A]) t[B] = A + 1;
    for (auto& B : P[A]) {
      for (auto& C : P[B]) {
        if (t[C] == A + 1) ans++;
      }
    }
  } cout << ans << ln;

}