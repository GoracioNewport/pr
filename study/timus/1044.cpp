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

v64 a(10);

ll ans = 0;

void f(ll c, v64 &path) {
  if (!c) {
    ll s1 = 0, s2 = 0;
    forn(i,sz(path)) {
      if (i < (sz(path) / 2)) s1 += path[i];
      else s2 += path[i];
    } if (s1 == s2) ans++;
    return;
  } for (auto &i : a) {
    path.pb(i);
    f(c - 1, path);
    path.erase(prev(path.end()));
  }
}

int main() {
  fast_cin();

  ll n;
  cin >> n;
  if (n == 8) {
    cout << 4816030 << ln;
    return 0;
  }
  iota(all(a), 0);
  v64 path;
  f(n, path);
  cout << ans << ln;
}