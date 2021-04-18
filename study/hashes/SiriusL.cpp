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

const ll mod = 1791791791, k = 239;

v64 ks, h, ksum;

struct node {
  ll len;
  ll seg;
  ll hash;
  ll l;
  ll r;
  pair <string, v64> history;
};

struct Tree {
  vector <node> t;
  v64 a;
  ll n;

  const ll NEUTRAL_ELEMENT = INF;

  Tree (v64 &_a) {
    a = _a;
    n = sz(a);
    t.assign(4 * n, {0,NEUTRAL_ELEMENT,0, -1, -1});
    build(0,0,n);
  }

  void build(ll v, ll l, ll r) { // OK!!!
    t[v].len = r - l;
    t[v].l = l;
    t[v].r = r - 1;
    if (l + 1 == r) {
      t[v].hash = a[l];
      t[v].history.fi = to_string(a[l]);
      t[v].history.se = {0};
      return;
    } ll m = (l + r) / 2;
    build(2 * v + 1, l, m);
    build(2 * v + 2, m, r);
//    cout << "Building " << v << ' ' << l << ' ' << r - 1 << ln;
//    cout << "Left Hash: " << t[2 * v + 1].hash << ln;
//    for (auto &i : t[2 * v + 1].history.se) cout << i << ' ';
//    cout << ln;
//    cout << "Right Hash: " << t[2 * v + 2].hash << ln;
//    for (auto &i : t[2 * v + 2].history.se) cout << i << ' ';
//    cout << ln;
    t[v].hash = ((t[2 * v + 1].hash * ks[t[2 * v + 2].len]) % mod + t[2 * v + 2].hash) % mod;
//    cout << "MyHash: " << t[v].hash << ln;
    t[v].history.fi = t[2 * v + 1].history.fi + t[2 * v + 2].history.fi;
    t[v].history.se.clear();
    for (auto &i : t[2 * v + 1].history.se) t[v].history.se.pb(i + t[2 * v + 2].len);
    for (auto &i : t[2 * v + 2].history.se) t[v].history.se.pb(i);
//    for (auto &i : t[v].history.se) cout << i << ' ';
//    cout << ln;
  }

  void push(ll v, ll l, ll r) { // OK!
    if (l + 1 == r || t[v].seg == NEUTRAL_ELEMENT) return;
//    cout << "PUSHING " << v << ' ' << t[v].seg << ' ' << t[v].history.fi << ln;
//    cout << "MyHash: " << t[v].hash << ln;
    t[2 * v + 1].seg = t[v].seg;
    t[2 * v + 2].seg = t[v].seg;
    t[2 * v + 1].hash = (t[v].seg * ksum[t[2 * v + 1].len - 1]) % mod;
    t[2 * v + 2].hash = (t[v].seg * ksum[t[2 * v + 2].len - 1]) % mod;
    t[2 * v + 1].history.fi.clear();
    forn(i,t[2 * v + 1].len) t[2 * v + 1].history.fi += to_string(t[v].seg);
    t[2 * v + 2].history.fi.clear();
    forn(i,t[2 * v + 2].len) t[2 * v + 2].history.fi += to_string(t[v].seg);
    t[2 * v + 1].history.se.clear();
    rforn(i,t[2 * v + 1].len - 1) t[2 * v + 1].history.se.pb(i);
    t[2 * v + 2].history.se.clear();
    rforn(i,t[2 * v + 2].len - 1) t[2 * v + 2].history.se.pb(i);
//    cout << t[2 * v + 1].hash << ' ' << t[2 * v + 1].history.fi << ln;
//    for (auto &i : t[2 * v + 2].history.se) cout << i << ' ';
//    cout << ln;
//    cout << t[2 * v + 1].hash << ' ' << t[2 * v + 1].history.fi << ln;
//    for (auto &i : t[2 * v + 2].history.se) cout << i << ' ';
//    cout << ln;
    t[v].seg = NEUTRAL_ELEMENT;
  }

