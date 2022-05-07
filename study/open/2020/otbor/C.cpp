// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
// #pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

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

ll n, m, k;
v64 used;
v64 q;
vvp64 p;
v64 z;

void dfs(ll v, ll s) {
	// cout << "AAAA " << v << endl;
	if (s <	0) return;
	if (used[v] != -1 && used[v] >= s) return;
	if (z[v]) q.pb(v);
	used[v] = s;
	for (auto &i : p[v]) {
		if (used[i.fi] == -1 || ((s - i.se) > used[i.fi]) && used[i.fi] >= 0) dfs(i.fi, s - i.se);
	}
}


int main() {
    fast_cin();
    ll s;
    cin >> n >> m >> k >> s;
    p.resize(n, vp64 (0));
    used.resize(n, -1);
    z.resize(n, 0);

    forn(i,m) {
    	ll x, y, w;
    	cin >> x >> y >> w;
    	x--;
    	y--;
    	p[x].pb({y,w});
    	p[y].pb({x,w});
    } q.pb(0);
    forn(i,k) {
    	ll a;
    	cin >> a;
    	a--;
    	z[a] = 1;
    } while (!q.empty()) {
    	// cout << sz(q) << endl;
    	// for (auto &i : q) cout << i + 1 << ' ';
    	// cout << endl;
    	v64 qCopy = q;
    	q.clear();
    	for (auto &i : qCopy) {
    		dfs(i, s);
    	}
    } v64 ans;
    forn(i,n) if (used[i] != -1) ans.pb(i);
    // for (auto &i : used) cout << i << ' ';
    // cout << ln;
    sort(all(ans));
    cout << sz(ans) << ln;
    for (auto &i : ans) cout << i + 1 << ' ';
    cout << ln;
}