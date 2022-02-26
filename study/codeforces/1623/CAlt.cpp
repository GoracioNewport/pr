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

bool ok(v64 a, ll d) {

  ll n = sz(a);


  v64 b(n);

  for (ll i = n - 1; i >= 2; i--) {
    ll x = max(0ll, (a[i] + b[i] - d) / 3);
    b[i - 2] += 2 * x;
    b[i - 1] += x;
  }

  for(ll i = 2; i < n; i++) {
    ll can = max(0ll, min(a[i] / 3, (a[i] - (d - b[i])) / 3));
    a[i - 2] += 2 * can;
    a[i - 1] += can;
    a[i] -= 3 * can;
    if (a[i] < 0) return false;
  } return (*min_element(all(a)) >= d);
}

int main() {
  fast_cin();

  ll t;
  cin >> t;
  while(t--) {
    ll n;
    cin >> n;
    v64 a(n);
    for (auto& i : a) cin >> i;


    ll l = 0;
    ll r = 2e9;
    while(l + 1 < r) {
      ll m = (l + r) / 2;
      if (ok(a,  m)) l = m;
      else r = m;
    } cout << l << ln;
  }

}