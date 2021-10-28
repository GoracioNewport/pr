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
vv64 p;
vv64 used, ans;

bool fail;

vp64 moves = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

bool valid(ll i, ll j) {
  return (i >= 0 && j >= 0 && i < n && j < m);
}

void dfs(ll v, ll i, ll j, ll x) {
  used[i][j] = v;
  if (i == 0 || j == 0 || i == n - 1 || j == m - 1 || ans[i][j] == -1) fail = true;
  if (fail) return;

  for (auto& c: moves) {
    if (valid(i + c.fi, j + c.se) && p[i + c.fi][j + c.se] < x && used[i + c.fi][j + c.se] != v) dfs(v, i + c.fi, j + c.se, x);
  }
}

void dfsAns(ll v, ll i, ll j, ll x) {
  used[i][j] = v;
  ans[i][j] = x;
  for (auto& c: moves) {
    if (valid(i + c.fi, j + c.se) && p[i + c.fi][j + c.se] < x && used[i + c.fi][j + c.se] != v) dfs(v, i + c.fi, j + c.se, x);
  }
}

void dfsFill(ll v, ll i, ll j, ll x) {
  used[i][j] = v;
  ans[i][j] = -1;
  for (auto& c: moves) {
    if (valid(i + c.fi, j + c.se) && p[i + c.fi][j + c.se] < x && used[i + c.fi][j + c.se] != v) dfs(v, i + c.fi, j + c.se, x);
  }
}

bool DEBUG = false;

int main() {
  fast_cin();

  cin >> n >> m;
//  if (max(n, m) > 50) {
//    v64 Q(1e9);
//  }
  p.resize(n, v64 (m));
  used.resize(n, v64 (m, 0));
  ans.resize(n, v64 (m, 0));
  for (auto& i : p) for (auto& j : i) cin >> j;

  vector <pair <ll, p64>> c;

  for (ll i = 1; i < n - 1; i++) {
    for (ll j = 1; j < m - 1; j++) {
      c.pb({p[i][j], {i,j}});
    }
  } sort(all(c));

  ll cnt = 0;
  for (auto& i : c) {
    if (ans[i.se.fi][i.se.se] != 0) continue;
    ll l = i.fi;
    ll r = 1e9 + 1;

    if (DEBUG) cout << "---" << i.se.fi << ' ' << i.se.se << ln;

    while(l + 1 < r) {
      ll t = (l + r) / 2;
      fail = false;
      dfs(++cnt, i.se.fi, i.se.se, t);
      if (DEBUG) cout << t << ' ' << fail << ln;
      if (fail) r = t;
      else l = t;
    } if (DEBUG) cout << "ANS: " << l << ln;

    if (l != i.fi) dfsAns(++cnt, i.se.fi, i.se.se, l);
    else dfsFill(++cnt, i.se.fi, i.se.se, l);

  } ll ANS = 0;
  forn(i,n) {
    forn(j,m) {
      if (ans[i][j] > p[i][j]) ANS += (ans[i][j] - p[i][j]);
    }
  } cout << ANS << ln;


}

//3 6
//5 5 5 5 5 5
//1 2 1 3 1 4
//5 5 5 5 5 5