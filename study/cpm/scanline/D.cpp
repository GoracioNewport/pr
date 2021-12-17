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

  vp64 a;

  forn(i,n) {
    ll a1, b1, c1, a2, b2, c2;
    cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
    b1 += (a1 * 60);
    c1 += (b1 * 60);
    b2 += (a2 * 60);
    c2 += (b2 * 60);

    if (c1 == c2) {
      a.pb({0, 0});
      a.pb({24 * 60 * 60, 1});
    } if (c1 > c2) {
      a.pb({0, 0});
      a.pb({c2, 1});
      a.pb({c1, 0});
      a.pb({24 * 60 * 60, 1});
    }

    a.pb({c1, 0});
    a.pb({c2, 1});
  }

  ll ans = 0, prev, bal = 0;

  sort(all(a));

  for (auto& i : a) {
    if (i.se == 0) {
      bal++;
      if (bal == n) prev = i.fi;
    } else {
      bal--;
      if (bal == n - 1) ans += i.fi - prev;
    }
  } cout << ans << ln;

}