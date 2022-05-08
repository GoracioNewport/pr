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

ll maxW = 2e4;
ll maxN = 2e3;

int main() {
  fastCin();

  ll t;
  cin >> t;

  v64 leadPower(maxN, INF);
  leadPower[1] = 0;
  for (ll i = 1; i < maxN; i++) {
    for (ll j = 1; j <= i; j++) {
      if (i + (i / j) >= maxN) continue;
      leadPower[i + (i / j)] = min(leadPower[i + (i / j)], leadPower[i] + 1);
    }
  }

//  cout << leadPower << ln;

  while(t--) {
    ll n, k;
    cin >> n >> k;
    k = min(k, maxW);
    v64 a(n, 1), b(n), c(n);
    cin >> b >> c;

    vp64 q(n); // <weight, cost>
    forn(i,n) q[i] = {leadPower[b[i]], c[i]};


//    cout << q << ln;
//    sort(all(q));

    vv64 dp(n + 1, v64(k + 1));



    for (ll i = 0; i < n; i++) {
      for (ll W = 0; W <= k; W++) {
        dp[i + 1][W] = dp[i][W];
        if (W >= q[i].fi && ((dp[i][W - q[i].fi] + q[i].se) > dp[i + 1][W])) dp[i + 1][W] = dp[i][W - q[i].fi] + q[i].se;
      }
    } cout << dp[n][k] << ln;
//    cout << dp << ln;


  }

}