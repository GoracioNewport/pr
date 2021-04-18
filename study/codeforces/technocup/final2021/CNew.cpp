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

bool comp(pair <pair <ll,ll>, v64> &a, pair <pair <ll,ll>, v64> &b) {
  return a.fi.se < b.fi.se;
}


int main() {
//  ios_base::sync_with_stdio(false);
//  cin.tie(NULL);
//  cout.tie(NULL);

  ll t;
  cin >> t;
  while (t--) {
    ll n, m;
    cin >> n >> m;
    vector <pair <pair <ll,ll>, vector <ll>>> p(m); // ind, n;
    forn(i, m) {
      ll N;
      cin >> N;
      p[i].fi.fi = i;
      p[i].fi.se = N;
      forn(z, N) {
        ll x;
        cin >> x;
        p[i].se.push_back(x);
      }
    }

    bool a1 = true, a2 = true;
    vector <pair <ll,ll>> ans1, ans2;
    sort(p.begin(), p.end(), comp);
    ll limit = m / 2;
    if (m % 2) limit++;

    { // ans1
      map <ll, ll> used;
      forn(i,sz(p)) {
        ll selected = 0;
        if (sz(p[i].se) == 1) selected = 0;
        else {
          if (used[p[i].se[0]] < limit) selected = 0;
          else selected = 1;
        } used[p[i].se[selected]]++;
        ans1.push_back({p[i].se[selected], p[i].fi.fi});
      } for (auto &i : used) if (i.se > limit) a1 = false;
    }

    { // ans2
      map <ll, ll> used;
      forn(i,sz(p)) {
        ll last = sz(p[i].se) - 1;
        ll selected = 0;
        if (sz(p[i].se) == 1) selected = 0;
        else {
          if (used[p[i].se[last]] < limit) selected = last;
          else selected = last - 1;
        } used[p[i].se[selected]]++;
        ans2.push_back({p[i].se[selected], p[i].fi.fi});
      } for (auto &i : used) if (i.se > limit) a2 = false;
    }

    if (a1 || a2) {
      cout << "YES" << ln;

      v64 ans(m);
      if (a1) for (auto &i : ans1) ans[i.se] = i.fi;
      else for (auto &i : ans2) ans[i.se] = i.fi;
      for (auto &i : ans) cout << i << ' ';
      cout << ln;
    } else {
      cout << "NO" << ln;
    }
  }
}