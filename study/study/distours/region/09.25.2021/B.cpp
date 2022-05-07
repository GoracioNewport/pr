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

bool DEBUG = false;

int main() {
  fast_cin();

  freopen("prizes.in", "r", stdin);
  freopen("prizes.out", "w", stdout);

  ll n, k;
  cin >> n >> k;
  v64 a(n);
  for (auto &i : a) cin >> i;
  v64 p(n + 1, 0), rp(n + 1, 0);
  v64 b = a;
  reverse(all(b));
  forn(i,n) p[i + 1] = p[i] + a[i];
  forn(i,n) rp[i + 1] = rp[i] + b[i];

//  for (auto& i : p) cout << i << ' ';
//  cout << ln;
//  for (auto& i : rp) cout << i << ' ';
//  cout << ln;

  v64 maxP(n, 0), maxS(n, 0);
  maxP[k - 1] = p[k];
  maxS[k - 1] = p[n] - p[n - k];

  for (ll i = k; i < n; i++) {
    maxP[i] = max(maxP[i - 1], (p[i + 1] - p[i - k + 1]));
  }

  for (ll i = k; i < n; i++) {
    maxS[i] = max(maxS[i - 1], (rp[i + 1] - rp[i - k + 1]));
  }

//  reverse(all(maxS));

//  for (auto &i : maxP) cout << i << ' ';
//  cout << ln;
//  for (auto &i : maxS) cout << i << ' ';
//  cout << ln;

  ll ans = INF;

  // maxP[i] = Максимальный блок длины k на префиксе длины i + 1
  // maxS[i] = Максимальный блок длины k на суффиксе длины i + 1

  for (ll i = 0; i + k <= n; i++) { // Индекс начала блока, который выбрала Алиса

    if (DEBUG) cout << "Alise begin: " << i << ln;

    if (i < k) { // Петя может выбрать только суффикс
      if (DEBUG) cout << "Only suffix" << ln;
      ll lenS = n - (i + k);
      ans = min(ans, maxS[lenS - 1]);
    } else if (i < n - k) { // Петя может выбрать и префикс, и суффикс
      if (DEBUG) cout << "Prefix and suffix" << ln;
      ll lenS = n - (i + k);
      ll lenP = i;
      ans = min(ans, max(maxP[lenP - 1], maxS[lenS - 1]));
    } else { // Петя может выбрать только префикс
      if (DEBUG) cout << "Only prefix" << ln;
      ll lenP = i;
      ans = min(ans, maxP[lenP - 1]);
    } if (DEBUG) cout << ans << ln;
  } cout << ans << ln;


}