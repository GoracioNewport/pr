// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
// #pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

// Author: @GoracioNewport

using namespace std;

typedef int ll;
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

struct sparceTableMax {
  vv64 t;
  v64 a, leadPower;
  ll n, maxL;

  sparceTableMax(v64& _a) {
    a = _a;
    n = sz(a);
    leadPower.assign(n + 1, 0);
    forsn(i,2,n + 1) leadPower[i] = leadPower[i / 2] + 1;
    maxL = leadPower.back() + 1;

    t.assign(n, v64 (maxL + 1));
    forn(i,n) t[i][0] = a[i];

    for (ll len = 1; len <= maxL; len++) {
      for (ll i = 0; i < n - (1 << len) + 1; i++) {
        t[i][len] = max(t[i][len - 1], t[i + (1 << (len - 1))][len - 1]);
      }
    }
  }

  ll getMax(ll l, ll r) {
    l++; r++;
    ll len = leadPower[(r - l) + 1];
    return max(t[l - 1][len], t[r - (1 << len)][len]);
  }

};

struct sparceTableOr {
  vv64 t;
  v64 a, leadPower;
  ll n, maxL;

  sparceTableOr(v64& _a) {
    a = _a;
    n = sz(a);
    leadPower.assign(n + 1, 0);
    forsn(i,2,n + 1) leadPower[i] = leadPower[i / 2] + 1;
    maxL = leadPower.back() + 1;

    t.assign(n, v64 (maxL + 1));
    forn(i,n) t[i][0] = a[i];

    for (ll len = 1; len <= maxL; len++) {
      for (ll i = 0; i < n - (1 << len) + 1; i++) {
        t[i][len] = t[i][len - 1] | t[i + (1 << (len - 1))][len - 1];
      }
    }
  }

  ll getOr(ll l, ll r) {
    l++; r++;
    ll len = leadPower[(r - l) + 1];
    return t[l - 1][len] | t[r - (1 << len)][len];
  }

};

int main() {
  fast_cin();

  ll n;
  cin >> n;
  v64 a(n);
  for (auto& i : a) cin >> i;
  sparceTableMax tX(a);
  sparceTableOr tO(a);

  ll ans = 0;
  for (ll i = 0; i < n; i++) {
    for (ll j = i + 1; j < n; j++) {
      ll xo = tO.getOr(i, j);
      ll ma = tX.getMax(i, j);
//      cout << i << ' ' << j << ' ' << xo << ' ' << ma << ln;
      if (xo > ma) ans++;
    }
  } cout << ans << ln;

}