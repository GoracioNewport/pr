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

ll n, m;
vector <string> p;

bool valid(ll x, ll y) {
  return (x >= 0 && y >= 0 && x < n && y < m && p[x][y] == '.');
}

vp64 moves = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void dfs(p64 v, p64 P) {
  ll cnt = 0;
  for (auto& u : moves) if (valid(v.fi + u.fi, v.se + u.se) && mp(v.fi + u.fi, v.se + u.se) != P) cnt++;
  if (cnt > 1) return;
  for (auto& u : moves) if (valid(v.fi + u.fi, v.se + u.se) && mp(v.fi + u.fi, v.se + u.se) != P) dfs(mp(v.fi + u.fi, v.se + u.se), v);
  p[v.fi][v.se] = '+';
}

int main() {
  fast_cin();

  ll t;
  cin >> t;
  while(t--) {
    cin >> n >> m;
    p64 start;

    p.clear();
    p.resize(n);
    forn(i,n) {
      cin >> p[i];
      forn(j,m) if (p[i][j] == 'L') start = {i, j};
    } for (auto& i : moves) if (valid(start.fi + i.fi, start.se + i.se)) dfs(mp(start.fi + i.fi, start.se + i.se), mp(start.fi, start.se));
    for (auto& i : p) cout << i << ln;

  }

}