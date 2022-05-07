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
	ll l, r, ans;
	Node (): l(0), r(0), ans(0) {};
};

struct Tree {
	string a;
	vector <Node> t;
	ll n;

	Tree (string& _a) {
		a = _a;
		n = sz(a);
		t.assign(4 * n, Node());
		build(0, 0, n);
	}

	Node merge(Node a, Node b) {
		Node ans;
		ans.l = a.l + b.l;
		ans.r = a.r + b.r;
		ans.ans = a.ans + b.ans + min(a.l - a.ans, b.r - b.ans);
		return ans;
	}

	void build(ll v, ll l, ll r) {
		if (l + 1 == r) {
			if (a[l] == '(') t[v].l++;
			else t[v].r++;
			return;
		} ll m = (l + r) / 2;
		build(2 * v + 1, l, m);
		build(2 * v + 2, m, r);
		t[v] = merge(t[2 * v + 1], t[2 * v + 2]);
	}

	Node getAns(ll v, ll l, ll r, ll L, ll R) {
		if (l >= L && r <= R) return t[v];
		if (l >= R || r <= L) return Node();
		ll m = (l + r) / 2;
		return merge(getAns(2 * v + 1, l, m, L, R), getAns(2 * v + 2, m, r, L, R));
	}
};

int main() {
  fast_cin();

  string s;
  cin >> s;
  Tree tree(s);
  ll q;
  cin >> q;
  while(q--) {
  	ll l, r;
  	cin >> l >> r;
  	cout << tree.getAns(0, 0, sz(s), l - 1, r).ans * 2 << ln;
  }

}
