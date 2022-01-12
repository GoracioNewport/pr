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

struct Node {
	ll set, sum;
};

struct Tree {
	v64 a;
	vector <Node> t;
	ll n;

	Tree (ll _n) {
		// a = _a;
		n = _n;
		t.assign(4 * n, {(ll)INF, 0});
		// build(0, 0, n);
	}

	void build(ll v, ll l, ll r) {
		if (l + 1 == r) {
			t[v].sum = a[l];
			return;
		} ll m = (l + r) / 2;
		build(2 * v + 1, l, m);
		build(2 * v + 2, m, r);
		t[v].sum = t[2 * v + 1].sum + t[2 * v + 2].sum;
	}

	void push(ll v, ll l, ll r) {
		if (l + 1 == r || t[v].set == INF) return;
		ll m = (l + r) / 2;
		t[2 * v + 1].set = t[v].set;
		t[2 * v + 2].set = t[v].set;
		t[2 * v + 1].sum = t[v].set * (m - l);
		t[2 * v + 2].sum = t[v].set * (r - m);
		t[v].set = INF;
		t[v].sum = t[2 * v + 1].sum + t[2 * v + 2].sum;
	}

	void setX(ll v, ll l, ll r, ll L, ll R, ll x) {
		push(v, l, r);
		if (l >= L && r <= R) {
			t[v].set = x;
			t[v].sum = (r - l) * x;
			return;
		} if (l >= R || r <= L) return;
		ll m = (l + r) / 2;
		setX(2 * v + 1, l, m, L, R, x);
		setX(2 * v + 2, m, r, L, R, x);
		t[v].sum = t[2 * v + 1].sum + t[2 * v + 2].sum;
	}

	ll sum(ll v, ll l, ll r, ll L, ll R) {
		push(v, l, r);
		if (l >= L && r <= R) return t[v].sum;
		if (l >= R || r <= L) return 0;
		ll m = (l + r) / 2;
		return sum(2 * v + 1, l, m, L, R) + sum(2 * v + 2, m, r, L, R);
	}
};

int main() {
  fast_cin();


	ll n, q;
	cin >> n >> q;
	Tree tree(n);
	while(q--) {
		char cmd;
		cin >> cmd;
		if (cmd == 'A') {
			ll l, r, x;
			cin >> l >> r >> x;
			tree.setX(0, 0, n, l - 1, r, x);
		} else {
			ll l, r;
			cin >> l >> r;
			cout << tree.sum(0, 0, n, l - 1, r) << ln;
		}
	}


}
