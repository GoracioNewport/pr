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

v64 p, r;

void init(ll n) {
	p.resize(n);
	r.resize(n);
	forn(i,n) p[i] = i;
}

ll getV(ll v) {
	return v == p[v] ? v : p[v] = getV(p[v]);
}

void unite(ll a, ll b) {
	a = getV(a);
	b = getV(b);
	if (a == b) return;
	if (r[b] > r[a]) swap(a, b);
	if (r[a] == r[b]) r[a]++;
	p[b] = a; 
}
 
int main() {
  fastCin();
 
  freopen("b2.txt", "r", stdin);
  // freopen("a0ans.txt", "w", stdout);

  string st;
  getline(cin, st);
  ll t = stoll(st);

  forn(i,t) {
  	string s1, s2;
  	getline(cin, s1);
  	getline(cin, s2);
  
  	// cout << s1 << ' ' << s2 << ln;

  	vector <string> a, b, d;

  	string buf = "";
  	for (auto& c : s1) {
  		if (c == ' ') {
  			a.pb(buf);
  			b.pb(buf);
  			buf = "";
  		} else buf += c;
  	} 

  	// a.pb(buf);
  	// b.pb(buf);
  	buf = "";

  	for (auto& c : s2) {
  		if (c == ' ') {
  			a.pb(buf);
  			d.pb(buf);
  			buf = "";
  		} else buf += c;
  	} 

  	// a.pb(buf);
  	// d.pb(buf);
  	
  	buf = "";

  	sort(all(a));
  	a.erase(unique(all(a)), a.end());

  	map <string, ll> z;
  	forn(i,sz(a)) z[a[i]] = i;

  	init(sz(a));

  	v64 A, B;

  	for (auto& i : b) A.pb(z[i]);
  	for (auto& i : d) B.pb(z[i]);

  	// cout << A << ln << B << endl;
  	// cout << sz(a) << endl;

  	// cout << sz(b) << ' ' << sz(d) << endl;

  	forn(i,sz(A)) {
  		// cout << A[i] << ' ' << B[i] << endl;
  		unite(A[i], B[i]);
  	}
  	v64 cnt(sz(a));


  	forn(i,sz(a)) cnt[getV(z[a[i]])]++;

  	v64 ans;

  	for (auto& i : cnt) if (i > 1) ans.pb(i);
  	sort(all(ans));

  	cout << sz(ans) << ln << ans << ln;


  }
 
}

