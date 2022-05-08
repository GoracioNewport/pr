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

ll len;

bool comp(pair <p64, ll> a, pair <p64, ll> b) {
	return mp(a.fi.fi / len, a.fi.se) < mp(b.fi.fi / len, b.fi.se);
}



int main() {
  fast_cin();

  ll n, q;
  cin >> n >> q;
  len = sqrt(n);
  v64 a(n);
  for (auto& i : a) cin >> i;

  vector <pair <p64, ll>> b(q);
	forn(i,q) {
		cin >> b[i].fi.fi >> b[i].fi.se;
		b[i].fi.fi--;
		b[i].fi.se--;
		b[i].se = i;
	} sort(all(b), comp);

	v64 z(1e6 + 1);
	ll sum = 0;


	ll l = 0, r = 0;
	z[a[0]] = 1;
	sum = a[0];

	v64 ans(q);

	for (auto& i : b) {
		ll L = i.fi.fi;
		ll R = i.fi.se;

		while(l > L) {
			l--;
			ll x = z[a[l]];
			sum -= a[l] * x * x;
			x++;
			z[a[l]]++;
			sum += a[l] * x * x;
		}

		while(r < R) {
			r++;
			ll x = z[a[r]];
			sum -= a[r] * x * x;
			x++;
			z[a[r]]++;
			sum += a[r] * x * x;
		}

		while(l < L) {
			ll x = z[a[l]];
			sum -= a[l] * x * x;
			x--;
			z[a[l]]--;
			sum += a[l] * x * x;
			l++;
		}

		while(r > R) {
			ll x = z[a[r]];
			sum -= a[r] * x * x;
			x--;
			z[a[r]]--;
			sum += a[r] * x * x;
			r--;
		} ans[i.se] = sum;
	} for (auto& i : ans) cout << i << ln;
}
