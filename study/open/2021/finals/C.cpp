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

bool DEBUG = false;

ll calc(vv64 a, v64 cnt) {
	ll c = sz(cnt);
	ll n = sz(a);
	ll m = sz(a[0]);
	if (DEBUG) {
		cout << "--- " << n << ' ' << m << ln;
		cout << a << ln << ln;
	}

	v64 fistOccurence(c, -1);

	forn(j,m) {
		forn(i,n) {
			if (fistOccurence[a[i][j]] == -1) {
				fistOccurence[a[i][j]] = j;
				// if (DEBUG) cout << "UPDATE " << a[i][j] << ' ' << fistOccurence[a[i][j]] << ln;
			}
		}
	} 

	v64 len(c), cntZ(c), lastCord(c);
	ll ans = 0;

	for (ll j = m - 1; j >= 0; j--) {
		unordered_map <ll, bool> used; 

		forn(i,n) {
			if (used[a[i][j]]) continue;
			used[a[i][j]] = true;
			if(fistOccurence[a[i][j]] <= j) len[a[i][j]] += cntZ[a[i][j]] * (lastCord[a[i][j]] - j);
		}
		forn(i,n) {
			cntZ[a[i][j]]++;
			ans += len[a[i][j]];
			lastCord[a[i][j]] = j;
		}
	}

	v64 cntF(c);

	forn(i,n) {
		forn(j,m) {
			if (j == fistOccurence[a[i][j]]) cntF[a[i][j]]++;
		}
	} 

	if (DEBUG) cout << "COLORS: " << ln;
 	forn(j,c) {
		// ans += cntF[j] * len[j];
		if (DEBUG) cout << j << ' ' << cntF[j] << ' ' << len[j] << ln;
	} if (DEBUG) cout << ln;
	if (DEBUG) cout << "ANS: " << ans << ln;
	return ans;
} 
 
int main() {
  fastCin();
 
	ll n, m;
	cin >> n >> m;

	vv64 p(n, v64(m));
	cin >> p;


	v64 allColors;
	for (auto& i : p) for (auto& j : i) allColors.pb(j);

	sort(all(allColors));
	allColors.erase(unique(all(allColors)), allColors.end());
	
	unordered_map <ll, ll> z;
	forn(i,sz(allColors)) z[allColors[i]] = i;

	for (auto& i : p) for (auto& j : i) j = z[j];

	ll c = allColors.size();

	v64 cnt(c);
	for (auto& i : p) for (auto& j : i) cnt[j]++;
	ll ans = 0;

	ans += calc(p, cnt);

	for (auto& i : p) reverse(all(i));
	ans += calc(p, cnt);



	vv64 newP(m);
	forn(i,n) {
		for(ll j = m - 1; j >= 0; j--) {
			newP[j].pb(p[i][j]);
		}
	} 

	ans += calc(newP, cnt);


	for (auto& i : newP) reverse(all(i));
	ans += calc(newP, cnt);

	cout << ans / 2 << endl;

	
 
}

