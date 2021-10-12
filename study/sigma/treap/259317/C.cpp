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
	ll key, prior, size;
	Node (ll key): l(nullptr), r(nullptr), key(key), prior(rng()), size(1) {};
};

ll getSize(Node* a) {
	if (!a) return 0;
	return a->size;
}

void upd(Node* a) {
	if (!a) return;
	a->size = getSize(a->l) + getSize(a->r) + 1;
}

ll getLeft(Node* a) {
	if (!a) return 0;
	if (a->l) return getLeft(a->l);
	return a->key;
}

ll getRight(Node* a) {
	if (!a) return 0;
	if (a->r) return getRight(a->r);
	return a->key;
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

	if (getSize(a->l) >= i) {
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
  print(a->l);
  cout << a->key << ' ';
  print(a->r);
}

Node* root = nullptr;

bool DEBUG = false;

int main() {
  fast_cin();
  ll n, q;
  cin >> n >> q;
  v64 a(n);
  for (auto& i : a) cin >> i;

  map <ll, ll> m;
	forn(i, n - 1) {
		m[a[i]] = a[i + 1];
		root = merge(root, new Node(a[i]));
	} m[a.back()] = 0;
	m[0] = 0;
	root = merge(root, new Node(a.back()));


	while(q--) {
		ll t; cin >> t;
		if (t == 1) {
			ll l1, r1, l2, r2;
			cin >> l1 >> r1 >> l2 >> r2; l1--; l2--;
			
			auto d = splitSize(root, r2);
			auto c = splitSize(d.fi, l2);
			auto b = splitSize(c.fi, r1);
			auto a = splitSize(b.fi, l1);

			if (DEBUG) {
				cout << "Left: " << ln;
				print(a.fi);
				cout << ln;
				cout << "First Seg: " << ln;
				print(a.se);
				cout << ln;
				cout << "Middle: " << ln;
				print(b.se);
				cout << ln;
				cout << "Second Seg: " << ln;
				print(c.se);
				cout << ln;
				cout << "Right: " << ln;
				print(d.se);
				cout << endl;

			}

			m[getRight(a.fi)] = getLeft(c.se);
			if (DEBUG) cout << getRight(a.fi) << " - " << getLeft(c.se) << ln;
			
			if (getLeft(b.se)) {
				m[getRight(c.se)] = getLeft(b.se);
				if (DEBUG) cout << getRight(c.se) << " - " << getLeft(b.se) << ln;
			} else {
				m[getRight(c.se)] = getLeft(a.se);	
				if (DEBUG) cout << getRight(c.se) << " - " << getLeft(a.se) << ln;
			}

			m[getRight(b.se)] = getLeft(a.se);
			if (DEBUG) cout << getRight(b.se) << " - " << getLeft(a.se) << ln;
			m[getRight(a.se)] = getLeft(d.se);
			if (DEBUG) cout << getRight(a.se) << " - " << getLeft(d.se) << endl;

			m[0] = 0;

			root = merge(a.fi, c.se);
			root = merge(root, b.se);
			root = merge(root, a.se);
			root = merge(root, d.se);

		} else {

			ll x;
			cin >> x;
			forn(i,3) {
				cout << (m[x] == 0 ? -1 : m[x]) << ' ';
				x = m[x];
			} cout << ln;

		}
	}

}
