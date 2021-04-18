#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector <ll> v64;
typedef vector <v64> vv64;

#define INF 2e18(ll)
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define ln '\n'
#define sz(a) (a).size()
#define fi first
#define se second


int main() {
//  ios_base::sync_with_stdio(false);
//  cin.tie(NULL);
//  cout.tie(NULL);

  ll t;
  cin >> t;
  while(t--) {
    ll n, m;
    cin >> n >> m;
    vv64 p(m, v64 ());
    forn(i,m) {
      ll N;
      cin >> N;
      forn(z,N) {
        ll x;
        cin >> x;
        p[i].push_back(x);
      }
    } bool ok1 = true;
    bool ok2 = true;
    v64 ans1, ans2;
    ll limit = m / 2;
    { // ok1, first
      bool isBlocked = false;
      pair <ll,ll> blocked = {-1, 0}; // number, tiems
      map <ll,ll> used;
      forn(i,sz(p)) {
        ll selected;
        if (p[i].size() == 1) selected = 0;
        else {
          if (isBlocked && blocked.fi == p[i][0]) selected = 1;
          else selected = 0;
        } if (blocked.fi == -1) blocked.fi = p[i][selected];
        if (blocked.fi == p[i][selected]) blocked.se++;
        if (blocked.se >= limit) isBlocked = true;
        used[p[i][selected]]++;
        ans1.push_back(p[i][selected]);
      } for (auto &i : used) if (i.se > limit) ok1 = false;
    }

    { // ok2, last
      bool isBlocked = false;
      pair <ll,ll> blocked = {-1, 0}; // number, tiems
      map <ll,ll> used;
      forn(i,sz(p)) {
        if (sz(p[i]) != 1)
        ll last = sz(p[i]) - 1;
        ll selected;
        if (p[i].size() == 1) selected = 0;
        else {
          if (isBlocked && blocked.fi == p[i][last]) selected = last - 1;
          else selected = last;
        } if (blocked.fi == -1) blocked.fi = p[i][selected];
        if (blocked.fi == p[i][selected]) blocked.se++;
        if (blocked.se >= limit) isBlocked = true;
        used[p[i][selected]]++;
        ans2.push_back(p[i][selected]);
      } for (auto &i : used) if (i.se > limit) ok2 = false;
    } if (ok1 || ok2) {
      cout << "YES" << ln;
      if (ok2) for (auto &i : ans2) cout << i << ' ';
      else for (auto &i : ans1) cout << i << ' ';
      cout << ln;
    } else cout << "NO" << ln;
  }
}