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

ll code(char c) {
  if (c == '#') return 0;
  if (c == '$') return 1;
  if (isdigit(c)) return c - '0' + 2;
  if (c - 'Z' - 1 < 0) return c - 'A' + 12;
  else return c - 'a' + 12 + 26;
}

int main() {
  fastCin();

  ll k, m;
  cin >> k >> m;

  v64 ans(m, -1);

  forn(z,m) {
    string s1, s2;
    cin >> s1 >> s2;

    v64 a, b;
    for (auto& i : s1) a.pb(code(i));
    for (auto& i : s2) b.pb(code(i));

    forn(i,k * 6) {
      if (a == b) {
        ans[z] = i;
        break;
      } if (a[0] < 32) {
        ll x = 0;
        for (ll j = k - 1; j >= 0; j--) {
          a[j] *= 2;
          a[j] += x;

          x = a[j] / 64;
          a[j] %= 64;
        }
      } else {
        a[0] -= 32;
        a[a.size() - 1] += 1;

        ll x = 0;
        for (ll j = k - 1; j >= 0; j--) {
          a[j] *= 2;
          a[j] += x;

          x = a[j] / 64;
          a[j] %= 64;
        }

        for (ll j = k - 1; j >= 0; j--) {
          if (a[j]) {
            a[j] -= 1;
            break;
          } a[j] = 63;
        }
      }
    }


  }

  for (auto& i : ans) cout << i << ln;

}