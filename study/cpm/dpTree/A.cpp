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

vv64 p;
ll n, k;

pair <v64, ll> dfs(ll v, ll prev = -1) {
  if (sz(p[v]) == 1 && p[v][0] == prev) {
    v64 dist(k + 1);
    dist[0] = 1;
    return {dist, 0};
  }

  ll ans = 0;
  vv64 s;

  for (auto& u : p[v]) {
    if (u == prev) continue;
    auto x = dfs(u, v);
    for (ll i = k; i > 0; i--) x.fi[i] = x.fi[i - 1];
    x.fi[0] = 0;
    s.pb(x.fi);
    ans += x.se;
  } v64 sum(k + 1);

  for(auto& i : s) forn(j,k + 1) sum[j] += i[j];
  sum[0] = 1;

  ans += sum[k] * 2;

  for(auto& i : s) forsn(j,1,k) ans += i[j] * (sum[k - j] - i[k - j]);
  return {sum, ans};
}

int main() {
  fastCin();

  cin >> n >> k;
  p.resize(n, v64());
  forn(i,n - 1) {
    ll x, y; cin >> x >> y; x--; y--;
    p[x].pb(y);
    p[y].pb(x);
  } cout << dfs(0).se / 2 << ln;

}