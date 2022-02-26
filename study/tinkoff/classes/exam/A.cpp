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

vv64 p;
v64 mul;

pair <ll, p64> dfs(ll v) { // ans, min, max;
  if (mul[v]) return {0, {mul[v], mul[v]}};
  auto ansLeft = dfs(p[v][0]);
  auto ansRight = dfs(p[v][1]);

  if (ansLeft.fi == INF || ansRight.fi == INF) return {INF, {0, 0}};
  if (ansLeft.se.se == ansRight.se.fi - 1) return {ansLeft.fi + ansRight.fi, {ansLeft.se.fi, ansRight.se.se}};
  if (ansRight.se.se == ansLeft.se.fi - 1) return {ansLeft.fi + ansRight.fi + 1, {ansRight.se.fi, ansLeft.se.se}};
  return {INF, {0, 0}};

}

int main() {
  fast_cin();

  ll t;
  cin >> t;
  while(t--) {
    ll n;
    cin >> n;

    p.clear();
    mul.clear();
    p.resize(n, v64());
    mul.resize(n);

    ll cnt = 0;
    forn(i,n) {
      ll x, y; cin >> x >> y; x--; y--;
      if (x == -2) {
        mul[i] = y + 1;
        cnt++;
      }
      else {
        p[i].pb(x);
        p[i].pb(y);
      }
    } auto ans = dfs(0);

    if (ans.fi != INF && ans.se.fi == 1 && ans.se.se == cnt) cout << ans.fi << ln;
    else cout << -1 << ln;


  }

}