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

vector <vector <pair <ll, p64>>> p;
v64 used, disabled;

void dfs(ll v, ll bit) {
  used[v] = true;
  for (auto& [u, x]: p[v]) {
    if (used[u] || ((1ll << bit) & (x.fi)) || disabled[x.se]) continue;
    dfs(u, bit);
  }
}

int main() {
  fastCin();

  ll t;
  cin >> t;
  while(t--) {
    ll n, m;
    cin >> n >> m;
    used.clear();
    p.clear();
    disabled.clear();

    used.resize(n);
    p.resize(n);
    disabled.resize(m);
    v64 edges;

    forn(i,m) {
      ll x, y, w;
      cin >> x >> y >> w; x--; y--;
      p[x].pb({y, {w, i}});
      p[y].pb({x, {w, i}});
      edges.pb(w);
    } ll ans = 0;

    for (ll bit = 30; bit >= 0; bit--) {
      fill(all(used), 0);
      dfs(0, bit);
      if (accumulate(all(used), 0ll) == n) {
        forn(i,m) if ((1ll << bit) & edges[i]) disabled[i] = true;
      } else ans += (1ll << bit);
    } cout << ans << ln;
  }

}