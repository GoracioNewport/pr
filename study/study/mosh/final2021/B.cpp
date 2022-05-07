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

vv64 p;
v64 used;

void dfs(ll v, ll c) {
	used[v] = c;
	for (auto &i : p[v]) if (used[i] == -1) dfs(i, c);
}

int main() {
  // fast_cin();

  // freopen("b1.txt","r",stdin);
  freopen("b1ansMy.txt","w",stdout);

  string f;
  getline(cin, f);
  ll t = stoll(f);


  while(t--) {
  	// cout << "a" << endl;
  	string s1raw, s2raw;
  	getline(cin, s1raw);
  	getline(cin, s2raw);
  	map <string, ll> strToInd;
  	vector <string> s1;
  	vector <string> s2;
  	set <string> ss;


  	ll m = 1;

  	string buf = "";
  	for (auto &i : s1raw) {
  		if (i == ' ') {
  			s1.pb(buf);
  			buf = "";
  			m++;
  		} else buf += i;
  	} s1.pb(buf);
  	buf = "";
  	for (auto &i : s2raw) {
  		if (i == ' ') {
  			s2.pb(buf);
  			buf = "";
  		} else buf += i;
  	} s2.pb(buf);

  	for (auto &i : s1) ss.insert(i);
		for (auto &i : s2) ss.insert(i);
		ll n = sz(ss);
		vector <string> indToStr(n);
		ll ind = 0;
		for (auto &i : ss) {
			strToInd[i] = ind;
			indToStr[ind++] = i;
		}

		p.clear();
		used.clear();
		p.resize(n, v64 ());
		used.resize(n, -1);

		forn(i,m) {
			ll indI = strToInd[s1[i]];
			ll indJ = strToInd[s2[i]];
			p[indI].pb(indJ);
			p[indJ].pb(indI);
		} forn(i,n) {
			if (used[i] == -1) dfs(i, i);
		}

		v64 cnt(n, 0);
		for (auto &i : used) if (i != -1) cnt[i]++;
		v64 ans;
		for (auto &i : cnt) if (i > 1) ans.pb(i);
		sort(all(ans));
		cout << sz(ans) << ln;
		for (auto &i : ans) cout << i << ' ';
		cout << ln;




  }


}
 