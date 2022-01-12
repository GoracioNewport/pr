//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
//#pragma GCC optimize("unroll-loops")
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
//  fast_cin();

  string cmd;
  getline(cin, cmd);
  bool c, d, i, u;
  for (auto &j : cmd) {
    if (j == 'c') c = true;
    if (j == 'd') d = true;
    if (j == 'i') i = true;
    if (j == 'u') u = true;
  }

  string s;
  string prev = "#fhsdjfhjsdjkfhjksd24789&*%&$89tRGs(*&FG";
  string prevL = prev;
  vector <pair <pair <string, string>, ll>> a;
  while(getline(cin, s)) {

    if (s == "E") break;

    string l = s;
    for (auto &j : l) j = tolower(j);
    if (s == prev || (i && l == prevL)) {
      a[sz(a) - 1].se++;
    } else {
      a.pb({{s, l}, 1});
      prev = s;
      prevL = l;
    }
  }

  for (auto &j : a) {
    if (!(d && j.se == 1) && !(u && j.se > 1)) {
      if (c) cout << j.se << ' ';
      cout << j.fi.fi << endl;
    }
  }

}