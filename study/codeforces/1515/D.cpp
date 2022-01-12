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

  bool debug = false;

  ll t;
  cin >> t;
  while(t--) {
    ll n, l, r;
    cin >> n >> l >> r;
    v64 a(n);
    for (auto &i : a) {
      cin >> i;
    } v64 lp(n), rp(n);
    forn(i,l) lp[a[i] - 1]++;
    forsn(i,l,n) rp[a[i] - 1]++;
    if (l > r) {
      swap(lp, rp);
      swap(l, r);
    } // l < r
    forn(i,n) { // Удалили все отсортированные носки
      ll x = min(lp[i], rp[i]);
      lp[i] -= x;
      rp[i] -= x;
    } ll turns = (r - l) / 2;
    ll ans = turns;

    if (debug) {

      for (auto &i : lp) cout << i << ' ';
      cout << ln;
      for (auto &i : rp) cout << i << ' ';
      cout << ln;
    }

    forn(i,n) { // Надо удалить все rp[i], которые больше 1...
      if (rp[i] > 1) {
        ll x = rp[i] / 2;
        if (turns < x) {
          rp[i] -= turns;
          lp[i] += turns;
          turns = 0;
          break;
        } else {
          rp[i] -= x;
          lp[i] += x;
          turns -= x;
        }
      }
    }
    forn(i,n) {
      ll x = min(lp[i], rp[i]);
      lp[i] -= x;
      rp[i] -= x;
    }

    if (turns > 0) {
      forn(i,n) {
        if (!turns) break;
        if (rp[i] > 0) {
          if (rp[i] > turns) {
            lp[i] += turns;
            rp[i] -= turns;
            turns = 0;
          } else {
            lp[i] += rp[i];
            turns -= rp[i];
            rp[i] = 0;
          }
        }
      }
    }

    if (debug) {

      for (auto &i : lp) cout << i << ' ';
      cout << ln;
      for (auto &i : rp) cout << i << ' ';
      cout << ln;

      cout << ans << ln;
    }
    forn(i,n) {
      ll x = min(lp[i], rp[i]);
      lp[i] -= x;
      rp[i] -= x;
    } for (auto &i : rp) ans += i;
    cout << ans << ln;
  }


}