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

bool DEBUG = true;

struct Node {
	Node* l;
	Node* r;
	ll key, prior;
	ll size, sum;

	Node (ll key): key(key), prior(rand()), size(1), sum(key) {};
};

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
		a->r = b;
		upd(a);
		return a;
	} else {
		b->l = a;
		upd(b);
		return b;
	}
}

pair <Node*, Node*> splitSize(Node *a, ll i) {
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

int main() {
  fast_cin();
  ll ind = 0;

  while(true) {
  	if (!DEBUG) cout << "Swapper " << ++ind << ":" << ln;
  	ll n, m;
  	cin >> n >> m;
  	if (n == 0 && m == 0) break;

  	v64 a(n);
  	for (auto& i : a) cin >> i;
  	
  	Node *even = nullptr;
 		Node *odd = nullptr;

 		forn(i,n) {
 			if (i % 2) odd = merge(odd, new Node(a[i]));
 			else even = merge(even, new Node(a[i]));
 		}

 		if (DEBUG) {
 			cout << "Initial state:" << endl;
 			print(even);
			cout << endl;
			print(odd);
			cout << endl;
 		}

 		while(m--) {
 			ll t, x, y, evenL, evenR, oddL, oddR;
 			cin >> t >> x >> y;
 			// ll len = (y - x + 1) / 2;
 			x--; y--;
 			if (DEBUG) cout << endl;

 			if (x % 2) {
 				oddL = x / 2;
 				evenL = oddL + 1;
 			} else {
 				oddL = x / 2;
 				evenL = oddL;
 			} 

 			if (y % 2) {
 				oddR = (y / 2) + 1;
 				evenR = oddR;
 			} else {
 				oddR = (y / 2);
 				evenR = oddR + 1;
 			}

 			auto evenP = splitSize(even, evenR);
			auto evenQ = splitSize(even, evenL);

			auto oddP = splitSize(odd, oddR);
			auto oddQ = splitSize(odd, oddL);

 			if (t == 1) {

 				if (DEBUG) {
 					cout << "EVEN: " << evenL << ' ' << evenR << ln;
 					cout << "ODD: " << oddL << ' ' << oddR << ln;
 				}

 				even = merge(evenQ.fi, oddQ.se);
 				even = merge(even, evenP.se);

 				odd = merge(oddQ.fi, evenQ.se);
 				odd = merge(odd, oddP.se);
 			
 			} else {

 				cout << getSum(evenQ.se) + getSum(oddQ.se) << ln;

 				even = merge(evenQ.fi, evenQ.se);
 				even = merge(even, evenP.se);

 				odd = merge(oddQ.fi, oddQ.se);
 				odd = merge(odd, oddP.se);

 			}

			if (DEBUG) {
				print(even);
				cout << endl;
				print(odd);
				cout << endl;
			}
 		}
  }

}
