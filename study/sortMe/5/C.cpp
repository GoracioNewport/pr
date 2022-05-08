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

struct sparceTableAnd {
  vv64 t;
  v64 leadPower;
  ll n, maxLog;

  sparceTableAnd(v64& a) {
    n = sz(a);

    leadPower.resize(n + 1);
    forsn(i,2,n + 1) leadPower[i] = leadPower[i / 2] + 1;
    maxLog = leadPower.back();

    t.resize(n, v64(maxLog + 1));

    forn(i,n) t[i][0] = a[i];

    for (ll len = 1; len <= maxLog; len++) {
      for (ll i = 0; i < n - (1 << len) + 1; i++) {
        t[i][len] = (t[i][len - 1] & t[i + (1 << (len - 1))][len - 1]);
      }
    }
  }

  ll getAnd(ll l, ll r) {
    ll len = leadPower[r - l + 1];
    return (t[l][len] & t[r - (1 << len) + 1][len]);
  }
};

int main() {
  fastCin();

  ll n;
  cin >> n;
  v64 a(n);
  cin >> a;

  sparceTableAnd t(a);

  ll logN = 32;

  vv64 inds(logN, v64());

  forn(i,n) {
    bitset <32> x(a[i]);
    forn(j,logN) if (!x[j]) inds[j].pb(i);
  } forn(i,logN) inds[i].pb(n);

  ll ans = 0;

  forn(l,n) {
    bitset <32> x(a[l]);
    v64 b;
    forn(j,logN) {
      if (x[j]) {
        ll i = *upper_bound(all(inds[j]), l);
        b.pb(i);
      }
    }

//    cout << a[l] << "   " << b << ln;

    for (auto& i : b) {
      ll r = i - 1;
      ans = max(ans, t.getAnd(l, r) * (r - l + 1));
    }
  } cout << ans << ln;


}