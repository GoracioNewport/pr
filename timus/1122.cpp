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

vv64 mask(3, v64 (3, 0));
vv64 p(4, v64(4, 0));

ll cnt = INF;
const ll maxN = 6;
ll s = 0;

bool outOfRange(ll i, ll j) {
  return (i < 0 || i > 3 || j < 0 || j > 3);
}


ll apply(ll i, ll j) {
  ll ans = 0;
  forn(x,3) {
    forn(y,3) {
      if (!outOfRange(i + x, j + y) && mask[x][y]) {
        if (p[i + x][j + y]) ans--;
        else ans++;
        p[i + x][j + y] = !p[i + x][j + y];
      }
    }
  } return ans;
}

void f(ll c) {
//  cout << c << "---" << ln;
  if (c == maxN) return;
  if (s == 0 || s == 16) {
    cnt = min(cnt, c);
    return;
  }

  forn(i,4) {
    forn(j,4) {
//      cout << i << ' ' << j << ln;
      s += apply(i,j);
      f(c + 1);
      s += apply(i,j);
    }
  }

}

int main() {
//  fast_cin();

  forn(i,4) {
    forn(j,4) {
      char c;
      cin >> c;
      p[i][j] = (c == 'W' ? 1 : 0);
      if (p[i][j]) s++;
    }
  } forn(i,3) {
    forn(j,3) {
      char c;
      cin >> c;
      mask[i][j] = (c == '1' ? 1 : 0);
    }
  } f(0);
  if (cnt == INF) cout << "Impossible" << ln;
  else cout << cnt << ln;

}