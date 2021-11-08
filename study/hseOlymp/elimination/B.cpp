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

ll n, m, s, t;
vvp64 p;
v64 used;

ll ANS = INF;
v64 vAns;

void fullDfs(ll v, ll s) {
  if (v == t) {
    ANS = min(ANS, s);
    return;
  } used[v] = 1;
  for (auto&u : p[v]) {
    if (!used[u.fi]) fullDfs(u.fi, s + u.se);
  }
  used[v] = 0;
}

void cntDfs(ll v, ll s, v64& path) {
  if (v == t) {
    if (s != ANS || sz(path) <= sz(vAns)) return;
    vAns = path;
    return;
  } used[v] = 1;
  for (auto&u : p[v]) {
    if (!used[u.fi]) {
      path.pb(u.fi);
      cntDfs(u.fi, s + u.se, path);
      path.pop_back();
    }
  } used[v] = 0;
}

void solve10() {
  fullDfs(s, 0);
  v64 path;
  cntDfs(s, 0, path);
  cout << ANS << ln;
  cout << sz(vAns) - 1 << endl;
  vAns.pop_back();
  for(auto& i : vAns) cout << i + 1 << ' ';
}

void solveElse() {
  queue <ll> q;
  q.push(s);
  v64 P(n, -1);
  while(!q.empty()) {
    ll x = q.front();
    used[x] = 1;
    q.pop();
    for (auto& u : p[x]) {
      if (used[u.fi]) continue;
      P[u.fi] = x;
      q.push(u.fi);
    }
  } ll x = P[t];
  v64 ans;
  while(P[x] != -1) {
    ans.pb(x);
    x = P[x];
  } cout << sz(ans) + 1 << ln << sz(ans) << ln;


  for (auto& i : ans) cout << i + 1 << ' ';
}

int main() {
  fast_cin();

  cin >> n >> m >> s >> t; s--; t--;
  p.resize(n, vp64());
  used.resize(n);
  forn(i,m) {
    ll x, y, c;
    cin >> x >> y >> c; x--; y--;
    p[x].pb({y, c});
    p[y].pb({x, c});
  } if (n <= 10) solve10();
  else solveElse();
}