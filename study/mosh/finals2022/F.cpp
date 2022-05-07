// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
// #pragma GCC optimize("unroll-loops")
 
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
 
// Author: @GoracioNewport
 
using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<int> v32;
typedef vector<ll> v64;
typedef vector<ld> vdd;
typedef vector<v32> vv32;
typedef vector<v64> vv64;
typedef vector<vdd> vvdd;
typedef vector<p64> vp64;
typedef vector<vp64> vvp64;
 
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define ln "\n"
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define fastCin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
 
mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
 
istream& operator>>(istream& in, v64& a) {
  for (auto& i : a) in >> i;
  return in;
}
 
istream& operator>>(istream& in, vp64& a) {
  for (auto& i : a) in >> i.fi >> i.se;
  return in;
}
 
istream& operator>>(istream& in, vv64& a) {
  for (auto& i : a) for (auto& j : i) in >> j;
  return in;
}
 
istream& operator>>(istream& in, vvp64& a) {
  for (auto& i : a) for (auto& j : i) in >> j.fi >> j.se;
  return in;
}
 
ostream& operator<<(ostream& out, v64& a) {
  for (auto& i : a) out << i << ' ';
  return out;
}
 
ostream& operator<<(ostream& out, vp64& a) {
  for (auto& i : a) out << i.fi << ' ' << i.se << ln;
  return out;
}
 
ostream& operator<<(ostream& out, vv64& a) {
  for (auto& i : a) {
    for (auto& j : i) out << j << ' ';
    cout << ln;
  } return out;
}
 
ostream& operator<<(ostream& out, vvp64& a) {
  for (auto& i : a) {
    for (auto& j : i) out << j.fi << ' ' << j.se << ln;
    cout << ln;
  } return out;
}
 
ll mod = 1791791791;
ld eps = 1e-12;
ll INF = 2e18;
 
int main() {
  fastCin();
 
	freopen("f2.txt", "r", stdin);
  freopen("f1ans.txt", "w", stdout);  
 
  ll t;
  cin >> t;
  while(t--) {
  	ll n;
  	cin >> n;

  	map <string, ll> z;

  	vp64 p;

  	forn(i,n) {
  		string s;
  		ll l, r;
  		cin >> s >> l >> r;
  		z[s] = i;
  		p.pb({l, r});
  	} ll m;
  	cin >> m;

  	vector <pair <char, ll>> q;

  	forn(i,m) {
  		char cmd;
  		string s;
  		cin >> cmd >> s;

  		q.pb({cmd, z[s]});
  	} 

  	// p - разброс числа
  	// q - операции

  	ll MaxN = 10000;

  	vector <vector <bool>> dp(m + 1, vector <bool>(MaxN));
  	dp[0][0] = true;

  	forn(i,m) {
  		if (q[i].fi == '?') {
  			dp[i + 1] = dp[i];
  			forn(j,MaxN) {
  				if (j < p[q[i].se].fi || j > p[q[i].se].se) dp[i + 1][j] = false;
  			}
  		}

  		else {

	  		v64 posVals;
	  		forn(j,MaxN) if (dp[i][j]) posVals.pb(j);

	  		// cout << posVals << ln;

	  		for (auto& val : posVals) {
	  			
	  			if (q[i].fi == '+') {
		  			for (ll x = val + p[q[i].se].fi; x <= val + p[q[i].se].se; x++) {
		  				if (x >= 0 && x < MaxN) dp[i + 1][x] = true;
		  			}
		  		}

		  		else if (q[i].fi == '-') {
		  			for (ll x = val - p[q[i].se].se; x <= val - p[q[i].se].fi; x++) {
		  				if (x >= 0 && x < MaxN) dp[i + 1][x] = true;
		  			}
		  		}
				}

  		}
  	} 

  	// for(auto& i : dp) {
  	// 	forn(j,MaxN) cout << (i[j] > 0) << ' ';
  	// 	cout << ln;
  	// }

  	ll L = INF, R = -INF;

  	forn(i,MaxN) {
  		if (dp[m][i]) {
  			L = min(L, i);
  			R = max(R, i);
  		}
  	}

  	cout << L << ' ' << R << ln;

  }

}

