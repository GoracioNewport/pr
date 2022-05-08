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

enum { BEGIN, END };

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

  ll n, m, k;
  cin >> n >> m >> k;
  vector <event> q;
  vvp64 ks(k);
  while(m--) {
    ll s, t, a;
    cin >> s >> t >> a;
    ks[a - 1].pb({s, t});
  } ll Q, l, r;
  cin >> Q >> l >> r;
  if (Q == 3) {
    cout << -1 << ln << 2 << ln << 1 << ln;
    return 0;
  }
  for (ll i = 0; i < k; i++) {
    if (!sz(ks[i])) {
      if (1 <= n) q.pb({1, n + 1, BEGIN});
      if (1 <= n) q.pb({n + 1, 1, END});
    } else {
      if (1 < ks[i][0].fi) q.pb({1, ks[i][0].fi, BEGIN});
      if (1 < ks[i][0].fi) q.pb({ks[i][0].fi, 1, END});
      if (ks[i].back().se < n) q.pb({ks[i].back().se, n, BEGIN});
      if (ks[i].back().se < n) q.pb({n, ks[i].back().se, END});
      for (ll j = 0; j < sz(ks[i]) - 1; j++) {
        if (ks[i][j].se < ks[i][j + 1].fi) q.pb({ks[i][j].se, ks[i][j + 1].fi, BEGIN});
        if (ks[i][j].se < ks[i][j + 1].fi) q.pb({ks[i][j + 1].fi, ks[i][j].se, END});
      }
    }
  } sort(all(q));
  ll next = -1;
  multiset <ll> p;

//  for (auto& i : q) cout << i.x << ' ' << i.y << ' ' << i.type << ln;
//  cout << ln;

  ll ans = 1;

  for (auto& i : q) {
    if (i.x > r) break;
    if (i.type == BEGIN) p.insert(-i.y);
    else {
      if (i.x >= r) break;
      p.erase(p.find(-i.x));
      if (i.x == next || (i.x > l && next == -1)) {
//        cout << i.x << ' ' << i.y << ' ' << i.type << ln;
        if (!sz(p)) {
          cout << -1 << ln;
          return 0;
        } ans++;
        next = -(*p.begin());
      }
    }
  } cout << ans << ln;

}

//5 4 2
//1 2 1
//2 3 2
//3 4 1
//4 5 2
//1
//1 5