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

ll gcd(ll a, ll b) {
  if (b == 0) return a;
  else return gcd(b, a % b);
}

struct SparceTableGCD {
  vv64 t;
  v64 leadPower;
  ll maxLog, n;

  SparceTableGCD(v64& a) {
    n = sz(a);
    leadPower.resize(n + 1, 0);
    forsn(i,2,n + 1) leadPower[i] = leadPower[i / 2] + 1;
    maxLog = leadPower.back();

    t.resize(n, v64 (maxLog + 1));
    forn(i,n) t[i][0] = a[i];

    for (ll len = 1; len <= maxLog; len++) {
      for (ll i = 0; i < n - (1 << len) + 1; i++) {
        t[i][len] = gcd(t[i][len - 1], t[i + (1 << (len - 1))][len - 1]);
      }
    }
  }

  ll getGcd(ll l, ll r) {
    ll len = leadPower[r - l + 1];
    return gcd(t[l][len], t[r - (1 << len) + 1][len]);
  }
};

int main() {
  fast_cin();

  ll T;
  cin >> T;
  while(T--) {
    ll n;
    cin >> n;
    v64 a(n);
    for (auto& i : a) cin >> i;
    v64 b(n - 1);
    forn(i, n - 1) b[i] = abs(a[i] - a[i + 1]);
    SparceTableGCD t(b);

    ll ans = 1;
    for (ll i = 0; i < n - 1; i++) {
      ll l = i;
      ll r = n - 1;
      while(l + 1 < r) {
        ll m = (l + r) / 2;
        if (t.getGcd(i, m) > 1) l = m;
        else r = m;
      } if (t.getGcd(i, l) == 1) l--;
      ans = max(ans, l - i + 2);
    } cout << ans << ln;

  }

}