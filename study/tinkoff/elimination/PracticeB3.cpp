#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

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
v64 c;

void dfs(ll v, ll color) {
  c[v] = color;
  for (auto &u : p[v]) if (c[u] == -1) dfs(u, !color);
}

int main() {
  fast_cin();
  
  ll n, m;
  cin >> n >> m;
  p.resize(n, v64());
  c.resize(n, -1);
  forn(i,n - 1) {
    ll x;
    cin >> x;
    x--;
    p[i + 1].pb(x);
    p[x].pb(i + 1);
  } ll favor = 0;
  // cout << "SHIT" << endl;
  dfs(0, 0);
  forn(i,m) {
    ll t;
    cin >> t;
    if (t == 1) {
      ll x, y;
      cin >> x >> y;
      x--;
      y--;
      if (c[x] != c[y]) cout << 0 << ln;
      else cout << favor << ln;
    } else {
      ll x;
      cin >> x;
      favor = favor ^ x;
      // cout << favor << endl;
    }
  }

}
