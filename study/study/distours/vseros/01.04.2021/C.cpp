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

int main() {
  fast_cin();

  ll n;
  cin >> n;
  vector <pair <p64, ll>> a(n);
  for (auto& i : a) cin >> i.fi.fi >> i.fi.se;
  forn(i,n) a[i].se = i;

 

  vector <pair <p64, ll>> ans;

  while(true) {
 		shuffle(all(a), rng); 
  	p64 indK = {INF, -1}; 
  	forn(i,n) {
  		if (a[i].fi.fi < 0 || a[i].fi.se < 0) {
  			indK = {min(a[i].fi.fi, a[i].fi.se), i};
  			break;
  		}
  	} if (indK.se == -1) break;

  	ll ind = indK.se;

  	pair <p64, p64> maxDiagonal = {{-INF, -INF}, {-INF, -INF}};

  	forn(i,n) {
  		forn(j,n) {
  			if (i == j || i == ind || j == ind) continue;

  			ll x3 = a[ind].fi.fi;
  			ll y3 = a[ind].fi.se;
  			ll x1 = a[i].fi.fi;
  			ll y1 = a[i].fi.se;
  			ll x2 = a[j].fi.fi;
  			ll y2 = a[j].fi.se;

  			p64 v1 = {x1 - x3, y1 - y3};
  			p64 v2 = {x2 - x3, y2 - y3};

  			ld k1 = (v1.fi == 0 ? INF : ((ld)v1.se / (ld)v1.fi));
  			ld k2 = (v2.fi == 0 ? INF : ((ld)v2.se / (ld)v2.fi));

  			if (k1 == k2) continue;

  			ll x4 = x1 + v2.fi;
  			ll y4 = y1 + v2.se;



  			maxDiagonal = max(maxDiagonal, {{max(x4, y4), ind}, {i, j}});
  		}
  	} if (maxDiagonal.fi.fi == -INF) {
  		cout << -1 << ln;
  		return 0;
  	} else {
  		ll i = maxDiagonal.se.fi;
  		ll j = maxDiagonal.se.se;

			ll x3 = a[ind].fi.fi;
			ll y3 = a[ind].fi.se;
			ll x1 = a[i].fi.fi;
			ll y1 = a[i].fi.se;
			ll x2 = a[j].fi.fi;
			ll y2 = a[j].fi.se;
			p64 v1 = {x1 - x3, y1 - y3};
			p64 v2 = {x2 - x3, y2 - y3};
			
			ll x4 = x1 + v2.fi;
			ll y4 = y1 + v2.se;

  		ans.pb({{a[i].se, a[j].se}, a[ind].se});
  		a[ind].fi.fi = x4;
  		a[ind].fi.se = y4;
  	}
  } cout << sz(ans) << ln;
  for (auto& i : ans) {
  	cout << i.fi.fi + 1 << ' ' << i.fi.se + 1 << ' ' << i.se + 1 << ln;
  }

}
