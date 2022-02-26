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

    ll w, h, k, T;
    cin >> w >> h >> k >> T;

    vector <pair <p64, ll>> ans(k);

    vvp64 Wnew(w), Hnew(h);
    vector <vector <pair <p64, ll>>> W(w), H(h);

    forn(i,k) {
      ll x, y, d;
      cin >> x >> y >> d;
      if (d == 1 || d == 3) H[y].pb({{x, d}, i});
      else W[x].pb({{y, d}, i});
    }


    forn(i,w) {
      ll t = (T % (2 * h));
      sort(all(W[i]));
      for (auto& c : W[i]) {
        if (c.fi.se == 2) { // X raise
          ll t1 = h - c.fi.fi;
          ll t2 = t1 + h;

          if (t < t1) Wnew[i].pb({c.fi.fi + t, 2});
          else if (t < t2) Wnew[i].pb({h - (t - t1), 4});
          else Wnew[i].pb({t - t2, 2});

        } else {

          ll t1 = c.fi.fi;
          ll t2 = t1 + h;

          if (t < t1) Wnew[i].pb({c.fi.fi - t, 4});
          else if (t < t2) Wnew[i].pb({t - t1, 2});
          else Wnew[i].pb({h - (t - t2), 4});
        }
      }
    }

    forn(i,h) {
      ll t = (T % (2 * w));
      sort(all(H[i]));
      for (auto& c : H[i]) {
        if (c.fi.se == 1) { // Y raise
          ll t1 = w - c.fi.fi;
          ll t2 = t1 + w;

          if (t < t1) Hnew[i].pb({c.fi.fi + t, 1});
          else if (t < t2) Hnew[i].pb({w - (t - t1), 3});
          else Hnew[i].pb({t - t2, 1});

        } else {

          ll t1 = c.fi.fi;
          ll t2 = t1 + w;

          if (t < t1) Hnew[i].pb({c.fi.fi - t, 3});
          else if (t < t2) Hnew[i].pb({t - t1, 1});
          else Hnew[i].pb({ w - (t - t2), 3});
        }
      }
    }

    forn(i, w) {
      sort(all(Wnew[i]));
      ll ind = 0;
      for (auto& j : Wnew[i]) ans[W[i][ind++].se] = {{i, j.fi}, j.se};
    } forn(i, h) {
      sort(all(Hnew[i]));
      ll ind = 0;
      for (auto& j : Hnew[i]) ans[H[i][ind++].se] = {{j.fi, i}, j.se};
    }

    for (auto& i : ans) cout << i.fi.fi << ' ' << i.fi.se << ' ' << i.se << ln;










  }