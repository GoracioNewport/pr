//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

// Author: @GoracioNewport
  
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

enum { WHITE, GRAY, BLACK };

ll ans = 0;
ll validSize = 0;
vv64 p;
v64 valid, used;

void dfs(ll v, ll d, ll P = -1) {
	used[v] = GRAY;
	for (auto& u : p[v]) {
		if (!valid[u] || u == P) continue;
		if (used[u] == GRAY && d == validSize - 1) ans++;
		if (used[u] == WHITE) dfs(u, d + 1, v); 
	} // 	used[v] = BLACK;
}


int main() {
  fast_cin();

  ll n, m;
  cin >> n >> m;
  p.resize(n, v64());
  used.resize(n);
  valid.resize(n);
  forn(i,m) {
  	ll x, y;
  	cin >> x >> y; x--; y--;
  	p[x].pb(y);
  	p[y].pb(x);
  }

  forsn(i,1,(1 << n)) {
  	ll ind = 0;
  	validSize = 0;
  	ll prevAns = ans;
  	forn(j,n) {
  		valid[j] = (i & (1 << j) > 0);
  		used[j] = WHITE;
  		if (i & (1 << j)) ind = j, validSize++;
  	} dfs(ind, 0);
  	ll curAns = ans - prevAns;
  	if (curAns) {
  		cout << i << ' ' << curAns << ln;
  	}
  } cout << ans << ln;

}
