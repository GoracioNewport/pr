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

v64 f = {1, 2, 3, 5, 8, 13, 21, 34, 55, 89};

void F(v64& path, ll s, ll m) {
  if (s == 0) {
    for(ll i = 0; i < sz(path); i++) {
      if (i != 0) cout << '+';
      cout << path[i];
    }
    cout << ln;
    return;
  }

  for(auto& x : f) {
    if (x < m || x > s) continue;
    path.pb(x);
    F(path, s - x, x);
    path.pop_back();
  }

}

int main() {
  fast_cin();

  ll n, k;
  cin >> n >> k;
//  reverse(all(f));
//  v64 path;
//  F(path, n, 1);

  vv64 ANS;
  for (ll i = 0; i < (1 << sz(f)); i++) {
    vector <bool> used(sz(f));
    ll s = 0;
    for (ll j = 0; j < sz(f); j++) {
      if ((1 << j) & i) {
        used[j] = true;
        s += f[j];
      }
    }
    if (s == n) {
//      string ans = "";
      v64 z;
      forn(i,sz(f)) if (used[i]) z.pb(f[i]);
      ANS.pb(z);
    }
  } sort(all(ANS));

  for (auto& i : ANS) {
    forn(j, sz(i)) {
      if (j != 0) cout << '+';
      cout << i[j];
    } cout << ln;
  }

}