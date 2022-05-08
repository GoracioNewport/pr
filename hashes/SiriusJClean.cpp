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
};

struct Tree {
    vector <node> t;
    v64 a;
    ll n;

    const ll NEUTRAL_ELEMENT = INF;

    Tree (v64 &_a) {
      a = _a;
      n = sz(a);
      t.assign(4 * n, {0,NEUTRAL_ELEMENT,0});
      build(0,0,n);
    }

    void build(ll v, ll l, ll r) { // OK!!!
      t[v].len = r - l;
      if (l + 1 == r) {
        t[v].hash = a[l];
        return;
      } ll m = (l + r) / 2;
      build(2 * v + 1, l, m);
      build(2 * v + 2, m, r);
      t[v].hash = ((t[2 * v + 1].hash * ks[t[2 * v + 2].len]) % mod + t[2 * v + 2].hash) % mod;
    }

    void push(ll v, ll l, ll r) { // OK!
      if (l + 1 == r || t[v].seg == NEUTRAL_ELEMENT) return;
      t[2 * v + 1].seg = t[v].seg;
      t[2 * v + 2].seg = t[v].seg;
      t[2 * v + 1].hash = (t[v].seg * ksum[t[2 * v + 1].len - 1]) % mod;
      t[2 * v + 2].hash = (t[v].seg * ksum[t[2 * v + 2].len - 1]) % mod;
      t[v].seg = NEUTRAL_ELEMENT;
    }

    void set(ll v, ll l, ll r, ll L, ll R, ll x) { // OK!
      push(v,l,r);
      if (l >= R || r <= L) return;
      if (l >= L && r <= R) { // OK
        t[v].seg = x;
        t[v].hash = (x * ksum[t[v].len - 1]) % mod;
        return;
      } ll m = (l + r) / 2;
      set(2 * v + 1, l, m, L, R, x);
      set(2 * v + 2, m, r, L, R, x);
      t[v].hash = ((t[2 * v + 1].hash * ks[t[2 * v + 2].len]) % mod + t[2 * v + 2].hash) % mod;
    }

    ll getHash(ll v, ll l, ll r, ll L, ll R) {
      push(v,l,r);
      if (l >= R || r <= L) return 0;
      if (l >= L && r <= R) return t[v].hash;

      ll m = (l + r) / 2;
      ll h1 = getHash(2 * v + 1, l, m, L, R);
      ll h2 = getHash(2 * v + 2, m, r, L, R);

      ll rLen = max((ll)0,min(R,r) - m);
      ll h = (((h1 * ks[rLen]) % mod) + h2) % mod;

      return h;
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

  cin >> m;
  Tree tree(a);
  while(m--) {
    ll t;
    cin >> t;
    ll l, r, k;
    cin >> l >> r >> k;
    if (!t) tree.set(0,0,n,l - 1,r,k);
    else {
      ll h1 = tree.getHash(0,0,n,l - 1,l + k - 1);
      ll h2 = tree.getHash(0,0,n,r - 1, r + k - 1);
      if (h1 == h2) cout << '+';
      else cout << '-';
    }
  }
}