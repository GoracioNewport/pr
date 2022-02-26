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

vv64 p1, p2;
vp64 path;
v64 h1, h2;

struct SparceTableMin {
  vvp64 t;
  v64 leadPower, ind;
  ll n, maxLog;

  SparceTableMin(vp64& a, ll _n) {
    n = sz(a);
    leadPower.resize(n + 1);
    ind.resize(_n, -1);
    forsn(i,2,n + 1) leadPower[i] = leadPower[i / 2] + 1;
    maxLog = leadPower.back();

    forn(i,n) if (ind[a[i].se] == -1) ind[a[i].se] = i;

    t.resize(n, vp64 (maxLog + 1));
    forn(i,n) t[i][0] = a[i];

    for (ll len = 1; len <= maxLog; len++) {
      for (ll i = 0; i < n - (1 << len) + 1; i++) {
        t[i][len] = min(t[i][len - 1], t[i + (1 << (len - 1))][len - 1]);
      }
    }
  }

  p64 getLca(ll a, ll b) {
    ll i = ind[a];
    ll j = ind[b];
    if (i > j) swap(i, j);

    ll len = leadPower[j - i + 1];
    return min(t[i][len], t[j - (1 << len) + 1][len]);
  }
};

void dfs1(ll v, ll h = 0, ll P = -1) {
  path.pb({h, v});
  h1[v] = h;
  for (auto& u : p1[v]) {
    if (u == P) continue;
    dfs1(u, h + 1, v);
    path.pb({h, v});
  } path.pb({h, v});
}

void dfs2(ll v, ll h = 0, ll P = -1) {
  path.pb({h, v});
  h2[v] = h;
  for (auto& u : p2[v]) {
    if (u == P) continue;
    dfs2(u, h + 1, v);
    path.pb({h, v});
  } path.pb({h, v});
}

int main() {
  fastCin();

  ll n;
  cin >> n;
  p1.resize(n);
  p2.resize(n);
  h1.resize(n);
  h2.resize(n);

  p64 edg;

  forn(i,n - 1) {
    ll x; cin >> x; x--;
    p1[x].pb(i + 1);
    p1[i + 1].pb(x);
  } forn(i,n - 1) {
    ll x; cin >> x; x--;
    p2[x].pb(i + 1);
    p2[i + 1].pb(x);
    edg = {i + 1, x};
  } dfs1(0);
  SparceTableMin t1(path, n);
//  cout << path << ln;

  path.clear();
  dfs2(0);
  SparceTableMin t2(path, n);
//  cout << path << ln;

  if (n > 5000) {

    ll ind = 0;
    forn(i,n) if (sz(p1[i]) == n - 1) ind = i;

    forn(i,n) {
      if (ind == i) continue;

      auto y = t2.getLca(i, ind);
      ll dist2 = abs(h2[i] - h2[y.se]) + abs(h2[ind] - h2[y.se]);
      if (dist2 == 1) {
        cout << 2 << ln << ind + 1 << ' ' << i + 1 << ln;
        return 0;
      }
    }

    cout << 3 << ln << edg.fi + 1 << ' ' << edg.se + 1 << ln;

  } else {


    pair<ll, p64> ans = {INF, {INF, INF}};

    forn(i, n) {
      forsn(j, i + 1, n) {
        auto x = t1.getLca(i, j);
        auto y = t2.getLca(i, j);
        ll dist1 = abs(h1[i] - h1[x.se]) + abs(h1[j] - h1[x.se]);
        ll dist2 = abs(h2[i] - h2[y.se]) + abs(h2[j] - h2[y.se]);

        //      cout << i + 1 << ' ' << j + 1 << ' ' << ' ' << x.se + 1 << ' ' << y.se + 1 << ' ';
        //      cout << dist1 << ' ' << dist2 << ln;

        ans = min(ans, {dist1 + dist2, {i, j}});
      }
    } // cout << t1.ind << ln << t2.ind << ln;
    cout << ans.fi << ln << ans.se.fi + 1 << ' ' << ans.se.se + 1 << ln;
  }




}