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

ll mod = 1e9 + 7;
ld eps = 1e-12;
ll INF = 2e18;

ll cnt = 0, n, ans = 0, s = 0;
vv64 p;
v64 a, fact;

ll binPow(ll a, ll n) {
  if (n == 0) return 1;
  else if (n % 2) return binPow(a, n - 1) * a % mod;
  else {
    ll b = binPow(a, n / 2);
    return b * b % mod;
  }
}

ll rev(ll a) {
  return binPow(a, mod - 2);
}

ll cnk(ll n, ll k) {
  return (fact[n] * rev(fact[n - k]) % mod);
}

void dfs(ll v, ll H = 0) {
  if ((H + 1) > cnt) return;

  ll x = cnk(cnt - 1, H) * fact[n - (H + 1)] % mod * s % mod;
//  cout << v << ' ' << H << ' ' << x << ' ' << cnk(cnt - 1, H) << ' ' << fact[n - (H + 1)] << ln;

  ans = (ans + x) % mod;

  for (auto& u : p[v]) dfs(u, H + 1);
}

int main() {
  fastCin();

  cin >> n;
  p.resize(n);
  a.resize(n);
  fact.resize(n + 10);
  fact[0] = fact[1] = 1;
  forsn(i,2,n + 10) fact[i] = fact[i - 1] * i % mod;

  forn(i,n - 1) {
    ll x; cin >> x; x--;
    p[x].pb(i + 1);
  } cin >> a;
  sort(all(a));

  for (auto& i : a) {
    cnt += (i >= 0);
    if (i >= 0) s = (s + i) % mod;
  }
  dfs(0);
  cout << ans << ln;

}