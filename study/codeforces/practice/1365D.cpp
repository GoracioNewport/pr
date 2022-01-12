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

bool ans;
vector <vector <char>> p;
vv64 used;

vp64 moves = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

ll n, m;

bool valid(ll x, ll y) {
  return (x >= 0 && x < n && y >= 0 && y < m);
}

void dfs(ll x, ll y) {
  used[x][y] = 1;
  for (auto &k : moves) {
    if (!valid(x + k.fi, y + k.se)) continue;
    if (!used[x + k.fi][y + k.se] && p[x + k.fi][y + k.se] != '#') dfs(x + k.fi, y + k.se);
  }
}

int main() {
  fast_cin();

  ll t;
  cin >> t;
  while(t--) {
    cin >> n >> m;

    p.clear();
    used.clear();

    p.resize(n, vector <char> (m));
    used.resize(n, v64 (m));
    ans = true;

    vector <pair <ll, ll>> q;


    forn(i,n) {
      forn(j,m) {
        cin >> p[i][j];
      }
    }
    forn(i,n) {
      forn(j,m) {
        if (p[i][j] == 'G') q.pb({i,j});
        if (p[i][j] == 'B') {
          for (auto &k : moves) {
            if (!valid(i + k.fi, j + k.se)) continue;
            if (p[i + k.fi][j + k.se] == 'G') ans = false;
            if (p[i + k.fi][j + k.se] != 'B') p[i + k.fi][j + k.se] = '#';
          }
        }
      }
    }

//    for (auto &i : p) {
//      for (auto &j : i) cout << j;
//      cout << ln;
//    }

    if (p[n - 1][m - 1] != '#') dfs(n - 1, m - 1);
    for (auto &i : q) {
      if (!used[i.fi][i.se]) ans = false;
    } cout << (ans ? "Yes" : "No") << ln;


  }

}
