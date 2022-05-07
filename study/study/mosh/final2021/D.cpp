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

int main() {
  fast_cin();

  freopen("d2.txt","r",stdin);
  freopen("d1ansMy.txt","w",stdout);

  ll t;
  cin >> t;
  while(t--) {
  	string s;
  	cin >> s;
  	ll n = sz(s);
  	set <char> ss;
  	set <string> sss;
  	v64 used(n);
  	for (auto &i : s) ss.insert(i);
  	s += '$';
  	for (char i = '1'; i <= '9'; i++) {
  		if (s.find(i) == string::npos) continue;
  		set <char> p;
  		forn(j,n) {
  			if (s[j] == i && !used[j] && !used[j + 1] && i != s[j + 1]) p.insert(s[j + 1]);
  		} if (sz(p) > 1 || *(p.begin()) == '$' || *(p.begin()) == s[0]) continue;
  		forn(j,n) if (s[j] == i && !used[j] && !used[j + 1]) used[j] = used[j + 1] = 1;
  		ss.erase(i);
  		ss.erase(*(p.begin()));
  		sss.insert({i, *(p.begin())});
  	} vector <string> ans;
  	for (auto &i : ss) ans.pb({i});
  	for (auto &i : sss) ans.pb(i);
  	sort(all(ans));
  	cout << sz(ans) << ln;
  	for (auto &i : ans) cout << i << ' ';
  	cout << ln;
  }

}
 