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
 
ll solveBishop(ll x1, ll y1, ll x2, ll y2, ll n) {
	if ((x1 + y1) % 2 != (x2 + y2) % 2) return INF;
	if (x1 == x2 && y1 == y2) return 0;
	if ((x1 - y1 == x2 - y2) || (x1 + y1 == x2 + y2)) return 1;
	else return 2;
}

bool valid(ll x, ll y, ll n) {
	return (x > 0 && y > 0 && x <= n && y <= n);
}

vp64 knightMoves = {{-2, -1}, {-1, -2}, {1, -2}, {-2, 1}, {-1, 2}, {2, -1}, {1, 2}, {2, 1}};

int main() {
  fastCin();

  freopen("a2.txt", "r", stdin);
  // freopen("a0ans.txt", "w", stdout);
 
  ll t;
  cin >> t;
  while(t--) {
  	ll n;
  	cin >> n;
  	ll x1, y1, x2, y2;
  	cin >> x1 >> y1 >> x2 >> y2;
  	if (x1 == y1 && x2 == y2) {
  		cout << 0 << ln;
  		continue;
  	}

  	if ((x1 + y1) % 2 == 0) {
  		ll ans = INF;
  		for (auto& c : knightMoves) {
  			if (valid(x1 + c.fi, y1 + c.se, n)) ans = min(ans, solveBishop(x1 + c.fi, y1 + c.se, x2, y2, n));
  		} if (ans == INF) cout << -1 << ln;
  		else cout << ans + 1 << ln;
  	} else cout << (solveBishop(x1, y1, x2, y2, n) == INF ? -1 : solveBishop(x1, y1, x2, y2, n)) << ln;
  }
	 
}