  void set(ll v, ll l, ll r, ll L, ll R, ll x) { // OK!
    push(v,l,r);
    if (l >= R || r <= L) return;
    if (l >= L && r <= R) { // OK
//      cout << l << ' ' << r - 1 << " Whole segment set to " << x << ln;
      t[v].seg = x;
      t[v].hash = (x * ksum[t[v].len - 1]) % mod;
//      cout << t[v].hash << ln;
      t[v].history.fi.clear();
      forn(i,t[v].len) t[v].history.fi += to_string(x);
//      cout << t[v].history.fi << ln;
//      for (auto &i : t[v].history.se) cout << i << ' ';
//      cout << ln;
      return;
    } ll m = (l + r) / 2;
    set(2 * v + 1, l, m, L, R, x);
    set(2 * v + 2, m, r, L, R, x);
    t[v].hash = ((t[2 * v + 1].hash * ks[t[2 * v + 2].len]) % mod + t[2 * v + 2].hash) % mod;
    t[v].history.fi = t[2 * v + 1].history.fi + t[2 * v + 2].history.fi;
    t[v].history.se.clear();
    for (auto &i : t[2 * v + 1].history.se) t[v].history.se.pb(i + t[2 * v + 2].len);
    for (auto &i : t[2 * v + 2].history.se) t[v].history.se.pb(i);
//    cout << "Updating " << v << ' ' << l << ' ' << r - 1 << ln;
//    cout << "Left Hash: " << t[2 * v + 1].hash << ln;
//    for (auto &i : t[2 * v + 1].history.se) cout << i << ' ';
//    cout << ln;
//    cout << "Right Hash: " << t[2 * v + 2].hash << ln;
//    for (auto &i : t[2 * v + 2].history.se) cout << i << ' ';
//    cout << ln;
//    for (auto &i : t[v].history.se) cout << i << ' ';
//    cout << ln;
//    cout << "MyHash: " << t[v].hash << ln;
  }

  pair <ll, pair <string, v64>> getHash(ll v, ll l, ll r, ll L, ll R) {
//    cout << "GetHash " << l << ' ' << r - 1 << ln;
    push(v,l,r);
    if (l >= R || r <= L) return {0, {"", {}}};
    if (l >= L && r <= R) {
//      cout << "Whole Segment: " << l << ' ' << r - 1 << ln;
//      cout << "Hash: " << t[v].hash << ln << ln;
      return {t[v].hash, {t[v].history.fi, t[v].history.se}};
    }
    ll m = (l + r) / 2;
    pair <ll, pair <string, v64>> f1 = getHash(2 * v + 1, l, m, L, R);
    pair <ll, pair <string, v64>> f2 = getHash(2 * v + 2, m, r, L, R);
    ll h1 = f1.fi;
    ll h2 = f2.fi;

    cout << "Partial Segment: " << l << ' ' << r - 1 << ln;
    cout << "Left: " << h1 << ' ' << l << ' ' << m - 1 << ln;
    cout << "Right: " << h2 << ' ' << m << ' ' << r - 1 << ln;
//    cout << "Left * " << ks[m - L + 1] << ln;

    ll rLen = max((ll)0,R - m);
    ll h = (((h1 * ks[rLen]) % mod) + h2) % mod;

    cout << "Length of right segment: " << rLen << ln;
    cout << "Total Hash: " << h << ln << ln;

    pair <ll, pair <string, v64>> ans;
    ans.fi = h;
    ans.se.fi = f1.se.fi + f2.se.fi;
    for (auto &i : f1.se.se) ans.se.se.pb(i + t[2 * v + 2].len);
    for (auto &i : f2.se.se) ans.se.se.pb(i);
    return ans;
  }

};


int main() {
  fast_cin();
  ll n, m;
  cin >> n;

  v64 a(n);
  for (auto &i : a) cin >> i;

  h.resize(n, a[0]);
  ks.resize(n + 1, 1);
  ksum.resize(n + 1, 1);

  forsn(i,1, n) h[i] = (h[i - 1] * k + a[i]) % mod;
  forn(i,n) ks[i + 1] = (ks[i] * k) % mod;
  forsn(i,1,n + 1) ksum[i] = (ksum[i - 1] + ks[i]) % mod;

//  for (auto &i : h) cout << i << ' ';
//  cout << ln;
//  for (auto &i : ks) cout << i << ' ';
//  cout << ln;
//  for (auto &i : ksum) cout << i << ' ';
//  cout << ln;

  cin >> m;
  Tree tree(a);
  while(m--) {
//    cout << "###" << ln;
    ll t;
    cin >> t;
    ll l, r, k;
    cin >> l >> r >> k;
    if (!t) tree.set(0,0,n,l - 1,r,k);
    else {
      cout << "-----------CALCULATING FIRST HASH-------------" << ln;
      auto p1 = tree.getHash(0,0,n,l - 1,l + k - 1);
      cout << "-----------CALCULATING SECOND HASH-------------" << ln;
      auto p2 = tree.getHash(0,0,n,r - 1, r + k - 1);
      ll h1 = p1.fi;
      ll h2 = p2.fi;
      cout << h1 << ln;
      for (auto &i : p1.se.fi) cout << i;
      cout << ln;
      for (auto &i : p1.se.se) cout << i << ' ';
      cout << ln;
      cout << h2 << ln;
      for (auto &i : p2.se.fi) cout << i;
      cout << ln;
      for (auto &i : p2.se.se) cout << i << ' ';
      cout << ln;
//      if (h1 == h2) cout << '+';
//      else cout << '-';
    }
  }
}