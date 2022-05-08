// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
// #pragma GCC optimize("unroll-loops")
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

vector <p64> p;

bool findAns(p64 x, p64 y) {
  vector <p64> d;
  ll a = x.se - y.se;
  ll b = y.fi - x.fi;
  ll c = ((x.fi * y.se) - (x.se * y.fi));
  for (auto &i : p) if ((a * (i.fi)) + (b * (i.se) + c) != 0) d.pb(i);
  // for (auto &i : d) cout << i.fi << ' ' << i.se << endl;
  if (sz(d) >= 3) {
    auto x1 = d[0], y1 = d[1];
    a = x1.se - y1.se;
    b = y1.fi - x1.fi;
    c = ((x1.fi * y1.se) - (x1.se * y1.fi));
    for (auto &i : d) if ((a * (i.fi)) + (b * (i.se) + c) != 0) return false;
  } return true;
}

bool findAnsK1 (p64 x, p64 y) {
  vector <p64> d;
  ll a = x.se - y.se;
  ll b = y.fi - x.fi;
  ll c = ((x.fi * y.se) - (x.se * y.fi));
  bool ok = true;
  for (auto &i : p) if ((a * (i.fi)) + (b * (i.se) + c) != 0) ok = false;
  return ok;
}

int main() {
  fast_cin();

  ll t;
  cin >> t;
  while (t--) {
    ll n, k;
    cin >> n >> k;
    p.resize(n);
    for (auto &i : p) cin >> i.fi >> i.se;
    bool ans = true;
    // if (n > 3) {
      if (k == 2) {
        bool ans1 = findAns(p[0], p[1]);
        bool ans2 = findAns(p[1], p[2]);
        bool ans3 = findAns(p[0], p[2]);
        if (!ans1 && !ans2 && !ans3) ans = false;
        if (ans) {
          vector <pair <pair <ll, ll>, pair <ll,ll>>> ansV;
          if (ans1) ansV.pb({p[0], p[1]});
          if (ans2) ansV.pb({p[1], p[2]});
          if (ans2) ansV.pb({p[0], p[2]});
        }
      } else if (k == 1) {
        ans = findAnsK1(p[0], p[1]);
        if (ans) {
          cout << "Yes\n1\n";
          cout << p[0].fi << ' ' << p[0].se << ' ' << p[1].fi << ' ' <<p[1].se << '\n';
        } else cout << "No\n";
      } else cout << "No\n";
    // }
  }
}
