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

ll mod = 1e9 + 7;
ll timer = 0;

vvp64 p;
v64 used, tin, fup, dis, P;

void dfsBridge(ll v, ll pr = -1) {
	used[v] = true;
	tin[v] = fup[v] = timer++;
	for (auto& z : p[v]) {
		ll u = z.fi;
		if (pr == u) continue;
		if (used[u]) fup[v] = min(fup[v], tin[u]);
		else {
			dfsBridge(u, v);
			fup[v] = min(fup[v], fup[u]);
			if (fup[u] > tin[v]) {
				// cout << v << ' ' << u << ln;
				dis[z.se] = 1;
				dis[(z.se % 2 ? z.se - 1 : z.se + 1)] = 1;
			}
		}
	}
}

ll dfs(ll v, ll c) {
	ll ans = 1;
	used[v] = c;
	for (auto& u : p[v]) {
		if (used[u.fi] != c && !dis[u.se]) ans += dfs(u.fi, c);
	} return ans;
}

int main() {
  fast_cin();

  ll n, m;
  cin >> n >> m;
  p.resize(n, vp64());
  used.resize(n, 0);
  tin.resize(n, 0);
  fup.resize(n, INF);
  dis.resize(2*m, 0);
  P.resize(n, 0);

  forn(z,m) {
  	ll x, y;
  	cin >> x >> y;
  	x--; y--;
  	p[x].pb({y,2*z});
  	p[y].pb({x,2*z+1});
  	P[x]++;
  	P[y]++;
  }

  dfsBridge(0);
  forn(i,n) used[i] = 0;
  ll offset = 0;
  forn(i,n) {
  	if (used[i] != 0) continue;
  	ll x = dfs(i, i + 1);
  	if (x == 1 && P[i] >= 2) {
  		// cout << i << ln;
  		offset++;
  	}
  } unordered_map <ll, ll> c;
  for (auto& i : used) c[i]++;
  ll ans = 1;
	ll cnt = 0;
	for (auto& i : c) {
		cnt++;
		ans = (ans * i.se) % mod;
	} cout << cnt - offset << ' ' << ans << ln;
	// cout << offset << ln;

}
