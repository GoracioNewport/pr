// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
// #pragma GCC optimize("unroll-loops")
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



int main() {
  fast_cin();
  
  ll n, m;
  cin >> n >> m;
  vvp64 p(n, vp64 (0));
  vv64 price(n, v64(n, 0));
  forn(i,m) {
    ll x, y, w, maxW;
    cin >> x >> y >> w >> maxW;
    x--;
    y--;
    p[x].pb({y, w});
    p[y].pb({x, w});
    price[x][y] = price[y][x] = maxW;
  }

  // for (auto &i : price) {
  //   for (auto &j : i) {
  //     cout << j << ' ';
  //   } cout << endl;
  // }

  ll l = 3e6;
  ll r = 1003000001;
  // ll r = 3000300;
  ll ans = -1;
  while (l + 1 < r) {
    ll ma = (l + r) / 2;
    // cout << ma << endl;
    // break;
    priority_queue <pair <ll,ll>> q;
    vector <ll> used(n, 0);
    vector <ll> len(n, INF);
    len[0] = 0;
    q.push({ 0, 0 });
    while (!q.empty()) {
      auto i = q.top();
      ll v = i.se;
      // cout << v << endl;
      q.pop();
      if (used[v]) continue;
      used[v] = true;
      for (auto &i : p[v]) {
        auto u = i.fi;
        auto w = i.se;
        // cout << v << ' ' << u << ' ' << price[v][u] << endl;
        if (ma > price[v][u]) continue;
        if (len[u] > len[v] + w) {
          // cout << "HI\n" << endl;
          len[u] = len[v] + w;
          q.push({ -len[u], u });
        }
      }
    } 
    
    // cout << ma << ' ' << len[n - 1] << endl;
    
    if (len[n - 1] <= 1440) l = ma;
    else r = ma;
    // cout << l << ' ' << r << endl;
  } ans = (ll)((l - 3e6) / 100);
  // cout << l << endl;
  cout << ans << endl;

}
