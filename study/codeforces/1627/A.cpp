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
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;

ll mod = 1791791791;
double eps = 1e-12;
ll INF = 2e18;

#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define ln "\n"
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

istream &operator>>(istream& in, v64& a) {
  for (auto& i : a) in >> i;
  return in;
}

istream &operator>>(istream& in, vp64& a) {
  for (auto& i : a) in >> i.fi >> i.se;
  return in;
}

istream &operator>>(istream& in, vv64& a) {
  for (auto& i : a) for (auto& j : i) cin >> j;
  return in;
}

istream &operator>>(istream& in, vvp64& a) {
  for (auto& i : a) for (auto& j : i) in >> j.fi >> j.se;
  return in;
}

int main() {
  fast_cin();

  ll t;
  cin >> t;
  while(t--) {
    ll n, m, r, c;
    cin >> n >> m >> r >> c; r--; c--;

    vector <string> q(n);
    for (auto& i : q) cin >> i;

    bool h = false, w = false, match = false, one = false;
    forn(i,n) {
      forn(j,m) {
        if (q[i][j] == 'B') {
          one = true;
          if (i == r) h = true;
          if (j == c) w = true;
        } if (i == r && j == c && q[i][j] == 'B') match = true;
      }
    } if (match) cout << 0 << ln;
    else if (h || w) cout << 1 << ln;
    else if (one) cout << 2 << ln;
    else cout << -1 << ln;
  }

}