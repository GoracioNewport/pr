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

enum { BEGIN, DOT, END };

struct block {
  ll x, y1, y2, ind, type;
};

bool comp(block& a, block& b) {
  if (a.x != b.x) return a.x < b.x;
  else return a.type < b.type;
}

struct Tree {

  ll n;
  v64 t;

  Tree (ll _n) {
    n = _n;
    t.assign(4 * n, 0);
  }

  void setX(ll v, ll l, ll r, ll i, ll x) {
    if (l + 1 == r) {
      t[v] += x;
      return;
    } ll m = (l + r) / 2;
    if (i < m) setX(2 * v + 1, l, m, i, x);
    else setX(2 * v + 2, m, r, i, x);
    t[v] = t[2 * v + 1] + t[2 * v + 2];
  }

  ll getSum(ll v, ll l, ll r, ll L, ll R) {
    if (l >= L && r <= R) return t[v];
    if (l >= R || r <= L) return 0;
    ll m = (l + r) / 2;
    return getSum(2 * v + 1, l, m, L, R) + getSum(2 * v + 2, m, r, L, R);
  }

};

bool DEBUG = false;

int main() {
  fast_cin();

  ll n;
  cin >> n;
  vp64 q(n);
  vector <block> scan;
  v64 ys;
  forn(i,n) {
    ll x, y;
    cin >> x >> y;
    q[i].fi = x;
    q[i].se = y;
    ys.pb(y);
  } ll m;
  cin >> m;
  vector <pair <pair <ll, ll>, pair <ll, ll>>> p(m);
  forn(i,m) {
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    p[i].fi.fi = x1;
    p[i].fi.se = y1;
    p[i].se.fi = x2;
    p[i].se.se = y2;
    ys.pb(y1);
    ys.pb(y2);
  } v64 ans(m);
  sort(all(ys));
  auto it = unique(all(ys));
  ys.erase(it, ys.end());

  if (DEBUG) {
    for (auto& i : ys) cout << i << ' ';
    cout << ln;
  }


  map <ll, ll> cords;
  forn(i,sz(ys)) cords[ys[i]] = i;
  ll N = sz(cords);

  forn(i,n) {
    ll x = q[i].fi;
    ll y = cords[q[i].se];
    scan.pb({x, y, y, i, DOT});
  } forn(i,m) {
    ll x1 = p[i].fi.fi;
    ll y1 = cords[p[i].fi.se];
    ll x2 = p[i].se.fi;
    ll y2 = cords[p[i].se.se];
    scan.pb({x1, y1, y2, i, BEGIN});
    scan.pb({x2, y1, y2, i, END});
  } sort(all(scan), comp);

  Tree tree(N);
  for (auto& i : scan) {
    if (i.type == DOT) {
      if (DEBUG) cout << "Dot add on " << i.y1 << ' ' << i.x << ln;
      tree.setX(0, 0, N,  i.y1, 1);
    } else if (i.type == BEGIN) {
      if (DEBUG) cout << "Sum query (-) on " << i.y1 << ' ' << i.y2 << ' ' << i.ind << ' ' << i.x << ln;
      ans[i.ind] -= tree.getSum(0, 0, N, i.y1, i.y2 + 1);
    } else {
      if (DEBUG) cout << "Sum query (+) on " << i.y1 << ' ' << i.y2 << ' ' << i.ind << ' ' << i.x << ln;
      ans[i.ind] += tree.getSum(0, 0, N, i.y1, i.y2 + 1);
    }
  } for (auto &i : ans) cout << i << ln;


  if (DEBUG) {
    for (auto &i: scan) cout << i.x << ' ' << i.type << ' ' << i.y1 << ' ' << i.y2 << ' ' << ln;
    cout << ln;
  }


}