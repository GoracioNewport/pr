#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

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

vp64 p;

pair <bool, vector <pair <p64, p64>>> f(vp64 r, ll k) {

  // cout << "FUNC " << k << endl;
  // for (auto &i : r) cout << i.fi << ' ' << i.se << endl; 
  
  if (k == 0) {
    if (sz(r) == 0) return {true, {}};
    else return {false, {}};
  }

  if (sz(r) <= k * 2) {
    if (sz(r) == 1) {
      if (p[0] == r[0]) return {true, {{p[0], {p[0].fi + 1, p[0].se + 1}}}};
      else return {true, {{p[0], r[0]}}};

    } else {
      vector <pair <p64, p64>> ans;
      for (int i = 1; i < sz(r); i += 2) ans.pb({r[i - 1], r[i]});
      if (sz(r) % 2) ans.pb({r.back(), r[0]});
      return {true, ans}; 
    }
  } else {
    vp64 lr;
    pair <bool, vector <pair <p64, p64>>> res = {false, {}};
    for (int i = 0; i < k + 1; i++) lr.pb(r[i]);
    for (int i = 0; i < sz(lr); i++) {
      for (int j = i + 1; j < sz(lr); j++) {
        vp64 n;
        auto x = lr[i];
        auto y = lr[j];
        ll a = x.se - y.se;
        ll b = y.fi - x.fi;
        ll c = ((x.fi * y.se) - (x.se * y.fi));
        for (auto &i : r) if ((a * (i.fi)) + (b * (i.se) + c) != 0) n.pb(i);
        res = f(n, k - 1);
        if (res.fi) { 
          res.se.pb({x,y});
          break;
        }
      } if (res.fi) break;
    } return res;
  }
}

int main() {
  fast_cin();
  
  ll t;
  cin >> t;
  while(t--) {
    ll n, k;
    cin >> n >> k;
    p.resize(n);
    for (auto &i : p) cin >> i.fi >> i.se;
    auto ans = f(p, k);
    if (ans.fi) {
      cout << "Yes\n";
      cout << sz(ans.se) << ln;
      for (auto &i : ans.se) cout << i.fi.fi << ' ' << i.fi.se << ' ' << i.se.fi << ' ' << i.se.se << ln;
    } else cout << "No\n";
  }  

}
