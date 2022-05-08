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

bool DEBUG = false;

int main() {
  fast_cin();

  ll m, n;
  cin >> m >> n;

  vp64 a(n);
  for (auto &i : a) cin >> i.fi >> i.se; // ver, gor

  map <ll, set <ll>> ver, hor, gorlt, gorlb;

  for (auto &i : a) {
    ll x = i.fi;
    ll y = i.se;
    ver[y].insert(x);
    hor[x].insert(y);
    gorlt[x - y].insert(x);
    gorlb[x + y].insert(y);
  } ll ans = 0;

  ll ind = 0;
  ll Prev = 0;

  for (auto &i : a) {

    if (DEBUG) cout << "-----------" << ind++ << "---------------" << ln;

    ll x = i.fi;
    ll y = i.se;

    {
      if (DEBUG) cout << "VERTICAL: " << ln;
      auto it = ver[y].lower_bound(x);
      if (it != ver[y].begin()) {
        if (DEBUG) cout << "PREV found" << ln;
        ans++;
      }

      auto e = next(it);
      if (e != ver[y].end()) {
        if (DEBUG) cout << "NEXT Found" << ln;
        ans++;
      }
    }

    {
      if (DEBUG) cout << "HORIZONTAL: " << ln;
      auto it = hor[x].lower_bound(y);
      if (it != hor[x].begin()) {
        if (DEBUG) cout << "PREV found" << ln;
        ans++;
      }

      auto e = next(it);
      if (e != hor[x].end()) {
        if (DEBUG) cout << "NEXT Found" << ln;
        ans++;
      }
    }

    {
      if (DEBUG) cout << "DIAGONAL 1: " << ln;
      auto it = gorlt[x - y].lower_bound(x);
      if (it != gorlt[x - y].begin()) {
        if (DEBUG) cout << "PREV found" << ln;
        ans++;
      }

      auto e = next(it);
      if (e != gorlt[x - y].end()) {
        if (DEBUG) cout << "NEXT Found" << ln;
        ans++;
      }
    }

    {
      if (DEBUG) cout << "DIAGONAL 2: " << ln;
      auto it = gorlb[x + y].lower_bound(y);
      if (it != gorlb[x + y].begin()) {
        if (DEBUG) cout << "PREV found" << ln;
        ans++;
      }

      auto e = next(it);
      if (e != gorlb[x + y].end()) {
        if (DEBUG) cout << "NEXT Found" << ln;
        ans++;
      }
    }

    if (DEBUG) cout << "Result: " << ans - Prev << ln;
    Prev = ans;

  }


  cout << ans / 2 << ln;

}