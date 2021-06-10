//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
//#pragma GCC optimize("unroll-loops")
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

struct Point {
    ld x, y;
    Point(pdd a) {
      x = a.fi;
      y = a.se;
    }
};

struct CenterPoint {
    ld x, y;
    ld r;
    pdd ind;
    CenterPoint(pdd a, pdd i, ld _r) {
      x = a.fi;
      y = a.se;
      r = _r;
      ind = i;
    }

    bool operator< (const CenterPoint &o) const {
      if (x != o.x) return x < o.x;
      else {
        if (y != o.y) return y < o.y;
        else {
          if (r != o.r) return r < o.r;
          else {
            if (ind.fi != o.ind.fi) return ind.fi < o.ind.fi;
            else return ind.se < o.ind.se;
          }
        }
      }
    }

};

int main() {
  fast_cin();
  ll n;
  cin >> n;
  vector <Point> a;
  forn(i,n) {
    ld x, y;
    cin >> x >> y;
    Point z({x,y});
    a.pb(z);
  }
  ld ans = -INF;
  vector <CenterPoint> b;
  forn(i,n) {
    forsn(j, i + 1, n) {
      Point center({(a[i].x + a[j].x) / 2, (a[i].y + a[j].y) / 2});
      ld r = hypot(abs(center.x - a[i].x), abs(center.y - a[i].y));
      CenterPoint c({center.x, center.y}, {min(i,j), max(i,j)}, r);
      b.pb(c);
    }
  } sort(all(b));

//  for (auto &i : b) {
//    cout << i.r << ' ' << i.x << ' ' << i.y << ln;
//  } cout << ln;

  forn(i,n) {
    forsn(j, i + 1, n) {
      Point center({(a[i].x + a[j].x) / 2, (a[i].y + a[j].y) / 2});
      ld R = hypot(abs(center.x - a[i].x), abs(center.y - a[i].y));

      ll l = 0;
      ll r = sz(b);
      while(l + 1 < r) {
        ll m = (l + r) / 2;
        pdd A({b[m].x, b[m].y});
        pdd B({center.x, center.y});
        if (A == B) {
          if (b[m].r < R) l = m;
          else r = m;
        } else {
          if (A < B) l = m;
          else r = m;
        }
      } forsn(k,r,sz(b)) {
        if (b[k].x != center.x || b[k].y != center.y) break;
        if (b[k].r < R) continue;
        if (b[k].r > R) break;
        Point x = a[b[k].ind.fi];
        ld X = hypot(abs(a[i].x - x.x), abs(a[i].y - x.y));
        ld Y = hypot(abs(a[j].x - x.x), abs(a[j].y - x.y));
        if (X * Y > ans) {
//          cout << X << ' ' << Y << ln;
//          cout << a[i].x << ' ' << a[i].y << ' ' << a[j].x << ' ' << a[j].y << ' ' << a[b[k].ind.fi].x << ' ' << a[b[k].ind.fi].y << ln;
//          cout << X * Y << ln;
        }
        ans = max(ans, X * Y);
      }

    }
  } cout << setprecision(17) << ans << ln;


}