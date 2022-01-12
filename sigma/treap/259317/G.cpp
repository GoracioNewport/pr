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
	ll key, prior;
	Node *l;
	Node *r;

	Node (ll key): key(key), prior(rand()) {
		l = r = nullptr;
	}
};

Node* root = nullptr;

Node* merge(Node* a, Node* b) {
	if (a == nullptr) return b;
	if (b == nullptr) return a;

	if (a->prior > b->prior) {
		a->r = merge(a->r, b);
		return a;
	} else {
		b->l = merge(a, b->l);
		return b;
	}
}

pair <Node*, Node*> split(Node* a, ll x) {
	if (a == nullptr) return {nullptr, nullptr};

	if (x <= a->key) { 
		auto p = split(a->l, x);
		a->l = p.se;
		return {p.fi, a};
	} else {
		auto p = split(a->r, x);
		a->r = p.fi;
		return {a, p.se};
	}
}

ll findMin(Node *a) {
	if (a == nullptr) return INF;
	if (a->l) return findMin(a->l);
	return a->key;
}

ll findMax(Node* a) {
	if (a == nullptr) return -INF;
	if (a->r) return findMax(a->r);
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

void erase(ll x) {
	auto p = split(root, x);
	auto q = split(p.se, x + 1);
	root = merge(p.fi, q.se);
	return;
}

bool exists(ll x) {
	auto p = split(root, x);
	bool ans = (findMin(p.se) == x);
	root = merge(p.fi, p.se);
	return ans;
}

ll next(ll x) {
	auto p = split(root, x + 1);
	ll ans = findMin(p.se);
	root = merge(p.fi, p.se);
	return ans;
}

ll prev(ll x) {
	auto p = split(root, x);
	ll ans = findMax(p.fi);
	root = merge(p.fi, p.se);
	return ans;
}

int main() {
  fast_cin();
  srand(time(0));

  string s;
  ll x;
  while(cin >> s >> x) {
  	if (s[0] == 'i') insert(x);
  	if (s[0] == 'd') erase(x);
  	if (s[0] == 'e') cout << (exists(x) ? "true" : "false") << ln;
  	if (s[0] == 'n') cout << (next(x) == INF ? "none" : to_string(next(x))) << ln;
  	if (s[0] == 'p') cout << (prev(x) == -INF ? "none" : to_string(prev(x))) << ln;
  }

}
