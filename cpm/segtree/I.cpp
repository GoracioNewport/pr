//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

// Author: @GoracioNewport
  
typedef int ll;
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
	ll sum, cnt;
};

struct Tree {
	vector <Node> t;
	ll n;

	Tree (ll _n) {
		n = _n;
		t.assign(4 * n, {0, 0});
	}

	void addX(ll v, ll l, ll r, ll i, ll x) {
		if (l + 1 == r) {
			t[v].sum += x;
			if (x == 1 && t[v].sum == 1) t[v].cnt++;
			if (x == -1 && t[v].sum == 0) t[v].cnt--;
			return;
		} ll m = (l + r) / 2;
		if (i < m) addX(2 * v + 1, l, m, i, x);
		else addX(2 * v + 2, m, r, i, x);
		t[v].sum = t[2 * v + 1].sum + t[2 * v + 2].sum;
	}

	ll getSum(ll v, ll l, ll r, ll L, ll R) {
		if (l >= L && r <= R) return t[v].sum;
		if (l >= R || r <= L) return 0;
		ll m = (l + r) / 2;
		return getSum(2 * v + 1, l, m, L, R) + getSum(2 * v + 2, m, r, L, R);
	}

	ll getCnt(ll v, ll l, ll r, ll L, ll R) {
		if (l >= L && r <= R) return t[v].cnt;
		if (l >= R || r <= L) return 0;
		ll m = (l + r) / 2;
		return getCnt(2 * v + 1, l, m, L, R) + getCnt(2 * v + 2, m, r, L, R); 
	}

	ll getX(ll v, ll l, ll r, ll i) {
		if (l + 1 == r) return t[v].sum;
		ll m = (l + r) / 2;
		if (i < m) return getX(2 * v + 1, l, m, i);
		else return getX(2 * v + 2, m, r, i);
	}

	ll findK(ll v, ll l, ll r, ll k) {
		if (l + 1 == r) return l;
		ll m = (l + r) / 2;
		if (t[2 * v + 1].sum > k) return findK(2 * v + 1, l, m, k);
		else return findK(2 * v + 2, m, r, k - t[2 * v + 1].sum);
	}
};

int main() {
  fast_cin();

  ll q;
  cin >> q;
  vector <p64> a(q);
  v64 b;
  for (auto& i : a) {
  	string s;
  	cin >> s >> i.se;
  	if (s[0] != 'k') b.pb(i.se);
  	if (s[0] == 'i') i.fi = 0; // count
  	else if (s[0] == 'e') i.fi = 1; // erase
  	else if (s[0] == 'k') i.fi = 3; // kth
  	else if (sz(s) == 5) i.fi = 2; // count
  	else i.fi = 4; // sum
  } map <ll, ll> z;
  sort(all(b));
  b.erase(unique(all(b)), b.end());
  ll n = sz(b);
  Tree tree(n);


  // for (auto&i : b) cout << i << ' ';
  // cout << ln;

  forn(i,sz(b)) z[b[i]] = i;
  for (auto& i : a) {


  	if (i.fi != 3) i.se = z[i.se];
  	
  	if (i.fi == 0) tree.addX(0, 0, n, i.se, 1);
  	else if (i.fi == 1) tree.addX(0, 0, n, i.se, -1);
  	else if (i.fi == 2) cout << tree.getX(0, 0, n, i.se) << ln;
  	else if (i.fi == 3) cout << b[tree.findK(0, 0, n, i.se - 1)] << ln;
  	else if (i.fi == 4) cout << tree.getSum(0, 0, n, 0, i.se) << ln;
 		
 		// forn(i,n) cout << tree.getX(0, 0, n, i) << ' ';
 		// cout << ln;
  }

}
