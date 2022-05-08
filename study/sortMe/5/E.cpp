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

struct xorArray {
  v64 d;
  ll n;

  xorArray(v64& a) {
    n = sz(a);
    d = {0};
    for (auto& i : a) d.pb(d.back() ^ i);
  }

  ll getXor(ll l, ll r) {
    return d[r + 1] ^ d[l];
  }
};

int main() {
  fastCin();

  ll n;
  cin >> n;
  v64 a(n), b(n);
  cin >> a >> b;

  xorArray A(a), B(b);

  ll ans = 0;
  v64 ansTuple(3);

  for (ll j = 1; j < n - 2; j++) {
    v64 z(5e3 * 2), ind(5e3 * 2);
    for (ll i = 0; i < j; i++) {
      ll x = A.getXor(0, i) ^ B.getXor(i + 1, j);
      z[x]++;
      ind[x] = i;
    }

    for (ll k = j + 1; k < n - 1; k++) {
      ll x = A.getXor(j + 1, k) ^ B.getXor(k + 1, n - 1);
      ans += z[x];
      if (z[x]) {
        ansTuple = {ind[x] + 1, j + 1, k + 1};
      }
    }
  } cout << ans << ln;

  if (ans) cout << ansTuple << ln;

}