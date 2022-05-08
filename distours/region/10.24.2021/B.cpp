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
  cin >> n >> k;
  v64 a(n);
  map <ll, ll> cnt;
  for (auto& i : a) {
    cin >> i;
    cnt[i]++;
  } sort(all(a));
  a.erase(unique(all(a)), a.end());
  ll ans = 0;
  v64 dbs;
  for (auto& i : cnt) {
    if (i.se > 1) dbs.pb(i.fi);
  }

  for (ll i = 0; i < sz(a); i++) { // ok
    ll x = (upper_bound(all(a), a[i] * k) - a.begin()) - i;
    ans += max((ll)0, 3 * (x - 2) * (x - 1));
  }

  for (ll i = 0; i < sz(a); i++) {
    if (cnt[a[i]] > 1) {
      ll x = (upper_bound(all(a), a[i] * k) - a.begin()) - i - 1;
      ans += max((ll) 0, x * 3);
    } ll y = ((upper_bound(all(dbs), a[i] * k) - dbs.begin()) - (upper_bound(all(dbs), a[i]) - dbs.begin()));
    ans += max((ll) 0, y * 3);
  }

  for (auto& i : cnt) if (i.se > 2) ans++; // ok
  cout << ans << ln;

}