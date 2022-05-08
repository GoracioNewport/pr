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

int main() {
  fast_cin();

  ll n, s, f;
  cin >> n >> s >> f; s--; f--;

  vvp64 p(n, vp64());

  forn(i,n) {
    forn(j,n) {
      ll x; cin >> x;
      if (i == j || x == -1) continue;
      p[i].pb({j, x});
//      p[j].pb({i, x});
    }
  }

  v64 dist(n, INF);
  dist[s] = 0;

  priority_queue <p64> q; // { -dist, vertex }
  q.push({0, s});

  while(!q.empty()) {
    ll v = q.top().se, curD = -q.top().fi;
    q.pop();

    if (dist[v] < curD) continue;

    for (auto &y : p[v]) {
      ll x = y.se;
      ll u = y.fi;
      if (dist[v] + x < dist[u]) {
        dist[u] = dist[v] + x;
        q.push({-dist[u], u});
      }
    }

  } cout << (dist[f] == INF ? -1 : dist[f]) << ln;

}