// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
// #pragma GCC optimize("unroll-loops")
 
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
 
// Author: @GoracioNewport
 
using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<int> v32;
typedef vector<ll> v64;
typedef vector<ld> vdd;
typedef vector<v32> vv32;
typedef vector<v64> vv64;
typedef vector<vdd> vvdd;
typedef vector<p64> vp64;
typedef vector<vp64> vvp64;
 
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define ln "\n"
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define fastCin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
 
mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
 
istream& operator>>(istream& in, v64& a) {
  for (auto& i : a) in >> i;
  return in;
}
 
istream& operator>>(istream& in, vp64& a) {
  for (auto& i : a) in >> i.fi >> i.se;
  return in;
}
 
istream& operator>>(istream& in, vv64& a) {
  for (auto& i : a) for (auto& j : i) in >> j;
  return in;
}
 
istream& operator>>(istream& in, vvp64& a) {
  for (auto& i : a) for (auto& j : i) in >> j.fi >> j.se;
  return in;
}
 
ostream& operator<<(ostream& out, v64& a) {
  for (auto& i : a) out << i << ' ';
  return out;
}
 
ostream& operator<<(ostream& out, vp64& a) {
  for (auto& i : a) out << i.fi << ' ' << i.se << ln;
  return out;
}
 
ostream& operator<<(ostream& out, vv64& a) {
  for (auto& i : a) {
    for (auto& j : i) out << j << ' ';
    cout << ln;
  } return out;
}
 
ostream& operator<<(ostream& out, vvp64& a) {
  for (auto& i : a) {
    for (auto& j : i) out << j.fi << ' ' << j.se << ln;
    cout << ln;
  } return out;
}
 
ll mod = 1791791791;
ld eps = 1e-12;
ll INF = 2e18;

vvp64 p;
v64 used;

bool DEBUG = false;

ll solve(ll n, ll m, ll I, ll J, vp64& qs) {
	ll ans = 0;
	for (auto& x : qs) {
		v64 dist(n, INF);
		// dist[x.fi] = 0;
		deque <p64> q;
		q.push_front({x.fi, 0});

		while(!q.empty()) {
			ll v = q.front().fi;
			ll curD = q.front().se;
			q.pop_front();

			if (dist[v] <= curD) continue;
			dist[v] = curD;

			for (auto& [u, i] : p[v]) {
				if (i == I || i == J) q.push_back({u, curD + 1});
				else q.push_front({u, curD});
			}
		} 

		if (DEBUG) cout << dist << ln;

		ans += dist[x.se];
	} return ans;
}


int main() {
  fastCin();
 
  ll t, g;
  cin >> t >> g;
  
  while(t--) {
  	p.clear();
  	used.clear();

  	ll n, m;
  	cin >> n >> m;
  	
  	p.resize(n);
  	used.resize(n);
  	vp64 edges;

  	forn(i,m) {
  		ll x, y; cin >> x >> y; x--; y--;
  		p[x].pb({y, i});
  		p[y].pb({x, i});
  		edges.pb({x, y});
  	}

  	ll k;
  	cin >> k;
  	vp64 qs(k);
  	cin >> qs;
  	for (auto& i : qs) {
  		i.fi--; i.se--;
  	}

  	pair <ll, pair <p64, p64>> ans = {-INF, {{-1, -1}, {-1, -1}}};

  	forn(i,m) {
  		forn(j,m) {
  			if (i == j) continue;
  			ll locAns = solve(n, m, i, j, qs);

  			if (DEBUG) cout << i << ' ' << j << ' ' << locAns << ln;

  			if (locAns > ans.fi) ans = {locAns, {edges[i], edges[j]}};
			}	
  	} cout << ans.fi << ln << ans.se.fi.fi + 1 << ' ' << ans.se.fi.se + 1 << ln << ans.se.se.fi + 1 << ' ' << ans.se.se.se + 1 << ln;

  } 
	 
}

