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

ll n;
vp64 knightMoves = {{-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {-2, -1}, {-2, 1}, {2, -1}, {2, 1}};
ll ans = -1;


bool valid(ll x, ll y) {
	return (x >= 1 && y >= 1 && x <= n && y <= n);
}

ll bishopIntersection(ll x1, ll y1, ll x2, ll y2) {
	// cout << "hello" << ln;
	if (x1 == x2 && y1 == y2) return 0;
	bool startBlack = true, finishBlack = true;
	if ((x1 + y1) % 2) startBlack = false;
	if ((x2 + y2) % 2) finishBlack = false;
	if (finishBlack != startBlack) return INF;
	if (((x1 - x2) == (y1 - y2)) || ((x1 - x2) == -(y1 - y2))) return 1;
	else return 2;
}

int main() {
  fast_cin();

  freopen("a2.txt","r",stdin);
  freopen("a2ansMy.txt","w",stdout);
  ll t;
  cin >> t;
  while(t--) {
  	cin >> n;
  	ll x1, y1, x2, y2;
  	cin >> x1 >> y1 >> x2 >> y2;
  	bool startBlack = true, finishBlack = true;
  	if ((x1 + y1) % 2) startBlack = false;
  	if ((x2 + y2) % 2) finishBlack = false;
  	// cout << startBlack << ' ' << finishBlack << ln;
  	ans = INF;
  	if (startBlack) {
  		// cout << "BBB" << ln;
  		for (auto &i : knightMoves) if (valid(x1 + i.fi, y1 + i.se)) ans = min(ans, 1 + bishopIntersection(x1 + i.fi, y1 + i.se, x2, y2));
  	
  	} else {
  		// cout << "AAA" << ln;
  		ans = bishopIntersection(x1, y1, x2, y2);
  	}// if (x1 == x2 && y1 == y2) ans = 0;
  	cout << (ans == INF ? -1 : ans) << ln;


  }

}
 