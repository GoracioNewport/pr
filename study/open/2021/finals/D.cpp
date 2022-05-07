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
 
void solve(ll n, ll q, vv64& p) {

	ll l, r, c;
	cin >> l >> r >> c; l--; r--;
	vv64 dp(3, v64 (n, -INF));
	dp[0][0] = p[0][0];

	if (l == 0) {
		dp[1][0] = dp[0][0] + p[1][0];
		dp[2][0] = dp[1][0] + p[2][0];
	} forn(i,n - 1) dp[0][i + 1] = dp[0][i] + p[0][i + 1];

	forsn(i,1,3) {
		forsn(j,1,n) {
			if (i == 1 && (j < l || j > r)) continue;
			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + p[i][j];
		}
	} cout << dp[2][n - 1] - c << ln;

	// cout << dp << ln;
}

int main() {
  fastCin();
 
	ll n, q;
	cin >> n >> q;
	vv64 p(3, v64 (n));
	cin >> p;

	if (q == 1) {
		solve(n, q, p);
		return 0;
	}


	vector <pair <p64, ll>> qs(q);
	for (auto& i : qs) cin >> i.fi.fi >> i.fi.se >> i.se;

	vp64 leftEdge, rightEdge;

	ll totSum = 0;

	for (auto& i : qs) {
		i.fi.fi--;
		i.fi.se--;
		leftEdge.pb({i.fi.fi, i.se});
		rightEdge.pb({i.fi.se, i.se});
		totSum += i.se;
	} sort(all(leftEdge));
	sort(all(rightEdge));

	vv64 s(3, v64(1));
	partial_sum(all(p[0]), back_inserter(s[0]));
	partial_sum(all(p[1]), back_inserter(s[1]));
	partial_sum(all(p[2]), back_inserter(s[2]));

	v64 leftSum(1), rightSum(1);

	forn(i,q) {
		leftSum.pb(leftSum.back() + leftEdge[i].se);
		rightSum.pb(rightSum.back() + rightEdge[i].se);
	}

	ll ans = -INF;
	for (ll i = 0; i < n; i++) {
		for (ll j = i + 1; j < n; j++) {
			ll locAns = s[0][i + 1];
			locAns += (s[1][j + 1] - s[1][i]);
			locAns += (s[2].back() - s[2][j]);

			ll leftI = upper_bound(all(leftEdge), {j, INF}) - leftEdge.begin();
			ll rightI = lower_bound(all(rightEdge), {i, -INF}) - rightEdge.begin() - 1;

			locAns += leftSum.back() - leftSum[leftI];
			locAns += rightSum
		}
	}

 
}

