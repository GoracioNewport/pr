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

vv64 p;
v64 used, fri, col;
bool good;

ll dfs(ll v, ll d) {
  used[v] = 1;
  if (fri[v]) return d / 2 - 1;
  ll m = -1;
  for (auto& u : p[v]) {
    if (!used[u]) m = max(m, dfs(u, d + 1));
  } //if (m == INF) return INF;

  if (m == 0) {
    col[v] = 1;
//    return INF;
  }
  return m - 1;
}

void dfsP(ll v, ll d) {
  used[v] = 1;
  if (col[v]) return;

  if (sz(p[v]) == 1 && d != -1) {
    good = true;
    return;
  } for (auto& u : p[v]) if (!used[u]) dfsP(u, v);
}

int main() {
  fast_cin();

  ll t;
  cin >> t;
  while(t--) {
    ll n, k;
    cin >> n >> k;

    p.clear();
    used.clear();
    fri.clear();
    col.clear();

    p.resize(n, v64());
    used.resize(n);
    fri.resize(n);
    col.resize(n);

    forn(i, k) {
      ll x;
      cin >> x; x--;
      fri[x] = 1;
      col[x] = 1;
    }

    forn(i,n - 1) {
      ll x, y;
      cin >> x >> y; x--; y--;
      p[x].pb(y);
      p[y].pb(x);
    } dfs(0, 0);

//    for (auto& i : col) cout << i << ' ';
//    cout << ln;

    forn(i,n) used[i] = 0;
    good = false;
    dfsP(0, -1);
    cout << (good ? "yEs" : "nO") << ln;

  }

}