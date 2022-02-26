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

v64 p, r;

void init(ll n) {
  p.resize(n);
  r.resize(n);
  forn(i,n) p[i] = i;
}

ll getP(ll v) {
  return p[v] == v ? v : p[v] = getP(p[v]);
}

void unite(ll a, ll b) {
  a = getP(a);
  b = getP(b);
  if (r[b] > r[a]) swap(a, b);
  if (r[a] == r[b]) r[a]++;
  p[b] = a;
}

int main() {
  fastCin();

  ll n;
  cin >> n;
  vv64 p(n, v64(n));
  vector <pair <ll, p64>> edges;
  forn(i,n) {
    forn(j,n) {
      cin >> p[i][j];
      if (i < j) edges.pb({p[i][j], {i, j}});
    }
  } v64 b(n);
  forn(i,n) {
    cin >> b[i];
    edges.pb({b[i], {i, n}});
  } init(n + 1);
  sort(all(edges));

  ll anal = 0;

  for (auto& i : edges) {
    if (getP(i.se.fi) != getP(i.se.se)) {
      unite(i.se.fi, i.se.se);
      anal += i.fi;
    }
  } cout << anal << ln;

}