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

ll mod = 998244353;

ll binPow(ll a, ll n) {
  if (n == 0) return 1;
  else if (n % 2) return binPow(a, n - 1) * a % mod;
  else {
    ll b = binPow(a, n / 2);
    return b * b % mod;
  }
}

int main() {
  fast_cin();

  v64 facts(5001, 1);
  forsn(i,1,5001) facts[i] = facts[i - 1] * i % mod;


  ll n, k;
  cin >> n >> k;
  string s;
  cin >> s;

  if (k == 0) {
    cout << 1 << ln;
    return 0;
  }

  vp64 closestOne(n, {-1, n});
  ll ind = -1;
  forn(i,n) {
    closestOne[i].fi = ind;
    if (s[i] == '1') ind = i;
  } ind = n;
  for (ll i = n - 1; i >= 0; i--) {
    closestOne[i].se = ind;
    if (s[i] == '1') ind = i;
  }

  v64 inds;
  forn(i,n) if (s[i] == '1') inds.pb(i);

  ll ans = 1;

  for(ll i = k - 1; i < sz(inds); i++) {
    ll l = closestOne[inds[i - k + 1]].fi + 1;
    ll r = closestOne[inds[i]].se - 1;

    ll r2 = inds[i] - 1;


    ll n = (r - l) + 1;
    ll n2 = (r2 - l) + 1;

    ll f = ((facts[n] * binPow(facts[k], mod - 2) % mod * binPow(facts[n - k], mod - 2) % mod) - 1 + mod) % mod;
    ll s = ((facts[n2] * binPow(facts[k - 1], mod - 2) % mod * binPow(facts[n2 - (k - 1)], mod - 2) % mod) - 1 + mod) % mod;
    if (i == k - 1) s = 0;
    ans = (ans + (f - s + mod)) % mod;
    cerr << n << ' ' << n2 << ' ' << l << ' ' << r << ' ' << r2 << ln;
  }

  cout << ans << ln;
//  for (auto& i : closestOne) cout << i.fi << ' ' << i.se << ln;


}