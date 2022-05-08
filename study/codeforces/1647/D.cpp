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

void factorize(ll x, unordered_map <ll, ll>& z) {
  for (ll i = 2; i * i <= x; i++) {
    while(x % i == 0) {
      x /= i;
      z[i]++;
    }
  } if (x > 1) z[x]++;
}

bool isPrime(ll x) {
  for (ll i = 2; i * i <= x; i++) {
    if (x % i == 0) return false;
  } return true;
}

int main() {
  fastCin();

  ll t;
  cin >> t;
  while(t--) {
    ll x, d;
    cin >> x >> d;

    if (x % (d * d)) {
      cout << "nO" << ln;
      continue;
    }

    unordered_map <ll, ll> factD, factX;
    factorize(d, factD);
    factorize(x, factX);

    if (sz(factD) == 1) {

      ll P = (*factD.begin()).fi; // P

      if (factD[P] == 1) {
        ll s = 0;
        for (auto &j: factX) {
          if (j.fi == P) continue;
          s += j.se;
        }
        if (s >= 2) cout << "yEs" << ln;
        else cout << "NO" << ln;

      } else {
        if (factD[P] == 2) {
          if ((factX[P] % 2 == 1 && sz(factX) == 1) || (isPrime(x / (d * d)))) cout << "no" << ln;
          else cout << "YES" << ln;
        } else cout << (x == d * d ? "No" : "YeS") << ln;
      }
    } else cout << (x == d * d ? "No" : "YeS") << ln;







  }

}