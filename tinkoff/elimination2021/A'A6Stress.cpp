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


ll solve(ll n, ll m, ll q, vector <pair <pair <ld, ld>, ll>>& a) {
  ll ans = 0;
  forn(i,m) {
    if (DEBUG) cout << " --- Line: " << i << ln;
    ll ind = q;
    set <pair <ld, ld>> d; // { cord, move };
    d.insert({0, ind});
    d.insert({n, INF});

    for (auto &j : a) {
      ind--;
      if (abs(i - j.fi.fi) > j.se) continue;
      ld D = sqrtl((j.se * j.se) - ((i - j.fi.fi) * (i - j.fi.fi)));

      ll lX = ceil(j.fi.se - D);
      ll rX = floor(j.fi.se + D);

      auto X = *prev(d.upper_bound({rX + 1, INF}));
      d.erase(d.upper_bound({lX, -INF}), d.upper_bound({rX + 1, INF}));

      d.insert({lX, ind});
      d.insert({rX + 1, X.se});

      if (DEBUG) {
        cout << "Circle: " << j.fi.fi << ' ' << j.fi.se << ' ' << j.se << ln;
        cout << "Set: " << ln;
        for (auto &i : d) cout << '{' << i.fi << ',' << i.se << "} ";
        cout << ln;
      }

    }
    vp64 D;
    for (auto &i : d) D.pb(i);
    ll locAns = 0;
    forn(k, sz(D) - 1) {
      locAns += D[k].se * (D[k + 1].fi - D[k].fi);
      if (DEBUG) {
        cout << "Add: " << D[k].se * (D[k + 1].fi - D[k].fi) << ln;
      }
    } ans += locAns;
    if (DEBUG) cout << "Line Ans: " << locAns << ln;
  } return ans;
}

ll solveStupid(ll n, ll m, ll q, vector <pair <pair <ld, ld>, ll>>& a) {
  vv64 M(m, v64(n, 0));
  for (auto &k : a) {
    forn(i,m) forn(j,n) M[i][j]++;

    forn(i,m) {
      forn(j,n) {
        if (((i + 1) - k.fi.fi) * ((i + 1) - k.fi.fi) + ((j + 1) - k.fi.se) * ((j + 1) - k.fi.se) <= k.se * k.se) M[i][j] = 0;
      }
    }
  } ll ans = 0;
  for(auto &i : M) for (auto &j : i) ans += j;
//  for (auto &i : M) {
//    for (auto &j : i) cout << j << ' ';
//    cout << ln;
//  }
  return ans;
}

mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

int main() {
  fast_cin();

//  ll n, m, q;
//  cin >> n >> m >> q;
//  vector <pair <pair <ld, ld>, ll>> a(q);

//  for (auto &i : a) cin >> i.fi.fi >> i.fi.se >> i.se;
//  cout << solve(n, m, q, a) << ln;
//  cout << solveStupid(n,m,q,a);

  while (true) {
    ll n = rng() % 10 + 1;
    ll m = rng() % 10 + 1;
    ll q = rng() % 5 + 1;
    vector <pair <pair <ld, ld>, ll>> a(q);

    for (auto &i : a) {
      i.fi.fi = rng() % (n - 2) + 2;
      i.fi.se = rng() % (m - 2) + 2;
      i.se = rng() % min(n, m) + 1;
      if (i.se > min(i.se, (ll)min(min(i.fi.fi - 1, i.fi.se - 1), min(n - i.fi.fi, m - i.fi.se)))) i.se = 1;
    } ll ans = solve(n, m, q, a);
    ll ansStupid = solveStupid(n, m, q, a);
    if (ans != ansStupid) {
      cout << "COUNTERTEST FOUND" << ln;
      cout << "YOUR ANSWER: " << solve(n, m, q, a) << ln;
      cout << "RIGHT ANSWER: " << solveStupid(n, m, q, a) << ln;
      cout << n << ' ' << m << ln << q << ln;
      for (auto &i : a) cout << i.fi.fi << ' ' << i.fi.se << ' ' << i.se << ln;
      return 0;
    }

  }


}