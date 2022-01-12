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
    v64 x(n);
    v64 y(n);
    forn(i,n) cin >> x[i] >> y[i];
    sort(all(x));
    sort(all(y));
    v64 xPref(n, 0);
    v64 xSuff(n, 0);
    v64 yPref(n, 0);
    v64 ySuff(n, 0);
    ll line = 0;
    forsn(i,1,n) {
      xPref[i] = (x[i] - x[i - 1]) + line + xPref[i - 1];
      line += (x[i] - x[i - 1]);
    } line = 0;
    forsn(i,1,n) {
      ll ri = n - i;
      xSuff[i] = (x[ri] - x[ri - 1]) + line + xSuff[i - 1];
      line += (x[ri] - x[ri - 1]);
    } forsn(i,1,n) {
      yPref[i] = (y[i] - y[i - 1]) + line + yPref[i - 1];
      line += (y[i] - y[i - 1]);
    } line = 0;
    forsn(i,1,n) {
      ll ri = n - i;
      ySuff[i] = (y[ri] - y[ri - 1]) + line + ySuff[i - 1];
      line += (y[ri] - y[ri - 1]);
    }

//    for (auto &i : xSuff) cout << i << ' ';
//    cout << ln;

    ll mi = INF;
    for (ll i = 0; i < n; i++) {
      for (ll j = i; j < n; j++) {
        ll XDist = (xPref[i] + xSuff[n - i - 1]);
        ll YDist = (yPref[j] + ySuff[n - j - 1]);
        mi = min(mi, XDist + YDist);
      }
    } set <p64> ans;
    for (ll i = 0; i < n; i++) {
      for (ll j = i; j < n; j++) {
        ll XDist = (xPref[i] + xSuff[n - i - 1]);
        ll YDist = (yPref[j] + ySuff[n - j - 1]);
        if (XDist + YDist == mi) ans.insert({x[i],y[j]});
      }
    } cout << sz(ans) << ln;
     for (auto &i : ans) cout << i.fi << ' ' << i.se << ln;
  }

}