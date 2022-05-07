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

void solve(ll n) {
  v64 a(n);
  for (auto& i : a) cin >> i;
  v64 l(64), r(64);
  for(ll i = 1; i < n; i++) r[a[i]]++;

  ll ans = 0;
  for (ll j = 1; j < n - 1; j++) {
    l[a[j - 1]]++;
    r[a[j]]--;

    for (ll i = 0; i < 64; i++) {
      for (ll k = 0; k < 64; k++) {
        ll x = i ^ a[j];
        ll y = k ^ a[j];

        if (x < y) ans += l[i] * r[k];
      }
    }
  } cout << ans << ln;
}

int main() {
  fast_cin();

  ll n;
  cin >> n;
  if (n > 3000) {
    solve(n);
    return 0;
  }

  v64 a(n);
  for (auto& i : a) cin >> i;
  ll ans = 0;
  for (ll j = 1; j < n - 1; j++) {
    v64 r;
    for (ll k = j + 1; k < n; k++) r.pb(a[j] ^ a[k]);
    sort(all(r));

//    cout << "J: " << j << ln;
//    for (auto& i : r) cout << i << ' ';
//    cout << ln;

    for (ll i = 0; i < j; i++) {
      ans += r.end() - upper_bound(all(r), a[j] ^ a[i]);
//      ans += (r.end() - it);
    }
  } cout << ans << ln;

}