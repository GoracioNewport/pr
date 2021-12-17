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

enum { BEGIN, END, CHECK };

struct event {
    ll x, y, type;

    bool operator< (event& o) {
      if (x != o.x) return x < o.x;
      else if (type != o.type) return type < o.type;
      else return y < o.y;
    }
};

int main() {
  fast_cin();

  ll m;
  cin >> m;

  vector <event> e;

  while(true) {
    ll x, y;
    cin >> x >> y;

    if (x == 0 && y == 0) break;
    if (x > y) swap(x, y);
    if (y <= 0) continue;

    e.pb({x, y, BEGIN});
    e.pb({y, x, END});
    if (max(0ll, x) != 0) e.pb({max(0ll, x), max(0ll, x), CHECK});
    if (y != 0) e.pb({y, y, CHECK});

  } e.pb({0, 0, CHECK});
  sort(all(e));

//  for (auto& i : e) {
//    cout << i.x << ' ' << i.y << ' ' <<  i.type << ln;
//  }

  ll query = 0;

  vp64 ans;
  multiset <p64> q;

  for (auto& i : e) {
    if (i.x >= m) break;
    if (i.type == BEGIN) q.insert({-i.y, -i.x});
    else if (i.type == END) q.erase(q.find({-i.x, -i.y}));
    else if (i.type == CHECK && i.x == query) {
      if (!sz(q)) {
        cout << "No solution" << ln;
        return 0;
      } auto x = *q.begin();
      ans.pb({-x.se, -x.fi});
      query = -x.fi;
    }
  } cout << sz(ans) << ln;
  for (auto& i : ans) cout << i.fi << ' ' << i.se << ln;

}
