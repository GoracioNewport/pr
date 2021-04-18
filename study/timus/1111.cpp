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

ld getDist(p64 a, p64 b) {
  return sqrt(abs(a.fi - b.fi) * abs(a.fi - b.fi) + abs(a.se - b.se) * abs(a.se - b.se));
}

struct rect {
    pair <ld,ld> tl, tr, bl, br;
    rect(pair <ld,ld> a, pair <ld,ld> b, pair <ld,ld> c, pair <ld,ld> d) {
      vector <pair <ld,ld>> f = {a,b,c,d};
      sort(all(f));
      bl = f[0];
      tl = f[1];
      br = f[2];
      tr = f[3];
    }
};

int main() {
  fast_cin();

  ll n;
  cin >> n;
  vector <pair <rect, ll>> a;
  forn(i,n) {
    ld x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    rect r({x1,y1},{x2,y2},{x1,y2},{x2,y1});
    a.pb({r,i});
  } ld px, py;
  cin >> px >> py;
  bool debug = true;
  vector <pair <ld, ll>> dist;
//  for (auto &i : a) {
//    cout << i.fi.bl.fi << ' ' << i.fi.bl.se << ln;
//    cout << i.fi.br.fi << ' ' << i.fi.br.se << ln;
//    cout << i.fi.tl.fi << ' ' << i.fi.tl.se << ln;
//    cout << i.fi.tr.fi << ' ' << i.fi.tr.se << ln;
//  }
  for (auto &i : a) {
    ld d;
    rect p = i.fi;
//    cout << (p.bl.fi >= px) << ln;
//    cout << (p.br.fi <= px) << ln;
//    cout << (p.bl.se >= py) << ln;
//    cout << (p.tl.se <= py) << ln;
    if (p.bl.fi <= px && p.br.fi >= px && p.bl.se <= py && p.tl.se >= py) {
      if (debug) cout << "inside" << ln;
      d = 0;
    }
    else if ((p.bl.fi <= px && p.br.fi >= px) || (p.bl.se <= py && p.tl.se >= py)) {
      if (debug) cout << "side ";
      if (p.bl.fi <= px && p.br.fi >= px) {
        if (debug) cout << "x" << ln;
        if (p.bl.se >= py) d = abs(p.bl.se - py);
        else d = abs(p.tl.se - py);
      } else {
        if (debug) cout << "y" << ln;
        if (p.bl.fi >= px) d = abs(p.bl.fi - px);
        else d = abs(p.br.fi - px);
      }
    } else {
      if (debug) cout << "no" << ln;
      d = min(min(getDist({px, py}, p.tl), getDist({px, py}, p.tr)),
              min(getDist({px, py}, p.bl), getDist({px, py}, p.br)));
    }
    dist.pb({d,i.se});
  } sort(all(dist));
  if (debug) for (auto &i : dist) cout << i.fi << ' ';
  if (debug) cout << ln;
  for (auto &i : dist) cout << i.se + 1 << ' ';


}