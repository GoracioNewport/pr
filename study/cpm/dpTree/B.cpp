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

v64 a, sum, down, up; // числа в вершинах, сумма по всем поддеревьям, ответ для всех поддеревьев, ответ для предка
vv64 p;
ll globalSum;

p64 dfs(ll v, ll prev = -1) { // sum, ans

  p64 ans = {0, 0};
  for (auto& u : p[v]) {
    if (u == prev) continue;
    auto x = dfs(u, v);
    ans.fi += x.fi;
    ans.se += x.se;
  } ans.se += ans.fi;
  ans.fi += a[v];

  sum[v] = ans.fi;
  down[v] = ans.se;

  return {ans.fi, ans.se};
}

void dfsUp(ll v, ll prev = -1) {

  for (auto& u : p[v]) {
    if (u == prev) continue;
    up[u] = down[v] - (down[u] + sum[u]) + (globalSum - sum[u]) + (prev == -1 ? 0 : (down[prev] - (down[v] + sum[v])) + up[prev] + (globalSum - sum[v]));
    dfsUp(u, v);
  }

}

int main() {
  fastCin();

  ll n;
  cin >> n;
  p.resize(n);
  a.resize(n);
  sum.resize(n);
  down.resize(n);
  up.resize(n);

  for (auto& i : a) cin >> i;
  globalSum = accumulate(all(a), 0ll);
  forn(i,n - 1) {
    ll x, y; cin >> x >> y; x--; y--;
    p[x].pb(y);
    p[y].pb(x);
  } dfs(0);
  dfsUp(0);

  ll ans = 0;
  forn(i,n) {
//    cerr << i << ' ' << sum[i] << ' ' << down[i] << ' ' << up[i] << ln;
    ans = max(ans, up[i] + down[i]);
  } cout << ans << ln;

}