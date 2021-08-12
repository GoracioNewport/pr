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
	ll key, prior, size, sum;
	Node (ll key): l(nullptr), r(nullptr), key(key), prior(rng()), size(1), sum(key * key) {};
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
	a->sum = getSum(a->l) + getSum(a->r) + (a->key * a->key);
}

Node* merge(Node* a, Node* b) {
	if (!a) return b;
	if (!b) return a;
	upd(a);
	upd(b);

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
	upd(a);

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

bool DEBUG = false;

int main() {
  fast_cin();

  // freopen("river.in", "r", stdin);
  // freopen("river.out", "w", stdout);

  ll n, k;
  cin >> n >> k;
  forn(i,n) {
  	ll x; cin >> x;
  	root = merge(root, new Node(x));
  } ll q;
  cin >> q;
  cout << getSum(root) << ln;
  while(q--) {
  	ll t, i;
  	cin >> t >> i; i--;
  	if (t == 1) {
  		if (i == 0) {

  			auto p = splitSize(root, 2);
  			auto q = splitSize(p.fi, 1);
  			ll x = q.fi->key;
  			q.se->key += x;
				root = merge(q.se, p.se);

  		} else if (i == n - 1) {

  			auto p = splitSize(root, i - 1);
  			auto q = splitSize(p.se, 1);
  			ll x = q.se->key;
  			q.fi->key += x;
  			root = merge(p.fi, q.fi);

  		} else {

  			auto d = splitSize(root, i + 2);
  			auto c = splitSize(d.fi, i + 1);
  			auto b = splitSize(c.fi, i);
  			auto a = splitSize(b.fi, i - 1);
  			ll x = b.se->key;

  			a.se->key += (x / 2);
  			c.se->key += x - (x / 2);

  			root = merge(a.fi, a.se);
  			root = merge(root, c.se);
  			root = merge(root, d.se);

  		} n--;

  	} else {

			auto p = splitSize(root, i + 1);
			auto q = splitSize(p.fi, i);
			ll x = q.se->key;
			root = merge(q.fi, new Node(x / 2));
			root = merge(root, new Node(x - (x / 2)));
			root = merge(root, p.se);
			n++;

  	}  if (DEBUG) {
  		print(root);
  		cout << endl;
  	} cout << getSum(root) << ln;
  } 
}
