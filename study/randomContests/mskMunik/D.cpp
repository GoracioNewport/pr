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

  ll n;
  cin >> n;
  v64 a(n);
  for (auto& i : a) cin >> i;


  v64 mins(n);
  mins[0] = a[0];

  forsn(i,1,n) mins[i] = min(mins[i - 1], a[i]);

  v64 maxs(n);
  reverse(all(a));
  maxs[0] = a[0];

  forsn(i,1,n) maxs[i] = max(maxs[i - 1], a[i]);

  reverse(all(a));
  reverse(all(maxs));

//  for (auto& i : mins) cout << i << ' ';
//  cout << ln;
//
//  for (auto& i : maxs) cout << i << ' ';
//  cout << ln;

  for (ll j = 1; j < n - 1; j++) {
    ll l = mins[j - 1];
    ll r = maxs[j + 1];

    if (l < a[j] && a[j] < r) {
      for (ll i = 0; i < j; i++) {
        if (a[i] < a[j]) {
          cout << i + 1 << ' ';
          break;
        }
      } cout << j + 1 << ' ';
      for (ll k = j + 1; k < n; k++) {
        if (a[j] < a[k]) {
          cout << k + 1 << ' ';
          return 0;
        }
      }
    }

  } cout << 0 << ln;

}