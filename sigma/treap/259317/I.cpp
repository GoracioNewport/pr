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
	Node* l;
	Node* r;
	ll key, prior, size, sum;
	Node (ll key): l(nullptr), r(nullptr), key(key), prior(rand()), size(1), sum(key) {};
};

Node* root = nullptr;

ll getSize(Node* a) {
	if (!a) return 0;
	return a->size;
}

ll getSum(Node* a) {
	if (!a) return 0;
	return a->sum;
}

void upd(Node* a) {
	if (!a) return;
	a->size = getSize(a->l) + getSize(a->r) + 1;
	a->sum = getSum(a->l) + getSum(a->r) + a->key;
}

Node* merge(Node* a, Node* b) {
	if (!a) return b;
	if (!b) return a;

	if (a->prior > b->prior) {
		a->r = merge(a->r, b);
		upd(a);
		return a;
	} else {
		b->l = merge(a, b->l);
		upd(b);
		return b;
	}
}

pair <Node*, Node*> split(Node* a, ll x) {
	if (!a) return {nullptr, nullptr};

	if (x <= a->key) {
		auto p = split(a->l, x);
		a->l = p.se;
		upd(a);
		return {p.fi, a};
	} else {
		auto p = split(a->r, x);
		a->r = p.fi;
		upd(a);
		return {a, p.se};
	}
}

ll findMin(Node *a) {
	if (!a) return INF;
	if (a->l) return findMin(a->l);
	return a->key;
}

void insert(ll x) {
	auto p = split(root, x);
	if (findMin(p.se) == x) {
		root = merge(p.fi, p.se);
		return;
	} root = merge(p.fi, new Node(x));
	root = merge(root, p.se);
}

int main() {
  fast_cin();

  ll q;
  cin >> q;
  ll prev = -1;
  while(q--) {
  	char cmd;
  	cin >> cmd;
  	if (cmd == '+') {
  		ll x;
  		cin >> x;
  		if (prev != -1) x = (x + prev) % (ll)1e9;
  		insert(x);
  		prev = -1;
  	} else {
  		ll l, r;
  		cin >> l >> r;
  		auto p = split(root, r + 1);
  		auto q = split(p.fi, l);
  		prev = getSum(q.se);
  		cout << prev << ln;
  		root = merge(q.fi, q.se);
  		root = merge(root, p.se);
  	}
  }

}
