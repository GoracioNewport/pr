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

ll n;
v64 d, X;

ll ans = 0, mod = 998244353;

ll binPow(ll a, ll n) {
  if (n == 0) return 1;
  else if (n % 2) return binPow(a, n - 1) * a % mod;
  else {
    ll b = binPow(a, n / 2);
    return b * b % mod;
  }
}

void f(ll h, v64& status) {
  if (h == n) {
    ll x = INF;
    forn(i,n) {
      if (status[i] == -1) x = min(x, X[i] - 1);
      if (status[i] == 1) x = min(x, d[i] - X[i]);
    } if (x != INF) ans = (ans + x) % mod;
    return;
  } for (ll i = -1; i <= 1; i++) {
    status[h] = i;
    f(h + 1, status);
    status[h] = 0;
  }
}

int main() {
  fast_cin();

  cin >> n;
  d.resize(n);
  X.resize(n);

  v64 status(n, 1);

  v64 up(n), down(n);

  ll mul = 1;

  for (auto& i : d) cin >> i;
  for (auto& i : X) cin >> i;
  forn(i,n) {
    up[i] = X[i] - 1;
    down[i] = d[i] - X[i];
  } vp64 q;
  forn(i,n) {
    q.pb({-up[i], i});
    q.pb({-down[i], i});
  } sort(all(q));

  ll revTwo = binPow(2, mod - 2);
  ll revThree = binPow(3, mod - 2);

//  for (auto& i : up) cout << i << ' ';
//  cout << ln;
//  for (auto& i : down) cout << i << ' ';
//  cout << ln;

  for (auto& i : q) {
    ll locMul = mul;
    if (status[i.se] == 2) locMul = mul * revTwo % mod;

    ans = (ans + locMul * -i.fi) % mod;
    if (status[i.se] == 1) mul = mul * 2 % mod;
    else if (status[i.se] == 2) {
      mul = mul * revTwo % mod;
      mul = mul * 3 % mod;
    } status[i.se]++;
  } cout << ans << ln;




//
//  f(0, status);
//  cout << ans << ln;


}