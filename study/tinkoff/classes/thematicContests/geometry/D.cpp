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

  ld x1, y1, r1, x2, y2, r2;
  cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
  cout << fixed << setprecision(20);
  if (x1 == x2 && y1 == y2 && r1 == r2) {
  	cout << 3;
  	return 0;
  } if (x1 == x2 && y1 == y2 && r1 != r2) {
  	cout << 0;
  	return 0;
  }

  ld offsetX = x1, offsetY = y1;

  x1 -= offsetX;
  x2 -= offsetX;
  y1 -= offsetY;
  y2 -= offsetY;

  ld a = -2 * x2;
  ld b = -2 * y2;
  ld c = (x2 * x2 + y2 * y2 + r1 * r1 - r2 * r2);

  // cout << a << ' ' << b << ' ' << c << ln;

  ld x0 = -(a * c) / (a * a + b * b);
  ld y0 = -(b * c) / (a * a + b * b);

  // cout << x0 << ' ' << y0 << ln;

  ld d = hypot(x0, y0);
  if (d > r1) {
  	cout << 0;
  	return 0;
  } else if (d == r1) {
  	cout << 1 << ln;
  	cout << x0 + offsetX << ' ' << y0 + offsetY << ln;
  } else {
  	cout << 2 << ln;
  	ld g = r1 * r1 - d * d;
  	ld mult = sqrt(g / (a * a + b * b));
  	cout << x0 + b * mult + offsetX << ' ' << y0 - a * mult + offsetY << ln << x0 - b * mult + offsetX << ' ' << y0 + a * mult + offsetY << ln;
  }



}
