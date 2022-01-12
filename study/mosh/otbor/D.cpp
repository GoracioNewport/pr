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

  ifstream in;
  ofstream out;
  in.open("C:/Users/bdfyl/CLionProjects/cf/mosh/otbor/d2.txt");
  out.open("C:/Users/bdfyl/CLionProjects/cf/mosh/otbor/d2ans.txt");
  ll t;
  in >> t;
  ll test = 1;
  while(t--) {
    cout << "Start Test " << test << ln;

    ll n, m;
    in >> n >> m;
    vv64 lines(n);
    vv64 rows(m);
    for (auto &i : lines) {
      ll x;
      in >> x;
      i.resize(x);
      for (auto &j : i) in >> j;
    } for (auto &i : rows) {
      ll x;
      in >> x;
      i.resize(x);
      for (auto &j : i) in >> j;
    } vv64 ans(n, v64 (m, 0));
    for (ll i = 0; i < n; i++) {
      ll ind = 0;
      for (ll j = 0; j < m; j++) {
        if (ind >= sz(lines[i])) break;
        if (lines[i][ind] == 0) {
          ind++;
          continue;
        } ans[i][j] = 1;
        lines[i][ind]--;
      }
    } for (auto &i : ans) {
      for (auto &j : i) out << j << ' ';
      out << ln;
    }

    cout << "Done Test " << test++ << ln;
  } in.close();
  out.close();

}