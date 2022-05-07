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
	v64 a(n);
	cin >> a;

	v64 cnt(2e6 + 1);
	for (auto& i : a) cnt[i]++;

	vp64 vals(2e6 + 1);
	forn(i,2e6 + 1) vals[i] = {cnt[i], i};
	sort(all(vals));
	reverse(all(vals));

	p64 max1 = vals[0]; // cnt, number
	p64 max2 = vals[1]; // cnt, number

	pair <p64, p64> ans = {{0, -1}, {-1, -1}}; // Total height, number of floors, height, width

	forn(h,2e6 + 1) {
		if (cnt[h] == 0) continue;
		{ // Equal size
			ll N = (cnt[h] - 1) / 3;
			ll H = h * N;
			ans = max(ans, {{H, N}, {h, h}});
		}

		{ // Diff size
			if (h == max1.se) {
				ll N = min(cnt[h] / 2, max2.fi - 1);
				ll H = h * N;
				ans = max(ans, {{H, N}, {h, max2.se}});
			} else {
				ll N = min(cnt[h] / 2, max1.fi - 1);
				ll H = h * N;
				ans = max(ans, {{H, N}, {h, max1.se}});
			}
		}
	} if (ans.fi.fi == 0) cout << "-1 -1 -1" << ln;
	else cout << ans.fi.se << ' ' << ans.se.fi << ' ' << ans.se.se << ln;
 
}

