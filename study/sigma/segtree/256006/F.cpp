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

mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

struct Node {
	Node* l;
	Node* r;
	ll key, prior, size, min;

	Node (ll key): l(nullptr), r(nullptr), key(key), prior(rng()), size(1), min(key) {};
};

Node* root = nullptr;

ll getSize(Node* a) {
	if (!a) return 0;
	return a->size;
}

ll getMin(Node* a) {
	if (!a) return INF;
	return a->min;
}

void upd(Node* a) {
	if (!a) return;
	a->size = getSize(a->l) + getSize(a->r) + 1;
	a->min = min(min(getMin(a->l), getMin(a->r)), a->key);
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

pair <Node*, Node*> splitSize(Node* a, ll i) {
	if (!a) return {nullptr, nullptr};

	if (i <= getSize(a->l)) {
		auto p = splitSize(a->l, i);
		a->l = p.se;
		upd(a);
		return {p.fi, a};
	} else {
		auto p = splitSize(a->r, i - getSize(a->l) - 1);
		a->r = p.fi;
		upd(a);
		return {a, p.se};
	}
}

void print(Node *a) {
  if (!a) return;
  upd(a);
  print(a->l);
  cout << a->key << ' ';
  print(a->r);
}



int main() {
  fast_cin();

  freopen("rmq.in", "r", stdin);
  freopen("rmq.out", "w", stdout);

  ll q;
  cin >> q;
  while(q--) {
  	char c;
  	ll l, r;
  	cin >> c >> l >> r; l--;
  	if (c == '?') {
  		auto q = splitSize(root, r);
  		auto p = splitSize(q.fi, l);
  		cout << getMin(p.se) << ln;
  		root = merge(p.fi, p.se);
  		root = merge(root, q.se);
  	} else {
  		auto p = splitSize(root, l + 1);
  		root = merge(p.fi, new Node(r));
  		root = merge(root, p.se);
  		// print(root);
  		// cout << endl;
  	}
  }

}
