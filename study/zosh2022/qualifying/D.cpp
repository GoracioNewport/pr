// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
// #pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

// Author: @GoracioNewport

using namespace std;

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

struct rect {
  ll x1, y1, x2, y2;
  rect (ll x1, ll y1, ll x2, ll y2): x1(x1), y1(y1), x2(x2), y2(y2) {};
  rect () {};

  void init() {
    if (x1 > x2) swap(x1, x2);
    if (y1 > y2) swap(y1, y2);
  }
};


istream& operator>> (istream& in, rect& o) {
  in >> o.x1 >> o.y1 >> o.x2 >> o.y2;
  return in;
}

rect unite(rect a, rect b) {
  return rect(max(a.x1, b.x1), max(a.y1, b.y1), min(a.x2, b.x2), min(a.y2, b.y2));
}

ll getArea(rect a) {
  if (a.x1 >= a.x2 || a.y1 >= a.y2) return 0;
  return (a.x2 - a.x1) * (a.y2 - a.y1);
}


int main() {
  fast_cin();

  rect a, b, c;
  cin >> a >> b >> c;
  a.init();
  b.init();
  c.init();

  cout << getArea(a) + getArea(b) + getArea(c) - getArea(unite(a, b)) - getArea(unite(b, c)) -  getArea(unite(a, c))
      + getArea(unite(a, unite(b, c)));


}