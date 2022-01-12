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

struct Tree {
  vp64 t;
  v64 a;
  ll n;
  Tree (v64& _a) {
    a = _a;
    n = sz(a);
    t.assign(4 * n, {INF, -INF});
    build(0, 0, n);
  }

  void build(ll v, ll l, ll r) {
    if (l + 1 == r) {
      t[v].fi = t[v].se = a[l];
      return;
    } ll m = (l + r) / 2;
    build(2 * v + 1, l, m);
    build(2 * v + 2, m, r);
    t[v].fi = min(t[2 * v + 1].fi, t[2 * v + 2].fi);
    t[v].se = max(t[2 * v + 1].se, t[2 * v + 2].se);
  }

  ll getMin(ll v, ll l, ll r, ll L, ll R) {
    if (l >= L && r <= R) return t[v].fi;
    if (l >= R || r <= L) return INF;
    ll m = (l + r) / 2;
    return min(getMin(2 * v + 1, l, m, L, R), getMin(2 * v + 2, m, r, L, R));
  }

  ll getMax(ll v, ll l, ll r, ll L, ll R) {
    if (l >= L && r <= R) return t[v].se;
    if (l >= R || r <= L) return -INF;
    ll m = (l + r) / 2;
    return max(getMax(2 * v + 1, l, m, L, R), getMax(2 * v + 2, m, r, L, R));
  }
};

void countSort(v64& c, v64& p) {
  ll n = sz(p);
  v64 cnt(n), pos(n), newP(n);
  for (auto& i : c) cnt[i]++;
  forsn(i,1,n) pos[i] = pos[i - 1] + cnt[i - 1];
  for (auto& i : p) newP[pos[c[i]]++] = i;
  p = newP;
}

int main() {
  fast_cin();

  string s;
  cin >> s;
  s += '$';
  ll n = sz(s);
  v64 p(n), c(n); {
    vector <pair <char, ll>> a(n);
    forn(i,n) a[i] = {s[i], i};
    sort(all(a));
    forn(i,n) p[i] = a[i].se;
    forsn(i,1,n) {
      if (a[i].fi == a[i - 1].fi) c[p[i]] = c[p[i - 1]];
      else c[p[i]] = c[p[i - 1]] + 1;
    }
  } ll k = 0;
  while((1 << k) < n) {
    for(auto& i : p) i = (i - (1 << k) + n) % n;
    countSort(c, p);
    v64 newC(n);
    forsn(i,1,n) {
      if ((c[p[i]] == c[p[i - 1]]) && (c[(p[i] + (1 << k)) % n] == c[(p[i - 1] + (1 << k)) % n])) newC[p[i]] = newC[p[i - 1]];
      else newC[p[i]] = newC[p[i - 1]] + 1;
    } c = newC;
    k++;
  } k = 0;
  v64 lcp(n - 1);

  // p - sortedInd to ind
  // c - ind to sortedInd

  forn(i,n - 1) {
    ll j = p[c[i] - 1];
    while(s[i + k] == s[j + k]) k++;
    lcp[c[i] - 1] = k;
    k = max(0ll, k - 1);
  }

  vp64 closest(n, {-1, n - 1});
  stack <p64> q;
  q.push({-INF, -1});

  forn(i,n - 1) {
    while(q.top().fi > lcp[i]) {
      closest[q.top().se].se = i;
      q.pop();
    } q.push({lcp[i], i});
  } while (!q.empty()) q.pop();

  q.push({-INF, n - 1});

  rforn(i,n - 1) {
    while(q.top().fi > lcp[i]) {
      closest[q.top().se].fi = i;
      q.pop();
    } q.push({lcp[i], i});
  } Tree t(p);

//  for (auto& i : lcp) cout << i << ' ';
//  cout << ln;
//
//  for (auto& i : closest) cout << i.fi << ' ';
//  cout << ln;
//
//  for (auto& i : closest) cout << i.se << ' ';
//  cout << ln;

  ll ans = 0;

  forn(z,n - 1) {
    ll i = closest[z].fi + 1;
    ll j = closest[z].se;
    ll left = t.getMin(0, 0, n, i, j + 1);
    ll right = t.getMax(0, 0, n, i, j + 1);
//    p64 left = {t.getMin(0, 0, n, i, z + 1), t.getMax(0, 0, n, i, z + 1)};
//    p64 right = {t.getMin(0, 0, n, z + 1, j + 1), t.getMax(0, 0, n, z + 1, j + 1)};
//    ll x = max(left.se - right.fi, right.se - left.fi);
    ll x = right - left;
//    cout << i << ' ' << z << ' ' << j << ' ' << x << ln;
    ans = max(ans, x + lcp[z] + lcp[z] * lcp[z]);
  } cout << ans << ln;


}