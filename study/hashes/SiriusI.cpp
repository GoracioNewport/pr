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
ll mod = 1791791791;
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

const ll k = 239, q = 10559;

vector <string> s;
vv64 h;
v64 ks, qs;

ll subHash(ll x1, ll y1, ll x2, ll y2) {
	cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl;
	ll fullHash = h[x2 + 1][y2 + 1];
	ll oHash = ((h[x2 + 1][y1]) * ks[y2 - y1 + 1]) % mod; // слева
	ll tHash = ((h[x1][y2 + 1]) * qs[x2 - x1 + 1]) % mod; // сверху
	ll xHash = ((((h[x1][y1]) * ks[y2 - y1 + 1]) % mod) * qs[x2 - x1 + 1]) % mod; // слева сверху
	dbg(fullHash);
	dbg(oHash);
	dbg(tHash);
	dbg(xHash);
	return ((fullHash - oHash - tHash + xHash) + mod) % mod;
}

int main() {
  fast_cin();

  ll n, m;
  cin >> n >> m;
  s.resize(n);
  ks.resize(n + 1, 1);
  qs.resize(m + 1, 1);
  for (auto &i : s) cin >> i;
  h.resize(n + 1, v64 (m + 1, 0));
	forn(i,n) {
		ks[i + 1] = (ks[i] * k) % mod;
		forn(j,m) {
			if (i == 0) qs[i + 1] = (qs[i] * q) % mod;
			ll x = (s[i][j] - 'a' + 1);
			h[i + 1][j + 1] = (((h[i + 1][j] * k) % mod) + x) % mod;
			h[i + 1][j + 1] = (((h[i][j + 1] * q) % mod) + h[i + 1][j + 1]) % mod;
		}
	} 
	
	// for (auto &i : h) {
	// 	for (auto &j : i) cout << j << ' ';
	// 	cout << ln;
	// }

	pair <pair <ll,ll>, pair <ll,ll>> ans = {{-1,-1},{-1,-1}};
	ll maxAns = 0;

	ll l = 0;
	ll r = min(n,m) + 1;
	while(l + 1 < r) {
		ll M = (l + r) / 2;
		cout << M << endl;
		map <ll, pair <ll,ll>> p;
		bool ok = false;
		forn(i,n - M + 1) {
			forn(j,m - M + 1) {
				// cout << i << ' ' << j << endl;
				ll hash = subHash(i, j, i + M - 1, j + M - 1);
				if (p.find(hash) != p.end()) {
					if (M > maxAns) {
						maxAns = M;
						ans = {{i,j}, p[hash]};
					} ok = true;
				} else p[hash] = {i,j};
			} if (ok) break;
		} if (ok) l = M;
		else r = M;
	} cout << maxAns << ln;
	if (maxAns > 0) cout << ans.fi.fi + 1 << ' ' << ans.fi.se + 1 << ln << ans.se.fi + 1 << ' ' << ans.se.se + 1 << ln;
	

}
