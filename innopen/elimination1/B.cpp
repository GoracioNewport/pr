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

ll mod = 1e9 + 7;

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

  ll n;
  cin >> n;
  vv64 a(n - 1, v64 (n));
  for (auto& i : a) for (auto& j : i) cin >> j;

  v64 f(n + 1, 1);
//  f[1] = 1;
  for (ll i = 2; i <= n; i++) {
    f[i] = f[i - 1] * i % mod;
  }

  v64 ans(n);
  for (ll j = 0; j < n; j++) {
    v64 used(n, 0);
    ll m = 0;
    for (ll i = 0; i < n - 1; i++) {
      used[a[i][j] - 1]++;
      m = max(m, used[a[i][j] - 1]);
    } if (m <= 1) {
      for (ll k = 0; k < n; k++) {
        if (!used[k]) {
          ans[j] = k + 1;
          break;
        }
      }
    }
  } map <ll, ll> z;
  for (auto& i : ans) z[i]++;

  ll c = 1, cnt = z[0], Ans = 0;
  for (auto& i : z) {
    if (i.fi == 0) continue;
    Ans++;
    c = c * i.se % mod;
    cnt += i.se - 1;
  } cout << Ans << ' ' << c * f[cnt] % mod << ln;



}