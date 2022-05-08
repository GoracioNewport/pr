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

int main() {
  fast_cin();

  ll n;
  cin >> n;
  v64 a(n);
  for (auto& i : a) {
    cin >> i;
  } sort(all(a));

  v64 d = {0};

  partial_sum(all(a), back_inserter(d));

  ll ans = INF;

  // for (auto& i : a) cout << i << ' ';
  // cout << ln;

  // for (auto& i : d) cout << i << ' ';
  // cout << ln; 

  for (ll i = 2; i < n; i++) {
    
    ll l = 1;                         
    ll r = i;

    while(l + 1 < r) {
      ll m = (l + r) / 2;

      ll j = i - m;

      ll s = d[i + 1] - d[j];
      ll ma = a[i];

      if (ma < s - ma) r = m;
      else l = m;
    } 

    ll j = i - r;

    ll s = d[i + 1] - d[j];
    ll ma = a[i];

    // cout << j << ' ' << i << ' ' << s << ' ' << ma << ln;
  
    if (ma < s - ma) ans = min(ans, r + 1);
  } cout << (ans == INF ? -1 : ans) << ln;

}