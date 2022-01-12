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
  ll c, type, x, y, e;
  bool operator< (event& o) {
    if (c != o.c) return c < o.c;
    else return type < o.type;
  }
};

int main() {
  fast_cin();

  ll n;
  cin >> n;
  v64 a(n), f(n), b(n);
  v64 ans(n, -1);
  for (auto& i : a) cin >> i;
  for (auto& i : f) cin >> i;
  forn(i,n) if (a[i] >= f[i]) ans[i] = 0;

  ll q;
  cin >> q;
  vector <pair <p64, p64>> Q(q);
  for (auto& i : Q) {
    cin >> i.fi.fi >> i.fi.se >> i.se.fi >> i.se.se;
    i.fi.fi--;
    i.fi.se--;
  }

  ll len = sqrt(q);
  for (ll start = 0; start < q; start += len) {
    vector <event> e;
    for (ll i = start; i < min(q, start + len); i++) {
      e.pb({Q[i].fi.fi, BEGIN, Q[i].se.fi, Q[i].se.se, Q[i].fi.se + 1});
      e.pb({Q[i].fi.se + 1, END, Q[i].se.fi, Q[i].se.se, Q[i].fi.fi});
    } sort(all(e));

    ll ind = 0;
    b = a;
    ll p = 0;
    ll step = 0;

    v64 inds;
    for (ll i = 0; i < n; i++) {
      while(ind < sz(e) && e[ind].c == i) {
        if (e[ind].type == BEGIN) {
          p += e[ind].x;
          step += e[ind].y;
        } else {
          p -= e[ind].x + (e[ind].y * (e[ind].c - e[ind].e));
          step -= e[ind].y;
        } ind++;
      } b[i] += p;
      if (ans[i] == -1 && b[i] >= f[i]) {
        inds.pb(i);
        ans[i] = 0;
      }
      p += step;
    }

//    cout << start << ln;
//
//    for (auto& i : a) cout << i << ' ';
//    cout << ln;
//
//    for (auto& i : b) cout << i << ' ';
//    cout << ln;


    for (auto& i : inds) {
      for (ll j = start; j < min(q, start + len); j++) {
        if (i >= Q[j].fi.fi && i <= Q[j].fi.se) a[i] += Q[j].se.fi + (Q[j].se.se * (i - Q[j].fi.fi));
        if (a[i] >= f[i]) {
          a[i] = b[i];
          ans[i] = j + 1;
          break;
        }
      }
    } a = b;

  } for (auto& i : ans) cout << i << ' ';
  cout << ln;

}