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

void solve(ll l, ll r, ll n, vp64& a, v64& used, v64& ans) {
  ll ind = -1;
  forn(i,n) if (a[i].fi == l && a[i].se == r) ind = i;
  used[ind] = true;

  if (l == r) {
    ans[ind] = l;
    return;
  }

  ll findInd = -1;
  forn(i,n) if (!used[i] && a[i].fi == l + 1 && a[i].se == r) findInd = i;

  if (findInd != -1) {
    ans[ind] = l;
    solve(l + 1, r, n, a, used, ans);
    return;
  }

  forn(i,n) if (!used[i] && a[i].fi == l && a[i].se == r - 1) findInd = i;

  if (findInd != -1) {
    ans[ind] = r;
    solve(l, r - 1, n, a, used, ans);
    return;
  }

  vp64 inds;
  forn(i,n) if (!used[i] && a[i].fi == l) inds.pb({a[i].se, i});
  unordered_map <ll, ll> found;

  for (auto& i : inds) found[i.fi] = 1;

  forn(i,n) {
    if (!used[i] && a[i].se == r) {
      if (found[a[i].fi - 2]) {
        ans[ind] = a[i].fi - 1;
        solve(l, a[i].fi - 2, n, a, used, ans);
        solve(a[i].fi, r, n, a, used, ans);
        return;
      }
    }
  }


}

int main() {
  fast_cin();

  ll t;
  cin >> t;
  while(t--) {
    ll n;
    cin >> n;
    vp64 a(n);
    for (auto& i : a) cin >> i.fi >> i.se;
//    forn(i,n) if (a[i].fi == 1 && a[i].se == n) ind = i;
    v64 used(n), ans(n);
    solve(1, n, n, a, used, ans);
    forn(i,n) cout << a[i].fi << ' ' << a[i].se << ' ' << ans[i] << ln;
    cout << ln;
  }

}