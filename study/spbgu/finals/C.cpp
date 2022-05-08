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

string solve1(string s) {
  ll cntO = 0, cntZ = 0, n = sz(s);
  for (auto& c : s) {
    if (c == '0') cntZ++;
    else cntO++;
  }

  if (max(cntO, cntZ) == n) {
    if (cntO == n) {
      for (auto& c : s) c = '?';
      return s;
    } else {
      forn(i,n/2) s[i] = '?';
      return s;
    }
  }

  if (cntZ >= cntO) {
    for (auto& i : s) if (i == '0') i = '?';
    return s;
  } else {
    for (auto& i : s) if (i == '1') i = '?';
    return s;
  }
}

string solve2(string s) {
  ll cntO = 0, cntZ = 0, cntQ = 0, n = sz(s);
  for (auto& i : s) {
    if (i == '0') cntZ++;
    if (i == '1') cntO++;
    if (i == '?') cntQ++;
  } if (cntQ == n) {
    for (auto& i : s) i = '1';
    return s;
  } if (cntO == 0 && (cntZ >= cntQ)) {
    for (auto& i : s) i = '0';
    return s;
  } else {
    if (cntZ == 0) {
      for (auto& i : s) if (i == '?') i = '0';
    } else {
      for (auto& i : s) if (i == '?') i = '1';
    }
    return s;
  }
}

int main() {
  fastCin();

  ll t;
  cin >> t;
  while(t--) {
    string s;
    cin >> s;

    bool q = false, same = true;
    for (auto& c : s) if (c != s[0]) same = false;
    for (auto& c : s) if (c == '?') q = true;


    if (q) cout << solve2(s) << ln;
    else cout << solve1(s) << ln;

  }

}