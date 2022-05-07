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
v64 tin, fup, isBridge, used;

ll timer = 0, ans = 0;

void dfsBridge(ll v, ll P = -1) {
	tin[v] = fup[v] = ++timer;
	for (auto& [u, i] : p[v]) {
		if (u == P) continue;
		if (tin[u]) fup[v] = min(fup[v], tin[u]);
		else {
			dfsBridge(u, v);
			fup[v] = min(fup[v], fup[u]);
			if (fup[u] > tin[v]) isBridge[i] = true;
		}
	}
}

ll dfsAns(ll v, ll P = -1) {
	used[v] = true;
	ll fM = 0, sM = 0;
	for (auto& [u, i] : p[v]) {
		if (used[u]) continue;
		ll x = dfsAns(u, v);
		if (isBridge[i]) x++;
		if (x > fM) {
			sM = fM;
			fM = x;
		} else if (x > sM) sM = x;
	} ans = max(ans, fM);
	ans = max(ans, fM + sM);
	return fM;
}

int main() {
  fastCin();
 
	ll n, m;
	cin >> n >> m;
	p.resize(n);
	tin.resize(n);
	fup.resize(n);
	isBridge.resize(m);
	used.resize(n);

	forn(i,m) {
		ll x, y; cin >> x >> y; x--; y--;
		p[x].pb({y, i});
		p[y].pb({x, i});
	} dfsBridge(0);
	dfsAns(0);
	cout << ans << ln;
 
}

