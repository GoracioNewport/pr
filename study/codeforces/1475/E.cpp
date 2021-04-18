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
ll mod = 1e9 + 7;
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

v64 f;

ll binPow(ll a, ll n) {
  if (n == 0) return 1;
  else if (n % 2 == 1) return (binPow(a, n -1) * a) % mod;
  else {
    ll b = binPow(a, n / 2) % mod;
    return (b * b) % mod;
  }
} 

ll inv(ll x) {
  return binPow(x, mod - 2);
}

int main() {
  fast_cin();
  
  ll t;
  cin >> t;
  f.resize(1001, 1);
  forsn(i, 1, 1001) f[i] = (f[i - 1] * i) % mod;
  // for (int i = 0; i <= 10; i++) cout << f[i] << endl;
  // cout << binPow(2, 30) << endl;
  while(t--) {
    ll n, k;
    cin >> n >> k;
    k--;
    v64 a(n);
    for (auto &i : a) cin >> i;
    sort(all(a));
    reverse(all(a));
    ll t = a[k];
    ll b = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] <= t) {
        b = i;
        break;
      }
    } ll num = 0;
    for (auto &i : a) if (i == t) num++;
    ll N = num;
    ll K = (k - b + 1);
    // cout << k << ' ' << b << endl;
    // cout << N << ' ' << K << endl;
    cout << ((f[N] * inv(f[K]) % mod) * inv(f[N - K])) % mod << endl;
  }

}
