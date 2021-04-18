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
  
  ll n, m, s, t;
  cin >> n >> m >> s >> t;
  vvp64 p(n, vp64 (0));
  v64 pr(n, -1);
  s--;
  t--;
  forn(i,m) {
    ll x, y, w;
    cin >> x >> y >> w;
    x--;
    y--;
    p[x].pb({y, w});
    p[y].pb({x, w});
  } priority_queue <pair <ll, ll>> q;
  vector <ll> used(n, 0);
  vector <ll> len(n, INF);
  len[s] = 0;
  q.push({ 0, s});
  while (!q.empty()) {
    ll v = q.top().se;
    q.pop();
    if (used[v]) continue;
    used[v] = true;
    for (auto &i : p[v]) {
      auto u = i.fi;
      auto w = i.se;
      if (len[u] > len[v] + w) {
        len[u] = len[v] + w;
        pr[u] = v;
        q.push({ -len[u], u });
      }
    }
  } if (len[t] != INF) {
    v64 ans;
    cout << len[t] << endl;
    while (s != t) {
      ans.pb(t);
      t = pr[t];
    } ans.pb(s);
    reverse(ans.begin(), ans.end());
    for (auto &i : ans) cout << i + 1 << ' ';
    cout << endl;
  } else cout << -1 << endl;
  

}
