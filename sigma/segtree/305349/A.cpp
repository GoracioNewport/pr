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
#define INF (ll)2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

struct Node {
	ll Min, Max;
};

struct Tree {
	ll n;
	v64 a;
	vector <Node> t;

	Tree (v64 &_a) {

		a = _a;
		n = sz(a);
		t.assign(4 * n, {INF, -INF});

		build(0, 0, n);
	}

	void build(ll v, ll l, ll r) {
		if (l + 1 == r) {
			t[v].Max = t[v].Min = a[l];
			return;
		} ll m = (l + r) / 2;

		build(2 * v + 1, l, m);
		build(2 * v + 2, m, r);

		t[v].Min = min(t[2 * v + 1].Min, t[2 * v + 2].Min);
		t[v].Max = max(t[2 * v + 1].Max, t[2 * v + 2].Max);
	}

	ll findMax(ll v, ll l, ll r, ll L, ll R) {
		if (l >= L && r <= R) return t[v].Max;
		if (l >= R || r <= L) return -INF;
		ll m = (l + r) / 2;
		return (max(findMax(2 * v + 1, l, m, L, R), findMax(2 * v + 2, m, r, L, R)));
	}

	ll findMin(ll v, ll l, ll r, ll L, ll R) {
		if (l >= L && r <= R) return t[v].Min;
		if (l >= R || r <= L) return INF;
		ll m = (l + r) / 2;
		return (min(findMin(2 * v + 1, l, m, L, R), findMin(2 * v + 2, m, r, L, R)));
	}

	void update(ll v, ll l, ll r, ll i, ll x) {
		if (l + 1 == r) {
			t[v].Min = t[v].Max = x;
			return;
		} ll m = (l + r) / 2;
		if (i < m) update(2 * v + 1, l, m, i, x);
		else update(2 * v + 2, m, r, i, x);


		t[v].Min = min(t[2 * v + 1].Min, t[2 * v + 2].Min);
		t[v].Max = max(t[2 * v + 1].Max, t[2 * v + 2].Max);
	}
	
};

int main() {
  fast_cin();

  ll n = 1e5 + 1;
  // ll n = 10;

  v64 a(n);
  forn(i,n) a[i] = (((i * i) % 12345) + ((i * i * i) % 23456));
  Tree tree(a);



  ll q;
  cin >> q;
  while(q--) {
  	ll x, y;
  	cin >> x >> y;

  	if (x > 0) cout << tree.findMax(0, 0, n, x, y + 1) - tree.findMin(0, 0, n, x, y + 1) << ln;
  	else tree.update(0, 0, n, -x, y);
  }

}
