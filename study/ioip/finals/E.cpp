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

p64 ans = {0, 0};

vv64 maxPath;

vv64 p;
vp64 cords;
v64 used;

struct r {
  ll x, y;
  r(ll x, ll y): x(x), y(y) {};
  r(p64 a, p64 b) {
    x = b.fi - a.fi;
    y = b.se - a.se;
  }

  ll operator* (r o) const {
    return x * o.x + y * o.y;
  }

  ll operator^ (r o) const {
    return x * o.y - o.x * y;
  }

  ll len() {
    return x * x + y * y;
  }
};

ld angle(r a, r b) {
  return atan2(a ^ b, a * b) * 180 / M_PI;
}



void dfs(ll v, vv64& path, ll curAns, ll prev, ll S) {


  if (curAns > ans.fi) {
    ans.fi = curAns;
    ans.se = path.size();
    maxPath = path;
  }

  for (ll I = 0; I < p[v].size(); I++) {
    ll i = p[v][I];
    if (used[i]) continue;
    for (ll J = 0; J < p[v].size(); J++) {
      ll j = p[v][J];
      if (used[j]) continue;
      for (ll K = 0; K < p[v].size(); K++) {
        ll k = p[v][K];
        if (used[k]) continue;
        if (i == j || j == k || i == k) continue;

        r L(cords[v], cords[i]);
        r B(cords[v], cords[j]);
        r R(cords[v], cords[k]);

        if (L.len() > B.len() || R.len() > B.len()) continue;


//        cout << v << ' ' << i << ' ' << j << ' ' << k << ln;
//        cout << B.x << ' ' << B.y << ln;
//        cout << angle(B, L) << ' ' << angle(B, R) << ln;

        if (angle(B, L) <= 0 || angle(B, L) >= 45) continue;
        if (angle(B, R) >= 0 || angle(B, R) <= -45) continue;

        r A(cords[v], cords[j]);
        r C(cords[prev], cords[v]);
        r D(cords[S], cords[v]);

        if (abs(angle(A, C)) >= 45) continue;
        if (abs(angle(A, D)) >= 45) continue;

        path.pb({i, j, k});
        used[i] = true;
        used[j] = true;
        used[k] = true;

        dfs(j, path, curAns + B.len(), v, S);

        path.pop_back();
        used[i] = false;
        used[j] = false;
        used[k] = false;

      }
    }
  }
}

int main() {
  fastCin();

  ll n, m, S;
  cin >> n >> m >> S; S--;

  cords.resize(n);
  p.resize(n);
  used.resize(n);
  used[S] = true;

  cin >> cords;

  forn(i,m) {
    ll x, y; cin >> x >> y; x--; y--;
    p[x].pb(y);
    p[y].pb(x);
  } vv64 pathH;
  dfs(S, pathH, 0, S, S);


  cout << ans.se << ' ' << ans.fi << ln;

  for (auto& i : maxPath) {
    cout << i[0] + 1 << ' ' << i[1] + 1 << ' ' << i[2] + 1 << ln;
  }


}