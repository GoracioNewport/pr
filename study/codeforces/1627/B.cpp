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
    ll n, m;
    cin >> n >> m;

    vv64 p(n, v64(m, INF));

    vp64 safe;

    ll x = (n / 2) + (m / 2);

    if ((n % 2) && (m % 2)) safe.pb({n / 2, m / 2});
    else if ((n % 2 == 0) && (m % 2)) {
      safe.pb({n / 2, m / 2});
      safe.pb({n / 2 - 1, m / 2});
    } else if ((n % 2) && (m % 2 == 0)) {
      safe.pb({n / 2, m / 2});
      safe.pb({n / 2, m / 2 - 1});
    } else {
      safe.pb({n / 2, m / 2});
      safe.pb({n / 2, m / 2 - 1});
      safe.pb({n / 2 - 1, m / 2});
      safe.pb({n / 2 - 1, m / 2 - 1});
    }

    forn(i,n) forn(j,m) for (auto& c : safe) p[i][j] = min(p[i][j], abs(i - c.fi) + abs(j - c.se));


    v64 cnt(n + m);
    for (auto& i : p) {
      for (auto& j : i) cnt[j]++;
    }



    forn(i,sz(cnt)) {
      forn(j,cnt[i]) cout << i + x << ' ';
    } cout << ln;



//    for (auto& i : p) {
//      for (auto& j : i) cout << j << ' ';
//      cout << ln;
//    }





//    if (n > m) swap(n, m);
//
//    ll x = (n / 2) + (m / 2);
//
//    ll nMax = ceil((ld)n / 2.0);
//    ll mMax = ceil((ld)m / 2.0);
//
//
//    ll i;
//    if ((n % 2) && (m % 2)) i = 1;
//    else if ((n % 2) || (m % 2)) i = 2;
//    else i = 4;
//
//    ll nH = 1, mH = 1;
//    if (n % 2 == 0) nH++;
//    if (m % 2 == 0) mH++;
//
//    while(nH <= n && mH <= m) {
//      forn(k,i) cout << x << ' ';
//      nH += 2;
//      mH += 2;
//      i = max(nH, mH) * 2 - 2;
//      x++;
//    }
//
//    ll off;
//    if (m % 2) off = 4;
//    else off = 2;
//
//    while(nH <= n || mH <= m) {
//      forn(k,i - off) cout << x << ' ';
//      nH += 2;
//      mH += 2;
//      i = max(nH, mH) * 2 - 2;
//      x++;
//      off += 4;
//    }
//
//
//    cout << ln;


  }

}