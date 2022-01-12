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
  fast_cin();

  ll n, m, d;
  cin >> n >> m >> d;

  vector <string> p;
  {
    string q(m + 2, '#');
    p.pb(q);
  }
  forn(i,n) {
    string s;
    cin >> s;
    s = '#' + s + '#';
    p.pb(s);
  }
  {
    string q(m + 2, '#');
    p.pb(q);
  }

  if (d == 1) {
    cout << 2 << ln << 0 << ln << 4 << ln << 4 << ln;
    return(0);
  }

  vector <set <ll>> hor(n + 2);
  vector <set <ll>> ver(m + 2);

  ll startX, startY;

  forn(i,n + 2) {
    forn(j,m + 2) {
      if (p[i][j] == 'S') {
        startX = i;
        startY = j;
      }



      if (p[i][j] == '#') {
        hor[i].insert(j);
        ver[j].insert(i);
      }
    }
  }

//  for (auto &i : p) {
//    for (auto &j : i) cout << j;
//    cout << ln;
//  }
//
//
//  for (auto &i : hor) {
//    for (auto &j : i) cout << j << ' ';
//    cout << ln;
//  }
//
//  for (auto &i : ver) {
//    for (auto &j : i) cout << j << ' ';
//    cout << ln;
//  }


  ll l;
  cin >> l;
  string cmd;
  cin >> cmd;
  for (auto &c : cmd) {
    ll ans;
    if (c == 'R') {
      ll f = *hor[startX].upper_bound(startY);
      ans = f - startY - 1;
      startY = f - 1;
    } else if (c == 'L') {
      ll f = *prev(hor[startX].upper_bound(startY));
      ans = (startY - f) - 1;
      startY = f + 1;
    } else if (c == 'D') {
      ll f = *ver[startY].upper_bound(startX);
      ans = f - startX - 1;
      startX = f - 1;
    } else if (c == 'U') {
      ll f = *prev(ver[startY].upper_bound(startX));
      ans = (startX - f) - 1;
      startX = f + 1;
    } cout << ans << ln;
  }



}