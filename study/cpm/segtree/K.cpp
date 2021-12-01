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
	ll add;
	p64 max;
};

struct Tree {
	vector <Node> t;
	ll n;

	Tree (ll _n) {
		n = _n;
		t.assign(4 * n, {0, {0, 0}});
		build(0, 0, n);
	}

	void build(ll v, ll l, ll r) {
		if (l + 1 == r) {
			t[v].max.se = l;
			return;
		} ll m = (l + r) / 2;
		build(2 * v + 1, l, m);
		build(2 * v + 2, m, r);
		t[v].max = max(t[2 * v + 1].max, t[2 * v + 2].max);
	}

	void push(ll v, ll l, ll r) {
		if (l + 1 == r) return;
		t[2 * v + 1].add += t[v].add;
		t[2 * v + 2].add += t[v].add;
		t[2 * v + 1].max.fi += t[v].add;
		t[2 * v + 2].max.fi += t[v].add;
		t[v].add = 0;
		t[v].max = max(t[2 * v + 1].max, t[2 * v + 2].max);
	}

	void add(ll v, ll l, ll r, ll L, ll R, ll x) {
		push(v, l, r);
		if (l >= L && r <= R) {
			t[v].add += x;
			t[v].max.fi += x;
			return;
		} if (l >= R || r <= L) return;
		ll m = (l + r) / 2;
		add(2 * v + 1, l, m, L, R, x);
		add(2 * v + 2, m, r, L, R, x);
		t[v].max = max(t[2 * v + 1].max, t[2 * v + 2].max);
	}

	p64 getMax(ll v, ll l, ll r, ll L, ll R) {
		push(v, l, r);
		if (l >= L && r <= R) return t[v].max;
		if (l >= R || r <= L) return {-INF, 0};
		ll m = (l + r) / 2;
		return max(getMax(2 * v + 1, l, m, L, R), getMax(2 * v + 2, m, r, L, R));
	}

};

struct event {
	ll x, l, r, type;
	bool operator< (event o) {
		if (x != o.x) return x < o.x;
		else return type < o.type;
	}
};

enum { BEGIN, DOT, END };

int main() {
  fast_cin();

  ll n, offset = 2e5;
  cin >> n;
  vector <event> q;
  forn(i,n) {
  	ll x1, y1, x2, y2;
  	cin >> x1 >> y1 >> x2 >> y2;
  	
  	x1 += offset;
  	y1 += offset;
  	x2 += offset;
  	y2 += offset;
  	
  	q.pb({x1, y1, y2, BEGIN});
  	q.pb({x2, y1, y2, END});
  	q.pb({x1, 0, 0, DOT});
  	q.pb({x2, 0, 0, DOT});
 
  } sort(all(q));

  ll N = 4e5 + 1;
  Tree tree(N);
  pair <ll, p64> ans = {-INF, {0, 0}};

  for (auto& i : q) {
  	if (i.type == DOT) {
  		p64 lAns = tree.getMax(0, 0, N, 0, N);
  		ans = max(ans, {lAns.fi, {i.x, lAns.se}});
  	} else if (i.type == BEGIN) tree.add(0, 0, N, i.l, i.r + 1, 1);
  	else tree.add(0, 0, N, i.l, i.r + 1, -1);
  } cout << ans.fi << ln;
  cout << ans.se.fi - offset << ' ' << ans.se.se - offset << ln;

}
