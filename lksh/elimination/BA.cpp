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

ll n, k;
v64 pr; // предок i
vv64 p; // дети i
vp64 d;
ll ans = 0;
v64 used;

void cntDfs(ll v, ll depth) {
  d.pb({depth, v});
  for (auto &u : p[v]) cntDfs(u, depth + 1);
}

void pushDfs(ll v, ll x) {
  if (used[v]) return;
  used[v] = 1;
  if (x == 0) return;
  for (auto &u : p[v]) pushDfs(u, x - 1);
}

void linkDfs(ll v, ll x) {
  if (v == 0) {
    pushDfs(v, k - 1);
    return;
  }

  if (x == 0) {
    if (pr[v] == 0) return;
    pushDfs(v, k - 1);
    ans++;
    return;
  } linkDfs(pr[v], x - 1);
}

int main() {
  fast_cin();

  cin >> n >> k;
  pr.resize(n);
  used.resize(n, 0);
  pr[0] = -1;
  p.resize(n, v64());
  forn(i,n) {
    ll x;
    cin >> x;
    if (i == 0 && x != 1) ans++;
    else if (i != 0) {
      pr[i] = x - 1;
      p[x - 1].pb(i);
    }
  } cntDfs(0, 0);
  sort(all(d));
  reverse(all(d));
  forn(i,n) {
    ll x = d[i].se;
    if (used[x]) continue;
    linkDfs(x, k - 1);
  } cout << ans << ln;



}