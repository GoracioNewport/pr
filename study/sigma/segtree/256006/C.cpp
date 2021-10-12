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
	ll seg, sum;
};

struct Tree {
	vector <Node> t;
	ll n;

	Tree(ll _n) {
		n = _n;
		t.assign(4 * n, {INF, 0});
	}

	void push(ll v, ll l, ll r) {
		if (t[v].seg == INF || l + 1 == r) return;
		ll m = (l + r) / 2;
		t[2 * v + 1].seg = t[v].seg;
		t[2 * v + 1].sum = t[v].seg * (m - l);
		t[2 * v + 2].seg = t[v].seg;
		t[2 * v + 2].sum = t[v].seg * (r - m);
		t[v].seg = INF; 	
	}

	void setX(ll v, ll l, ll r, ll L, ll R, ll x) {
		push(v, l, r);
		if (l >= L && r <= R) {
			t[v].seg = x; 
			t[v].sum = x * (r - l);
			return;
		} if (l >= R || r <= L) return;
		ll m = (l + r) / 2;

		setX(2 * v + 1, l, m, L, R, x);
		setX(2 * v + 2, m, r, L, R, x);
		t[v].sum = t[2 * v + 1].sum + t[2 * v + 2].sum;
	}

	ll getSum(ll v, ll l, ll r, ll L, ll R) {
		push(v, l, r);
		if (l >= L && r <= R) return t[v].sum;
		if (l >= R || r <= L) return 0;
		ll m = (l + r) / 2;
		return getSum(2 * v + 1, l, m, L, R) + getSum(2 * v + 2, m, r, L, R);
	}
};

int main() {
  fast_cin();

 	freopen("sum.in", "r", stdin);
 	freopen("sum.out", "w", stdout);

  ll n, k;
  cin >> n >> k;

  Tree tree(n);


  while(k--) {
  	char c;
  	ll l, r;
  	cin >> c >> l >> r;
  	if (c == 'A') {
  		ll x;
  		cin >> x;
  		tree.setX(0, 0, n, l - 1, r, x);
  	} else cout << tree.getSum(0, 0, n, l - 1, r) << ln;
  }
}
