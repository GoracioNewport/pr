// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
// #pragma GCC optimize("unroll-loops")
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

ll n, m, k;
v64 a;

struct Node {
	vector <Node*> p;
	ll cnt;

	Node () {
		p.resize(k, nullptr);
		cnt = 0;
	}
};

Node* root = nullptr;

void add(string& s) {
	auto cur = root;
	for(ll i = 0; i < sz(s); i++) {
		cur->cnt++;
		ll c = s[i] - '0';
		if (cur->p[c] == nullptr) cur->p[c] = new Node();
		cur = cur->p[c];
	} cur->cnt++;
}

pair <ll, string> ans = {INF, ""};

void getAns(Node* cur, ll h, ll sum, string& s) {
	if (h == m - 1) {
		ans = min(ans, {sum, s});
		return;
	} forn(i,k) {
		s.push_back('0' + i);
		getAns(cur->p[i], h + 1, sum + (cur->cnt - cur->p[i]->cnt) * a[h + 1], s);
		s.pop_back();
	}
} 

int main() {
  fast_cin();

  cin >> n >> m >> k;
  a.resize(m);
  for (auto& i : a) cin >> i;

	root = new Node();
	forn(i,n) {
		string s;
		cin >> s;
		add(s);
	} string s = "";
	getAns(root, -1, 0, s);
	cout << ans.fi << ln << ans.se << ln;



}