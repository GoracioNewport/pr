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
 
int main() {
  fastCin();
 
	ll n;
	cin >> n;
	string a, b;
	cin >> a >> b;
	if (a == b) {
		cout << "YES" << ln << 0 << ln;
		return 0;
	} bool hasZero = false, hasOne = false;
	for (auto& i : b) if (i == '0') hasZero = true;
	for (auto& i : a) if (i == '1') hasOne = true;

	if (!hasZero || !hasOne) {
		cout << "NO" << ln;
		return 0;
	}

	vector <pair <ll, p64>> ans;

	v64 aIndOne, aIndZer, bIndOne, bIndZer;

	forn(i,n) {
		if (a[i] == '0') aIndZer.pb(i);
		else aIndOne.pb(i);

		if (b[i] == '0') bIndZer.pb(i);
		else bIndOne.pb(i);
	} 

	forn(i,sz(aIndOne) - 1) {
		a[aIndOne[i]] = '0';
		ans.pb({aIndOne[i] + 1, {aIndOne[i] + 1, aIndOne[i] + 1}});
	} ans.pb({aIndOne.back() + 1, {1, n}});

	// a = "111....101...111"

	for(ll i = aIndOne.back() + 1; i < n - 1; i++) {
		ans.pb({i + 1, {i + 1, i + 1}});
	} if (aIndOne.back() + 1!= n) ans.pb({n, {aIndOne.back() + 1, n}});

	// a = "111.....10"

	ll curInd = bIndZer.back();

	for(ll i = curInd + 1; i < n - 1; i++) {
		ans.pb({i + 1, {i + 1, i + 1}});
	} if (curInd + 1 != n) ans.pb({curInd + 1, {curInd + 1, n}});

	// a = "1...101....1"

	forn(i,n) a[i] = '1';
	a[curInd] = '0';

	forn(i,n) {
		if (a[i] == '1' && b[i] == '0') ans.pb({i + 1, {i + 1, i + 1}});
	}

	cout << "YES" << ln;
	cout << sz(ans) << ln;

	for (auto& i : ans) cout << i.fi << ' ' << i.se.fi << ' ' << i.se.se << ln;
 
}

