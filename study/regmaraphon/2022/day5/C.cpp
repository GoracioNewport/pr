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

int main() {
  fast_cin();

  ll n, k;
  string s;
  cin >> n >> k >> s;
  k = min(k, (ll)1e6);


  pair <ll, string> ans = {INF, s};

  for (ll len = 0; len < 26; len++) {

    vp64 a(26);
    forn(i,26) a[i].se = i;
    forn(i,n) a[s[i] - 'a'].fi++;
    sort(all(a));

    if (a[len].fi == 0) continue;
    if (k < 0) break;


    set <p64> q;
    forn(i,26) if (a[i].fi != 0) q.insert({a[i].fi, a[i].se});

    vector <stack <ll>> ind(26);
    forn(i,n) ind[s[i] - 'a'].push(i);

    forn(z,k) {
      auto x = q.begin();
      auto y = prev(q.end());
      if ((*x).fi == (*y).fi) break;

      auto X = *x;
      auto Y = *y;

      q.erase(x);
      q.erase(y);

      ll a = ind[Y.se].top();
      ind[Y.se].pop();
      ind[X.se].push(a);

      q.insert({X.fi + 1, X.se});
      q.insert({Y.fi - 1, Y.se});
    } string locAns(n, 'a');

    ll mi = INF, ma = -INF;
    char cur = 'a';
    for (auto& i : ind) {
      mi = min(mi, sz(i));
      ma = max(ma, sz(i));
      while(!i.empty()) {
        locAns[i.top()] = cur;
        i.pop();
      } cur++;
    } ans = min(ans, {ma - mi - 1, locAns});

    ll move = a[len].fi;
    q.clear();
    ind.clear();
    ind.resize(26);

    forn(i,26) if (a[i].fi != 0) q.insert({a[i].fi, a[i].se});
    forn(i,n) ind[s[i] - 'a'].push(i);

    forn(z,move) {
      auto x = q.begin();
      auto y = next(q.begin());
      if (next(q.begin()) == q.end()) break;

      auto X = *x;
      auto Y = *y;

      q.erase(x);
      q.erase(y);

      ll a = ind[X.se].top();
      ind[X.se].pop();
      ind[Y.se].push(a);

      q.insert({X.fi - 1, X.se});
      q.insert({Y.fi + 1, Y.se});
    } cur = 'a';
    for (auto& i : ind) {
      while(!i.empty()) {
        s[i.top()] = cur;
        i.pop();
      } cur++;
    }
    if (k >= 0 && len == 25) {
      ans = {0, s};
    } k -= move;
  } cout << ans.se << ln;

  // aaa

}