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

  ll n;
  cin >> n;
  vector <pair <ll, pair <ll, string>>> y;
  vector <string> ans;
  ll mi = INF;
  forn(z,n) {
  	string s, t;
  	cin >> s >> t;
  	ll m = ((t[0] - '0') * 10) + (t[1] - '0');
  	ll S = ((t[3] - '0') * 10) + (t[4] - '0');
  	ll d = (t[6] - '0');


  	// cout << m << ' ' << S << ' ' << d << endl;

  	ll x = (m * 60 + S) * 10 + d;
  	y.pb({x, {x + (z * 300)}, s});
  } sort(all(y));

  for(auto &i : y) {
  	if (mi > i.se.fi) {
  		mi = i.se.fi;
  		ans.pb(i.se.se);
  	}
  }

  sort(all(ans));
  cout << sz(ans) << ln;
  for (auto &i : ans) cout << i << ln;

}
