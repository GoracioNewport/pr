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

vv64 p, r;
v64 used;
v64 path;

void dfs(ll v) {
	used[v] = true;
	for (auto& u : p[v]) if (!used[u]) dfs(u);
	path.pb(v);
}

void dfsC(ll v, ll c) {
	used[v] = c;
	for (auto& u : r[v]) if (!used[u]) dfsC(u, c);
}

int main() {
  fast_cin();

  ll n, m;
  while (cin >> n >> m) {
    if (n == 0 && m == 0) break;
  	p.clear();
  	r.clear();
  	used.clear();
  	path.clear();


		p.resize(2 * n, v64());
		r.resize(2 * n, v64());
		used.resize(2 * n);

    vp64 e;

		forn(z,m) {
			ll i1, e1, i2, e2;
			// a || b  <>  !a -> b && !b -> a
			cin >> i1 >> e1 >> i2 >> e2; // (2 * i1 ^ (!e1)) or (2 * i2 ^ (!e2))
			ll a = (2 * i1) ^ (!e1);
			ll b = (2 * i2) ^ (!e2);

      e.pb({a ^ 1, b});
      e.pb({b ^ 1, a});
		} sort(all(e));
    e.erase(unique(all(e)), e.end());
    for (auto& i : e) {
      if (i.fi == i.se) continue;
      p[i.fi].pb(i.se);
      r[i.se].pb(i.fi);
    } forn(i,2 * n) if (!used[i]) dfs(i);
		forn(i, 2 * n) used[i] = 0;

    reverse(all(path));

    ll cnt = 1;
		for (auto& i : path) if (!used[i]) dfsC(i, cnt++);

		forn(i,n) {
			cout << (used[2 * i] > used[2 * i + 1] ? '0' : '1');
		} cout << ln;

  }


}
