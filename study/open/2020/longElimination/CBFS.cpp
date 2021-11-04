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

ll s;
vvp64 p;
v64 len;

void dfs(ll v, ll d) {
  if (d < 0) return;
  // cout << "A\n";
  len[v] = d;
  for (auto &u : p[v]) if (len[u.fi] == INF && (d - u.se >= 0)) dfs(u.fi, d - u.se); 
}

int main() {
  fast_cin();

  ll n, m, k;
  cin >> n >> m >> k >> s;
  p.resize(n, vp64());
  v64 z(n, 0);
  v64 used(n, 0);
  len.resize(n, INF);
  forn(i,m) {
    ll x, y, w;
    cin >> x >> y >> w;
    x--;
    y--;
    p[x].pb({y,w});
    p[y].pb({x,w});
  } forn(i,k) {
    ll a;
    cin >> a;
    a--;
    z[a] = 1;
  } 

  if (k == 1) {
    priority_queue <pair <ll, ll>> q; // <weight, ind>
    q.push({ 0, 0 });
    len[0] = 0;
    while (!q.empty()) {
      auto i = q.top();
      ll v = i.se;
      q.pop();
      if (used[v]) continue;
      used[v] = true;
      for (auto &i : p[v]) {
        auto u = i.fi;
        auto w = i.se;
        if (len[u] > len[v] + w) {
          len[u] = len[v] + w;
          q.push({ -len[u], u });
        }
      }
    } // for (auto &i : len) cout << i << ' ';
  } else {
    deque <ll> q;
    q.push_back(0);
    len[0] = 0;
    while (!q.empty()) {
      ll v = q.front();
      q.pop_front();
      if (len[v] > s) continue; 
      if (z[v]) len[v] = 0;

      for (auto &u : p[v]) {
        if (len[u.fi] > len[v] + u.se) {
          len[u.fi] = len[v] + u.se;
          if (z[u.fi]) q.push_front(u.fi);
          else q.push_back(u.fi);
        }
      }
    } 
  } vector <ll> ans;
  // for (auto &i : len) cout << i << ' ';
  // cout << endl;
  for(int i = 0; i < n; i++) if (len[i] <= s) ans.pb(i);
  sort(all(ans));
  cout << sz(ans) << endl;
  for (auto &i : ans) cout << i + 1 << ' ';
  cout << endl;

}
