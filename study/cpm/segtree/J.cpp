// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma,popcnt")
// #pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

// Author: @GoracioNewport
  
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define ln "\n"
#define pb push_back
#define fi first
#define se second
#define INF (ll)2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

struct Node {
	ll min, max;
};

struct Tree {
	v64 a;
	vector <Node> t;
	ll n;

	Tree (v64& _a) {
		a = _a;
		n = sz(a);
		t.assign(4 * n, {INF, -INF});
		build(0, 0, n);
	}


	void build(ll v, ll l, ll r) {
		if (l + 1 == r) {
			t[v].min = t[v].max = a[l];
			return;
		} ll m = (l + r) / 2;
		build(2 * v + 1, l, m);
		build(2 * v + 2, m, r);
		t[v].min = min(t[2 * v + 1].min, t[2 * v + 2].min);
		t[v].max = max(t[2 * v + 1].max, t[2 * v + 2].max);
	}

	void addX(ll v, ll l, ll r, ll i, ll x) {
		if (l + 1 == r) {
			t[v].min += x;
			t[v].max += x;
			return;
		} ll m = (l + r) / 2;
		if (i < m) addX(2 * v + 1, l, m, i, x);
		else addX(2 * v + 2, m, r, i, x);
		t[v].min = min(t[2 * v + 1].min, t[2 * v + 2].min);
		t[v].max = max(t[2 * v + 1].max, t[2 * v + 2].max);
	}

	ll getMin(ll v, ll l, ll r, ll L, ll R) {
		if (l >= L && r <= R) return t[v].min;
		if (l >= R || r <= L) return INF;
		ll m = (l + r) / 2;
		return min(getMin(2 * v + 1, l, m, L, R), getMin(2 * v + 2, m, r, L, R));
	}

	ll getMax(ll v, ll l, ll r, ll L, ll R) {
		if (l >= L && r <= R) return t[v].max;
		if (l >= R || r <= L) return -INF;
		ll m = (l + r) / 2;
		return max(getMax(2 * v + 1, l, m, L, R), getMax(2 * v + 2, m, r, L, R));
	}
};


int main() {
  fast_cin();

  ll n, q;
  cin >> n >> q;
  v64 a(n);
  for (auto& i : a) cin >> i;
  v64 b(n - 1);
	forn(i,n) b[i] = a[i + 1] - a[i];
	Tree tree(b);

	while(q--) {
		ll cmd;
		cin >> cmd;
		if (cmd == 1) {
			ll x, y;
			cin >> x >> y;
			if (x < y) {
				ll ans = tree.getMax(0, 0, n - 1, x - 1, y - 1);
				cout << (ans > 1 ? "NO" : "YES") << ln;
			} else {
				ll ans = tree.getMin(0, 0, n - 1, y - 1, x - 1);
				cout << (ans < -1 ? "NO" : "YES") << ln;
			}
		} else {
			ll l, r, x;
			cin >> l >> r >> x; l--; r--;
			if (l >= 0) tree.addX(0, 0, n - 1, l, x);
			if (r + 1 < n - 1) tree.addX(0, 0, n - 1, r + 1, -x);
		}

		for (auto& i : tree.t) cout << i.min << ' ' << i.max << ln;
		cout << ln; 
	}
}
