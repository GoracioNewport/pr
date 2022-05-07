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

vv64 p, colors;
v64 used, carry;
ll cnt = 0, ans = 0;


bool DEBUG = false;

void dfs(ll v) {
  if (DEBUG) cout << ln << "ENTER " << v + 1 << ln;
  used[v] = 1;

  for (auto& c : colors[v]) {
    if (DEBUG) cout << "ADD " << c << ln;
    carry[c]++;
    if (carry[c] == 2) {
      if (DEBUG) cout << "DOUBLE! " << ln;
      cnt++;
    } if (DEBUG) for (auto& i : carry) cout << i << ' ';
    if (DEBUG) cout << ln;
  }


  for (auto& u : p[v]) {
    if (!used[u]) dfs(u);
  }


  if (DEBUG) cout << ln << "LEAVE " << v + 1 << ln;


  for (auto& c : colors[v]) {
    if (DEBUG) cout << "SUB " << c << ln;
    if (carry[c] == 2) {
      if (DEBUG) cout << "ZERO! " << ln;
    } carry[c]--;
    if (DEBUG) for (auto& i : carry) cout << i << ' ';
    if (DEBUG) cout << ln;
  }
}


int main() {
  fast_cin();

  ll n;
  cin >> n;
  p.resize(n, v64());
  used.resize(n, 0);
  colors.resize(n, v64());

  forn(i,n - 1) {
    ll x, y;
    cin >> x >> y;
    x--; y--;
    p[x].pb(y);
    p[y].pb(x);
  }

  ll q;
  cin >> q;
  carry.resize(q, 0);
  while(q--) {
    ll x, y;
    cin >> x >> y; x--; y--;
    colors[x].pb(q);
    colors[y].pb(q);
  }

  forn(i,n) {
    if (DEBUG) cout << "--- " << i << " ---" << ln;
    forn(j,n) used[j] = 0;
    used[i] = 1;
    for(auto& c : colors[i]) carry[c]++;
    for(auto& u : p[i]) {
      cnt = 0;
      dfs(u);
      ans = max(ans, cnt);
    } for(auto& c : colors[i]) carry[c]--;
  } cout << ans << ln;

}