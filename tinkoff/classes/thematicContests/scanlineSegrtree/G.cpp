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
#define INF (ll)2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

v64 buf(26);

const ll ALPH_SIZE = 26;

struct block {
    v64 a;
    ll seg;
};

struct Tree {
    ll n;
    vector <block> t;
    v64 a;

    Tree (v64& _a) {
      a = _a;
      n = sz(a);
      t.assign(4 * n, {v64 (ALPH_SIZE), INF});
      build(0, 0, n);
    }

    void build(ll v, ll l, ll r) {
      if (l + 1 == r) {
        t[v].a[a[l]] = 1;
        t[v].seg = a[l];
        return;
      } ll m = (l + r) / 2;
      build(2 * v + 1, l, m);
      build(2 * v + 2, m, r);
      forn(i,ALPH_SIZE) t[v].a[i] = t[2 * v + 1].a[i] + t[2 * v + 2].a[i];
    }

    void push(ll v, ll l, ll r) {
      if (l + 1 == r || t[v].seg == INF) return;
      t[2 * v + 1].seg = t[2 * v + 2].seg = t[v].seg;
      forn(i,ALPH_SIZE) t[v].a[i] = t[2 * v + 1].a[i] = t[2 * v + 2].a[i] = 0;
      ll m = (l + r) / 2;
      t[v].a[t[v].seg] = r - l;
      t[2 * v + 1].a[t[v].seg] = m - l;
      t[2 * v + 2].a[t[v].seg] = r - m;

      t[v].seg = INF;
    }

    void count(ll v, ll l, ll r, ll L, ll R) {
      push(v, l, r);
      if (l >= L && r <= R) {
        if (t[v].seg != INF) buf[t[v].seg] += (r - l);
        else forn(i,ALPH_SIZE) buf[i] += t[v].a[i];
        return;
      } if (l >= R || r <= L) return;
      ll m = (l + r) / 2;
      count(2 * v + 1, l, m, L, R);
      count(2 * v + 2, m, r, L, R);
    }

    void setSeg(ll v, ll l, ll r, ll L, ll R, ll x) {
      push(v, l, r);
      if (l >= L && r <= R) {
        t[v].seg = x;
        forn(i,ALPH_SIZE) t[v].a[i] = 0;
        t[v].a[x] = (r - l);
        return;
      } if (l >= R || r <= L) return;
      ll m = (l + r) / 2;
      setSeg(2 * v + 1, l, m, L, R, x);
      setSeg(2 * v + 2, m, r, L, R, x);
//      if (t[2 * v + 1].seg != INF && (t[2 * v + 1].seg == t[2 * v + 2].seg)) t[v].seg = t[2 * v + 1].seg;
      forn(i,ALPH_SIZE) t[v].a[i] = t[2 * v + 1].a[i] + t[2 * v + 2].a[i];
    }

    ll getX(ll v, ll l, ll r, ll i) {
      push(v, l, r);
      if (l + 1 == r) return t[v].seg;
      ll m = (l + r) / 2;
      if (i < m) return getX(2 * v + 1, l, m, i);
      else return getX(2 * v + 2, m, r, i);
    }




};

int main() {
  fast_cin();

  ll n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  v64 a(n);
  forn(i,n) a[i] = (s[i] - 'a');
  Tree tree(a);

  while(q--) {
    ll l, r, k;
    cin >> l >> r >> k;
    forn(i,ALPH_SIZE) buf[i] = 0;
    tree.count(0, 0, n, l - 1, r);
//    for (auto& i : buf) cout << i << ' ';
//    cout << ln;
    if (k) { // Возрастающий
      ll x = l - 1;
      forn(i,ALPH_SIZE) {
        if (buf[i] == 0) continue;
        tree.setSeg(0, 0, n, x, x + buf[i], i);
        x += buf[i];
      }
    } else { // Убывающий
      ll x = l - 1;
      for (ll i = ALPH_SIZE - 1; i >= 0; i--) {
        if (buf[i] == 0) continue;
        tree.setSeg(0, 0, n, x, x + buf[i], i);
        x += buf[i];
      }
    }
  } forn(i,n) a[i] = tree.getX(0, 0, n, i);
  for (auto& i : a) cout << (char)('a' + i);
  cout << ln;


}