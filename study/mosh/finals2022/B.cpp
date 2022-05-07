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

struct price {
	ll l1, r1, l2, r2, c;
	price(ll l1, ll r1, ll l2, ll r2, ll c): l1(l1), r1(r1), l2(l2), r2(r2), c(c) {};
};

bool comp(price& a, price& b) {
	if (a.l1 != b.l1) return a.l1 < b.l1;
	else return a.r1 < b.r1;
} 
 
int main() {
  fastCin();
 
	freopen("b2.txt", "r", stdin);
  freopen("b1ans.txt", "w", stdout);

  ll t;
  cin >> t;
  while(t--) {
  	ll n, m;
  	cin >> n >> m;

  	vvp64 g(n);
  	forn(i,m) {
  		ll x, y, c;
  		cin >> x >> y >> c; x--; y--;
  		g[x].pb({y, c});
  		g[y].pb({x, c});
  	} 

  	ll Q;
  	cin >> Q;

  	vector <price> p;

  	forn(i,Q) {
  		ll l1, r1, l2, r2, c;
  		cin >> l1 >> r1 >> l2 >> r2 >> c; l1--; r1--; l2--; r2--;
  		p.pb(price({l1, r1, l2, r2, c}));
  	} sort(all(p), comp);

  	ll s, f;
  	cin >> s >> f; s--; f--;
  	
  	priority_queue <p64> q;
  	v64 dist(n, INF);
  	dist[s] = 0;
  	q.push({0, s});

  	ll limit = 1e8;

    ll cnt = 0;

  	while(!q.empty()) {
  		ll v = q.top().se;
  		ll curD = q.top().fi;

      cnt++;

      if (cnt % 1000 == 0) cout << cnt << "/" << n << endl;

  		q.pop();

  		if (dist[v] < curD) continue; 

      v64 locDist(n, INF);

  		for (auto& [u, w] : g[v]) {
  			if (dist[u] > dist[v] + w) {
          locDist[u] = min(locDist[u], w);
  			}
  		}

  		for (auto& x : p) {
  			if (v >= x.l1 && v <= x.r1) {
  				ll w = x.c;
  				for (ll i = x.l2; i <= x.r2; i++) {
            locDist[i] = min(locDist[i], w);
  				}
  			}

  			if (v >= x.l2 && v <= x.r2) {
  				ll w = x.c;
  				for (ll i = x.l1; i <= x.r1; i++) {
            locDist[i] = min(locDist[i], w);
  				}
  			}
  		}

      forn(u,n) {
        if (locDist[u] == INF || dist[u] < dist[v] + locDist[u]) continue;
        dist[u] = dist[v] + locDist[u];
        if (q.size() < limit) q.push({dist[u], u}); 
        else {
          cout << "LIMIT REACHED" << endl;
          return 0;
        }
      } 

  	} cout << dist[f] << ln;
  }  
 
}

