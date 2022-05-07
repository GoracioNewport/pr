//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

// Author: @GoracioNewport

using namespace std;

typedef long long ll;
typedef double ld;
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


struct Point {
	ld x, y;
	// Point (ld X, ld Y) {
	// 	x = X;
	// 	y = Y;
	// }
};

struct Rect {
	Point bl, br, tl, tr;
	Rect (Point Bl, Point Tr) {
		Point Center({(Bl.x + Tr.x) / 2, (Bl.y + Tr.y) / 2});
		Point r({abs(Center.x - Bl.x), abs(Center.y - Bl.y)});
		bl = {Center.x + r.x, Center.y + r.y};
		br = {Center.x - r.x, Center.y - r.y};
		tl = {Center.x + r.y, Center.y - r.x};
		tr = {Center.x - r.y, Center.y + r.x}; 
	}
};

struct Line {
	ld A, B, C;
	Line (Point a, Point b) {
		A = a.y - b.y;
		B = b.x - a.x;
		C = (a.x * b.y) - (b.x * a.y);
	}
};

ld getDist(Point a, Point b) {
	return hypot(a.x - b.x, a.y - b.y);
}


int main() {
  fast_cin();

  ll n;
  cin >> n;

  vector <Rect> a(n);
  for (auto &i : a) {
  	ld x1, y1, x2, y2;
  	cin >> x1 >> y1 >> x2 >> y2;
  	Point a(x1, y1), b(x2, y2);
  	i = Rect(a, b);
  } vp64 ans(n);
  ld x, y;
  cin >> x >> y;
  Point s(x, y);
  for (auto &i : a) {

  }

}