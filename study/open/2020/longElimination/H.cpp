#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

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
  
  ll n;
  cin >> n;
  vector <ll> a(n + 2, -INF);
  for (int i = 1; i <= n; i++) cin >> a[i];
  vector <ll> l(n + 2);
  vector <ll> r(n + 2);

  stack <ll> mi;
  mi.push(0);

  for (int i = 1; i <= n + 1; i++) {
    while (a[mi.top()] > a[i]) {
      r[mi.top()] = i;
      mi.pop();
    } mi.push(i);
  } mi = stack <ll> ();
  mi.push(0);
  vector <ll> ac = a;
  reverse(ac.begin(), ac.end());

  for (int i = 1; i <= n + 1; i++) {
    while (ac[mi.top()] > ac[i]) {
      l[mi.top()] = n - i + 1;
      mi.pop();
    } mi.push(i);
  } reverse(l.begin(), l.end());
  // for (auto &i : l) cout << i << ' ';
  // cout << endl;
  // for (auto &i : r) cout << i << ' ';
  // cout << endl;

  ll gH = -1;
  ll gV = -1;

  for (int i = 1; i <= n; i++) {
    if (a[i] == 0) continue;
    ll h = a[i];
    ll v = (r[i] - l[i] - 1);
    if (h > v) swap(h, v);
    if (gH == -1) gH = h;
    if (gV == -1) gV = v;
    // cout << a[i] << ' ' << r[i] << ' ' << l[i] << endl;
    gH = min(gH, h);
    gV = min(gV, v);
  } cout << gH * gV << endl;
  // cout << gH << ' ' << gV << endl;
}
