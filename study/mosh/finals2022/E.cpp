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

ll calc(vector <pair <string, ll>>& a, v64& p) {
	ll n = sz(a);
	ll ans = 0;
	forn(i,n) {
		// cout << p[i] << ln;
		if (p[i] == -1) continue;

		string x = a[p[i]].fi;
		string y = a[i].fi;

		string z = x + y;

		ans += stoll(z);

		// cout << x << ' ' << y << ' ' << z << ln;
 	} return ans;
}

ll gen(ll x) { // [0, x)
	return rng() % x;
}
 
void improve(vector <pair <string, ll>>& a, v64& p) {
	ll n = a.size();
	
	forn(z,10) {
		ll i = gen(n / 2);
		ll j = gen(n / 2);
		if (i == j) continue;

		i = i * 2 + 1;
		j = j * 2 + 1;

		ll oldRes = calc(a, p);

		// cout << p << ln;
		// cout << i << ' ' << j << ln;
		swap(p[i], p[j]);
		// cout << p << ln;

		ll newRes = calc(a, p);

		if (newRes < oldRes) swap(p[i], p[j]);
		// if (newRes == oldRes) return;
	}
}

int main() {
  fastCin();
 
	freopen("e2.txt", "r", stdin);
  freopen("e1ans.txt", "w", stdout);


	ll t;
	cin >> t;
	while(t--) {
		ll n;
		cin >> n;
		vector <pair <string, ll>> a(2 * n);
		v64 p(2 * n);
		forn(i,2 * n) {
			cin >> a[i].fi;
			a[i].se = i;
		}

		pair <ll, vp64> ans;
		ans.fi = -INF;

		forn(z,50) {
			random_shuffle(all(a));
			for (ll i = 0; i < 2 * n; i += 2) {
				p[i] = -1;
				p[i + 1] = i;
			}



			// cout << "Old: " << calc(a, p) << ln;
			improve(a, p);
			ll res = calc(a, p);
			// cout << "New: " << res << ln;


			if (res > ans.fi) {
				ans.fi = res;

				vp64 pairAns;
				forn(i, 2 * n) {
					if (p[i] == -1) continue;
					pairAns.pb({a[p[i]].se + 1, a[i].se + 1});
				} ans.se = pairAns;

			}
		}

		cout << ans.fi << ln << ans.se;
	}
 
}

