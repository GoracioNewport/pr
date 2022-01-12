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

struct Tree {
	vector <bool> a, t;
	ll n;
	Tree (vector <bool> _a) {
		a = _a;
		n = sz(a);
		t.assign(4 * n, 0);
		build(0,0,n);
	}

	void build(ll v, ll l, ll r) {
		if (l + 1 == r) {
			t[v] = a[l];
			return;
		} ll m = (l + r) / 2;
		build(2 * v + 1, l, m);
		build(2 * v + 2, m, r);
		t[v] = t[2 * v + 1] + t[2 * v + 2];
	}

	void setX(ll v, ll l, ll r, ll i, ll x) {
		// cout << "Set\n" << ln;
		if (l + 1 == r) { 
			// cout << l << ' ' << x << ln;
			a[l] = x; 
			t[v] = a[l];
			return;
		} ll m = (l + r) / 2;
		if (i < m) setX(2 * v + 1, l, m, i, x);
		else setX(2 * v + 2, m, r, i, x);
		t[v] = t[2 * v + 1] + t[2 * v + 2];
	}

	ll getSum(ll v, ll l, ll r, ll L, ll R) {
		if (l >= R || r <= L) return 0;
		if (l >= L && r <= R) return t[v];
		ll m = (l + r) / 2;
		return getSum(2 * v + 1, l, m, L, R) + getSum(2 * v + 2, m, r, L, R);
	}
};

int main() {
  fast_cin(); 	
  ll n, q;
  cin >> n >> q;
  vector <vector <bool>> b(40, vector <bool> (n));
  v32 a(n);
  forn(i,n) {
  	// cout << i << endl;
  	cin >> a[i];
  	ll x = a[i];
  	b[x - 1][i] = 1;
  }
  vector <Tree> trees(40, Tree(vector <bool> (n, 0)));
  forn(i,40) {
  	Tree j(b[i]);
  	trees[i] = j;
  } while(q--) {
  	// cout << q << endl;
  	ll t, x, y;
  	cin >> t >> x >> y; x--;
  	if (t == 1) {
  		ll ans = 0;
  		// cout << "--------" << ln;
  		for (auto &i : trees) {
  			ans += (i.getSum(0,0,n,x,y) > 0);
  			// cout << i.getSum(0,0,n,x,y) << ln;
  		} cout << ans << ln;
  	}	else {
  		ll prev = a[x];
  		a[x] = y;
  		trees[prev - 1].setX(0,0,n,x,0);
  		trees[y - 1].setX(0,0,n,x,1);
  		// for(auto &i : trees) {
  		// 	for (auto &j : i.a) cout << j << ' ';
  		// 	cout << ln;
  		// }
  	}
  } 

}
