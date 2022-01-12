//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

// Author: @GoracioNewport

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
ll MOD = 1791791791;
double eps = 1e-12;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

int main() {
  fast_cin();

  string cmd;
  getline(cin, cmd);
  // cin.ignore();

  // cout << cmd << ln;

  bool c = false, d = false, I = false, u = false;
  for(auto &i : cmd) {
    // cout << i << ln;
    if (i == 'c') c = true;
    if (i == 'd') d = true;
    if (i == 'i') I = true;
    if (i == 'u') u = true;
  }

  vector <pair <string, string>> a; // fi - original, se - lower
  string s;
  while(getline(cin, s)) {
    pair <string, string> r = {s, s};
    if (I) {
      for (auto &i : s) i = tolower(i);
    } r.se = s;
    a.pb(r);
  } vector <pair <string, ll>> b;
  string prev = "#$*#@$*(@#*$(#@($*#$(#@*$@#($#", orig = "#$*#@$*(@#*$(#@($*#$(#@*$@#($#";

  for (auto &i : a) {
    if (i.se == prev) {
      b[sz(b) - 1].se++;
    } else {
      prev = i.se;
      orig = i.fi;
      b.pb({orig, 1});
    }
  }

  // cout << c << d << I << u << ln;

  for (auto &i : b) {
    if ((d && (i.se == 1) || (u && (i.se != 1)))) continue;
    if (c) cout << i.se << ' ';
    cout << i.fi << ln;
  }

}
