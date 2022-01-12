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

bool debug = true;

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	else return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}

ll count(ll n, ll k, ll b, ll e) {
	ll l = e - b;
	
	ll pos = b;
	ll ans = 0;
	do {
		if (pos % k == 0) ans++;
		pos += l;
		pos = pos % (n * k);
	} while (pos != b);


	cout << "-----" << ln;
	cout << e << ' ' << b << " - " << l << ln;
	cout << ans << ln << ln;

	return ans;
}

int main() {
  fast_cin();

  ll n, k, a, b;
  cin >> n >> k >> a >> b;

  v64 beg = {a, k - a, a + k, (k - a) + k};
  v64 en = {b, k - b, b + k, (k - b) + k};

  ll mi = INF;
  ll ma = -INF;
  
  forn(i, sz(beg)) {
  	forn(j, sz(en)) {
  		cout << i << ' ' << j << endl;
  		ll x;
  		if (beg[i] <= en[j] && beg[i] <= (n * k) && en[j] <= (n * k)) {
  			x = count(n, k, beg[i], en[j]);
  			mi = min(mi, x);
  			ma = max(ma, x);
  		}
  	}
  }



  cout << mi << ' ' << ma << ln;


}
