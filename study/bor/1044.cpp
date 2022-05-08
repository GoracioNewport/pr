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

int n, m, k;
v32 a;

struct Node {
	vector <int> p;
	int cnt;

	Node () {
		p.resize(k, -1);
		cnt = 0;
	}
};

vector <Node*> bor;
ll ind = 1;

void add(string& s) {
	auto cur = bor[0];
	for(int i = 0; i < sz(s); i++) {
		cur->cnt++;
		int c = s[i] - '0';
		if (cur->p[c] == -1) {
      bor.emplace_back(new Node());
      cur->p[c] = ind++;
    }
		cur = bor[cur->p[c]];
	} cur->cnt++;
}

pair <int, string> ans = {1e9, ""};

void getAns(Node* cur, int h, int sum, string& s) {
  for(int i = 0; i < k; i++) {
    if (cur->p[i] == -1) {
      string sCopy = s;
      if (h != m) sCopy.pb('0' + i);
      while(sz(sCopy) < m) sCopy.pb('0');
      ans = min(ans, {sum + a[h] * cur->cnt, sCopy});
      continue;
    } s.push_back('0' + i);
    getAns(bor[cur->p[i]], h + 1, sum + (cur->cnt - bor[cur->p[i]]->cnt) * a[h], s);
		s.pop_back();
	}
} 

int main() {
  fast_cin();

  cin >> n >> m >> k;
  a = {0};
  forn(i,m) {
    int x;
    cin >> x;
    a.emplace_back(x);
  }

  bor.emplace_back(new Node());
	forn(i,n) {
		string s;
		cin >> s;
		add(s);
	} string s = "";

	getAns(bor[0], 0, 0, s);
	cout << ans.se << ln << ans.fi << ln;



}