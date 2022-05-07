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

const ll k = 5, mod = 1791791791;
v64 ks;

ll subHash(ll l, ll r, v64&h) { // [l, r)
	return ((h[r] - ((h[l] * ks[r - l]) % mod) + mod) % mod);
}

int main() {
  fast_cin();

  ll n, m;
  cin >> n >> m;
  vector <unordered_map <ll, bool>> z(7e5 + 1);
  ks.resize(7e5 + 1, 1);
  forn(i,7e5 + 1) ks[i + 1] = (ks[i] * k) % mod;

  forn(u,n) {
  	string s;
  	cin >> s;
  	ll H = 0;
  	forn(i,sz(s)) H = (H * k + (s[i] - 'a' + 1)) % mod;
  	z[sz(s)][H] = true;
  	// cout << H << ln;
  }

  forn(u,m) {
  	string s;
  	cin >> s;
  	v64 h(sz(s) + 1);
  	forn(i,sz(s)) h[i + 1] = (h[i] * k + (s[i] - 'a' + 1)) % mod;
  	bool ans = false;
  	forn(i,sz(s)) {
  		for (char X = 'a'; X <= 'c'; X++) {
  			if (X == s[i]) continue;
  			// cout << i << ' ' << X << ln;
  			ll L = subHash(0, i, h);
  			ll R = subHash(i + 1, sz(s), h);
  			ll H = ((L * ks[sz(s) - i] % mod) + ((X - 'a' + 1) * ks[sz(s) - i - 1] % mod) + R) % mod;
  			if (z[sz(s)][H]) ans = true;
  		}
  	} cout << (ans ? "YES" : "NO") << ln;
  }

}
