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


ll m, n;
vp64 a(n);

v64 used(n);

bool isValid(ll x, ll y) {
  return (x >= 0 && y >= 0 && x < m && y < m);
}

void inter(ll x, ll y, ll xS, ll yS) {
  while(isValid(x,y)) {
    ll ind = 0;
    for (auto &i : a) {
      if (i.fi == x && i.se == y) {
        used[ind] = 1;
      }
      ind++;
    } x += xS;
    y += yS;
  }
}

bool intersection(ll x, ll y) {

  vp64 sh = {{1,1}, {-1,-1}, {1,-1}, {-1,1}, {0,1}, {1,0}, {0,-1}, {-1,0}, {0,0}};
  for (auto &i : a) {
    for (auto &j : sh) {
      if ((x + j.fi == i.fi && y + j.se == i.se)) return false;
    }
  }

//  cout << x << ' ' << y << ln;

  vp64 mov = {{1, 1}, {-1,-1}, {1,-1}, {-1, 1}, {1, 0}, {0, 1}, {-1, 0}, {0, -1}};
  used.clear();
  used.resize(n, 0);
  for (auto &i : mov) inter(x, y, i.fi, i.se);

  bool good = true;
  for (auto &i : used) if (!i) good = false;
  return good;
}

int main() {
  fast_cin();

  ll q;
  cin >> q;
  while(q--) {
    cin >> m >> n;
    a.clear();
    a.resize(n);
    for (auto &i : a) cin >> i.fi >> i.se;
    for (auto &i : a) {
      i.fi--;
      i.se--;
    }
    ll ans = 0;
    forn(i,m) {
      forn(j,m) {
        if (intersection(i,j)) {
          ans++;
        }
      }
    } cout << ans << ln;
  }

}