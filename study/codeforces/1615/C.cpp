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

  ll t;
  cin >> t;
  while(t--) {
    ll n;
    cin >> n;
    string a, b;
    cin >> a >> b;

    ll cnt1 = 0;
    for(auto& i : a) if (i == '1') cnt1++;
    ll cnt2 = (n - cnt1) + 1;

    ll ans = INF;

    ll cnt3 = 0;
    for (auto& i : b) if (i == '1') cnt3++;

    if (cnt1 == cnt3) {
      ll locAns = 0;
      forn(i,n) if (a[i] == '1' && b[i] == '0') locAns++;
      ans = min(ans, locAns * 2);
    } if (cnt2 == cnt3) {
      ll ind = -1;
      forn(i,n) if (a[i] == '1' && b[i] == '1') ind = i;
      if (ind == -1) forn(i,n) if (a[i] == '1') ind = i;
      if (ind != -1) {
        forn(i,n) {
          if (i != ind) {
            if (a[i] == '1') a[i] = '0';
            else a[i] = '1';
          }
        } ll locAns = 0;
        forn(i,n) if (a[i] == '1' && b[i] == '0') locAns++;
        ans = min(ans, locAns * 2 + 1);
      }
    } cout << (ans == INF ? -1 : ans) << ln;

  }

}