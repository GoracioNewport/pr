#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
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

int main() {
  fast_cin();

  ll n, q;
//  cin >> n >> q;
  scanf("%d %d", &n, &q);
  ll a[n];
  forn(i,n) {
//    cin >> a[i];
    scanf("%d", &a[i]);
  }
  ll len = 404;
//  cout << len << ln;

  pair <ll, pair <ll, ll>> d[n]; // { cnt, { ind, prev } };
  v64 used(n);
  forn(i,n) {
    if (used[i]) continue;
    ll curPos = i;
    v64 path = {curPos};
    ll r = min(n, (i / len) * len + len);
    while(curPos < r) {
      used[curPos] = 1;
      curPos += a[curPos];
      path.emplace_back(curPos);
    } ll ind = path.back();
    ll prev = path[sz(path) - 2];
    forn(j, sz(path)) {
      if (j == sz(path) - 1) continue;
      d[path[j]] = {sz(path) - j - 1, {ind, prev}};
    }
  } // for (auto &i : d) cout << i.fi << ' ' << i.se.fi << ' ' << i.se.se << ln;

  ll ind = 1;
  while(q--) {
    ind++;
    ll t, x;
//    cin >> t >> x;
    scanf("%d %d", &t, &x);
    x--;
    if (t == 0) {
      ll b;
//      cin >> b;
      scanf("%d", &b);
      if (a[x] == b) continue;
      a[x] = b;
      ll l = (x / len) * len;
      ll r = min(n, x + 1);
      for (ll i = l; i < r; i++) {
        if (used[i] == ind) continue;
        ll curPos = i;
        v64 path = {curPos};
//        ll r = min(n, (i / len) * len + len);
        while(curPos < r) {
          used[curPos] = ind;
          curPos += a[curPos];
          path.emplace_back(curPos);
        } ll ind = path.back();
        ll prev = path[sz(path) - 2];
        forn(j, sz(path)) {
          if (j == sz(path) - 1) continue;
          d[path[j]] = {sz(path) - j - 1, {ind, prev}};
        }
      }
    } else {
      ll ans = 0;
      ll curPos = x;
      ll prev;
      while(curPos < n) {
        ans += d[curPos].fi;
        prev = d[curPos].se.se;
        curPos = d[curPos].se.fi;
      } //cout << prev + 1 << ' ' << ans << ln;
      printf("%d %d\n", prev + 1, ans);
    }
  }


}