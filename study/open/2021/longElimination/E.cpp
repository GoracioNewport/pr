// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
// #pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

// Author: @GoracioNewport

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<int> v32;
typedef vector<ll> v64;
typedef vector<ld> vdd;
typedef vector<v32> vv32;
typedef vector<v64> vv64;
typedef vector<vdd> vvdd;
typedef vector<p64> vp64;
typedef vector<vp64> vvp64;

#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define ln "\n"
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define fastCin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

istream& operator>>(istream& in, v64& a) {
  for (auto& i : a) in >> i;
  return in;
}

istream& operator>>(istream& in, vp64& a) {
  for (auto& i : a) in >> i.fi >> i.se;
  return in;
}

istream& operator>>(istream& in, vv64& a) {
  for (auto& i : a) for (auto& j : i) in >> j;
  return in;
}

istream& operator>>(istream& in, vvp64& a) {
  for (auto& i : a) for (auto& j : i) in >> j.fi >> j.se;
  return in;
}

ostream& operator<<(ostream& out, v64& a) {
  for (auto& i : a) out << i << ' ';
  return out;
}

ostream& operator<<(ostream& out, vp64& a) {
  for (auto& i : a) out << i.fi << ' ' << i.se << ln;
  return out;
}

ostream& operator<<(ostream& out, vv64& a) {
  for (auto& i : a) {
    for (auto& j : i) out << j << ' ';
    cout << ln;
  } return out;
}

ostream& operator<<(ostream& out, vvp64& a) {
  for (auto& i : a) {
    for (auto& j : i) out << j.fi << ' ' << j.se << ln;
    cout << ln;
  } return out;
}

ll mod = 1791791791;
ld eps = 1e-12;
ll INF = 2e18;

struct Node {
  ll And, Or, Xor;
};

struct Tree {
  vector <Node> t;
  v64 a;
  ll n;

  Tree (v64& _a) {
    a = _a;
    n = sz(a);
    t.assign(4 * n, {0, 0, 0});
    build(0, 0, n);
  }

  void build(ll v, ll l, ll r) {
    if (l + 1 == r) {
      t[v].And = t[v].Xor = t[v].Or = a[l];
      return;
    } ll m = (l + r) / 2;
    build(2 * v + 1, l, m);
    build(2 * v + 2, m, r);
    t[v].And = t[2 * v + 1].And & t[2 * v + 2].And;
    t[v].Or = t[2 * v + 1].Or | t[2 * v + 2].Or;
    t[v].Xor = t[2 * v + 1].Xor ^ t[2 * v + 2].Xor;
  }

  void updXor(ll v, ll l, ll r, ll L, ll R, ll x) {
    if (l >= L && r <= R) {
      t[v].Xor ^= x;
      return;
    } if (l >= R || r <= L) return;
    ll m = (l + r) / 2;
    updXor(2 * v + 1, l, m, L, R, x);
    updXor(2 * v + 2, m, r, L, R, x);
    t[v].Xor = t[2 * v + 1].Xor ^ t[2 * v + 2].Xor;
  }

  ll getAnd(ll v, ll l, ll r, ll L, ll R) {
    if (l >= L && r <= R) return t[v].And;
    if (l >= R || r <= L) return LLONG_MAX;
    ll m = (l + r) / 2;
    return getAnd(2 * v + 1, l, m, L, R) & getAnd(2 * v + 2, m, r, L, R);
  }

  ll getOr(ll v, ll l, ll r, ll L, ll R) {
    if (l >= L && r <= R) return t[v].Or;
    if (l >= R || r <= L) return 0;
    ll m = (l + r) / 2;
    return getOr(2 * v + 1, l, m, L, R) | getOr(2 * v + 2, m, r, L, R);
  }

  ll getXor(ll v, ll l, ll r, ll L, ll R) {
    if (l >= L && r <= R) return t[v].Xor;
    if (l >= R || r <= L) return 0;
    ll m = (l + r) / 2;
    return getXor(2 * v + 1, l, m, L, R) ^ getXor(2 * v + 2, m, r, L, R);
  }

};

void solve(ll n, ll q, v64& a) {
  Tree t(a);
  while(q--) {
    string c, d;
    cin >> c >> d;
    ll l, r; cin >> l >> r; l--;
    if (c[0] == 'g') {
      ll res;
      if (d[0] == 'a') res = t.getAnd(0, 0, n, l, r);
      if (d[0] == 'o') res = t.getOr(0, 0, n, l, r);
      if (d[0] == 'x') res = t.getXor(0, 0, n, l, r);
      cout << res << ln;
    } else {
      ll x; cin >> x;
      if (d[0] == 'a') t.updXor(0, 0, n, l, r, x);

    }
  }
}

int main() {
  fastCin();

  ll n, q;
  cin >> n >> q;
  v64 a(n);
  cin >> a;

  if (n > 1000 || q > 1000) {
    solve(n, q, a);
    return 0;
  }

  while(q--) {
    string c, d;
    cin >> c >> d;
    ll l, r; cin >> l >> r; l--; r--;
    if (c[0] == 'g') {
      ll res = a[l];
      for (ll i = l + 1; i <= r; i++) {
        if (d[0] == 'a') res &= a[i];
        if (d[0] == 'o') res |= a[i];
        if (d[0] == 'x') res ^= a[i];
      } cout << res << ln;
    } else {
      ll x; cin >> x;
      for (ll i = l; i <= r; i++) {
        if (d[0] == 'a') a[i] &= x;
        if (d[0] == 'o') a[i] |= x;
        if (d[0] == 'x') a[i] ^= x;
      }
    }
  }

}