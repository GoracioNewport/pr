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
ll mod = 1791791791;
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

v64 ks, h;
const ll k = 239;
ll n;
string s;

ll subhash(ll l, ll r) {
	return ((h[r + 1] - ((h[l] * ks[r - l + 1]) % mod) + mod) % mod);
}

ll findLcp(ll a, ll b) {
	ll lenA = n - a;
	ll lenB = n - b;
	ll l = -1;
	ll r = min(lenA, lenB);
	while(l + 1 < r) {
		ll m = (l + r) / 2;
		if (subhash(a, a + m) == subhash(b, b + m)) l = m;
		else r = m;
	} return r;
}

bool subSort(ll a, ll b) { // < - true
	ll lcp = findLcp(a,b);
	// cout << "Sort " << s.substr(a) << ' ' << s.substr(b) << ln;
	// cout << "LCP: " << r << ln;
	if (lcp == min(n - a, n - b)) {
		// if (lenA < lenB) cout << "<" << ln;
		// else cout << ">" << ln;
		if (n - a < n - b) return true;
		else return false;
	} 

	// if (s[a + r] < s[b + r]) cout << "<" << ln;
	// else cout << ">" << ln;


	return (s[a + lcp] < s[b + lcp]);
}

int main() {
  fast_cin();

  cin >> s;
  n = sz(s);
  ks.resize(n + 1, 1);
  h.resize(n + 1, 0);
  forn(i,n) {
  	ks[i + 1] = (ks[i] * k) % mod;
  	ll x = (s[i] - 'a' + 1);
  	h[i + 1] = ((h[i] * k) % mod) + x;
  } v64 sufArr(n);
  iota(all(sufArr), 0);
  sort(all(sufArr), subSort);
  // for (auto &i : sufArr) cout << i << ' ' << s.substr(i) << ln;
  ll ans = (n * (n + 1)) / 2;
  forsn(i,1,n) ans -= findLcp(sufArr[i], sufArr[i - 1]);
  cout << ans << ln;

}
