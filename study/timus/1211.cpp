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

vv64 p;
v64 used;
bool cycle;

enum { WHITE, GRAY, BLACK };

void dfs(ll v) {
  used[v] = GRAY;
  for (auto &i : p[v]) {
    if (used[i] == GRAY) cycle = true;
    if (used[i] == WHITE) dfs(i);
  } used[v] = BLACK;
}

int main() {
  fast_cin();

  ll t;
  cin >> t;
  while(t--) {
    ll n;
    cin >> n;
    cycle = false;
    p.clear();
    used.clear();
    p.resize(n, v64());
    used.resize(n, WHITE);
    ll cntSelf = 0;
    forn(i,n) {
      ll x;
      cin >> x;
      if (x == 0) cntSelf++;
      else {
        x--;
        p[i].pb(x);
      }
    } forn(i,n) if(used[i] == WHITE) dfs(i);
    cout <<  ((cycle || (cntSelf != 1)) ? "NO" : "YES") << ln;
//    cout << cycle << ' ' << cntSelf << ln;
//    for (auto &i : used) cout << i << ' ';
//    cout << ln;

  }

}