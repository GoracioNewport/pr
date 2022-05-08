#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
  
using namespace std;
  
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
#define forsn(i,s,e) for(ll i C:\MinGW\bin= s; i < e; i++)
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

int main() {
  	fast_cin();

	ll t;
	cin >> t;
	forn(z, t) {
		ll n;
		cin >> n;
		vector <ll> a(n);
		for(auto &i : a) cin >> i;
		while (sz(a) > 1 && (count(a.begin(), a.end(), a[0]) != sz(a))) {
			ll mn = a[0];
			ll mi = 0;
			forn(i, sz(a)) {
				if (a[i] < mn) {
					mn = a[i];
					mi = i;
				}
			} cout << mn << ' ' << mi << endl;
			for (auto &i : a) cout << i << ' ';
			cout << endl;
			if (mi == 0) {
				cout << "Zero" << endl;
				a[0] += a[1];
				a.erase(a.begin() + 1);
			} else if (mi == (sz(a) - 1)) {
				cout << "Last" << endl;
				a[sz(a) - 2] += a[sz(a) - 1];
//				cout << "ok" << endl;
				a.erase(a.begin() + mi);
			} else {
				cout << "Neither" << endl; 
				if (a[mi - 1] < a[mi + 1]) {
					cout << "Left" << endl;
					a[mi - 1] += a[mi];
				} else {
					cout << "Right" << endl;
					a[mi + 1] += a[mi];
				}
			} a.erase(a.begin() + mi);
		} cout << sz(a) - n << endl;
	}

}
