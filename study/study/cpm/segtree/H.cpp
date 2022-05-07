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
	ll min, max, setMax;
};

struct Tree {
	v64 a;
	vector <Node> t;
	ll n;

	Tree (v64& _a) {
		a = _a;
		n = sz(a);
		t.assign(4 * n, {0, 0, -INF});
		build(0, 0, n);
	}

	void push(ll v, ll l, ll r) {
		if (l + 1 == r || t[v].setMax == -INF) return;
		t[2 * v + 1].max = max(t[2 * v + 1].max, t[v].setMax);
		t[2 * v + 2].max = max(t[2 * v + 2].max, t[v].setMax);
		t[2 * v + 1].min = max(t[2 * v + 1].min, t[v].setMax);
		t[2 * v + 2].min = max(t[2 * v + 2].min, t[v].setMax);
		t[2 * v + 1].setMax = max(t[2 * v + 1].setMax, t[v].setMax);
		t[2 * v + 2].setMax = max(t[2 * v + 2].setMax, t[v].setMax);
		t[v].max = max(t[2 * v + 1].max, t[2 * v + 2].max);
		t[v].min = min(t[2 * v + 1].min, t[2 * v + 2].min);
		t[v].setMax = -INF;
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

	void setMax(ll v, ll l, ll r, ll L, ll R, ll x) {
		push(v, l, r);
		if (l >= L && r <= R) {
			t[v].setMax = max(t[v].setMax, x);
			t[v].max = max(t[v].max, x);
			t[v].min = max(t[v].min, x);
			return;
		} // if (l >= R || r <= L) return;
		ll m = (l + r) / 2;
		if (L < m) setMax(2 * v + 1, l, m, L, R, x);
		if (R > m) setMax(2 * v + 2, m, r, L, R, x);
		t[v].max = max(t[2 * v + 1].max, t[2 * v + 2].max);
		t[v].min = min(t[2 * v + 1].min, t[2 * v + 2].min);
	}

	ll getMin(ll v, ll l, ll r, ll L, ll R) {
		push(v, l, r);
		if (l >= L && r <= R) return t[v].min;
		if (l >= R || r <= L) return INF;
		ll m = (l + r) / 2;
		ll res = INF;
		if (L < m) res = min(res, getMin(2 * v + 1, l, m, L, R));
		if (R > m) res = min(res, getMin(2 * v + 2, m, r, L, R));
		return res;
	}

	ll getMax(ll v, ll l, ll r, ll L, ll R) {
		push(v, l, r);
		if (l >= L && r <= R) return t[v].max;
		if (l >= R || r <= L) return -INF;
		ll m = (l + r) / 2;
		ll res = -INF;
		if (L < m) res = max(res, getMax(2 * v + 1, l, m, L, R));
		if (R > m) res = max(res, getMax(2 * v + 2, m, r, L, R));
		return res;
	}



};

int main() {
  fast_cin();

  ll n;
  cin >> n;
  v64 a(n);
  for (auto&i : a) cin >> i;
  Tree tree(a);

	ll q;
	cin >> q;
	while(q--) {
		string cmd;
		cin >> cmd;
		if (cmd[0] == 'a') {
			ll l, r;
			cin >> l >> r;
			cout << tree.getMax(0, 0, n, l - 1, r) - tree.getMin(0, 0, n, l - 1, r) << ln;
		} else {
			ll l, r, x;
			cin >> l >> r >> x;
			tree.setMax(0, 0, n, l - 1, r, x);
		}
	}

}
