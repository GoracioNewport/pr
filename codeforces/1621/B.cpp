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

  ll t;
  cin >> t;
  while(t--) {
  	ll n;
  	cin >> n;

  	pair <p64, p64> leftCost = {{INF, INF}, {INF, INF}}, leftEdge = {{INF, INF}, {INF, INF}}, rightCost = {{INF, INF}, {INF, INF}}, rightEdge = {{INF, INF}, {INF, INF}};

  	forn(i,n) {
  		ll l, r, c;
  		cin >> l >> r >> c;
  		
  		leftCost = min(leftCost, {{l, c}, {-r, i}});
  		leftEdge = min(leftEdge, {{l, -r}, {c, i}});
  		rightCost = min(rightCost, {{-r, c}, {l, i}});
  		rightEdge = min(rightEdge, {{-r, l}, {c, i}});

  		cout << min(leftCost.fi.se + rightCost.fi.se, (ll)(leftEdge.se.se == rightEdge.se.se ? leftEdge.se.fi : INF)) << ln;
  	}
  }

}
