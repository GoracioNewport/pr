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

vv64 p;
v64 used;

void dfs(ll v, ll c) {
  used[v] = c;
  for (auto &i : p[v]) if (!used[i]) dfs(i, c);
}

int main() {
  fast_cin();

  ll t;
  cin >> t;
  while(t--) {
    ll n, m, k;
    cin >> n >> m >> k;
    v64 path(k);
    for (auto &i : path) {
      cin >> i;
      i--;
    } p.clear();
    p.resize(n, v64());
    used.clear();
    used.resize(n, 0);
    forn(z,m) {
      ll x, y;
      cin >> x >> y; x--; y--;
      p[x].pb(y);
      p[y].pb(x);
    } forn(i,n) if (!used[i]) dfs(i, i + 1);
    v64 components;
    for (auto &i : path) components.pb(used[i]);
    sort(all(components));
    auto it = unique(components.begin(), components.end());
    components.erase(it, components.end());
    map <ll,ll> s;
    for (auto &i : used) s[i]++;
    map <ll,ll> eth;
    for (auto &i : components) eth[i] = s[i];
    map <ll,ll> ch;
    for (auto &i : path) ch[used[i]]++;
//    for (auto &i : eth) cout << i.fi << ' ' << i.se << ln;
//    cout << ln;
//    for (auto &i : ch) cout << i.fi << ' ' << i.se << ln;
    cout << (eth == ch ? "YES" : "NO") << ln;



  }

}