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

enum {BEGIN, END};

int main() {
  fast_cin();
  
  ll n, m;
  cin >> n >> m;
  vp64 c;
  vp64 q;
  forn(i,m) {
    ll l, r;
    cin >> l >> r;
    l--;
    c.pb({l, BEGIN});
    c.pb({r, END});
    q.pb({l, r});
  } sort(all(c));
  v64 p(n);
  ll ind = 0;
  ll cnt = 0;
  ll z = 0;
  forn(i,n) {
    while (ind < (2 * m) && c[ind].fi == i) {
      if (c[ind].se) cnt--;
      else cnt++;
      ind++;
    } p[i] = cnt;
    if (p[i] == 0) z++;
  } v64 pR(n + 1, 0);
  pR[1] = (p[0] == 1 ? 1 : 0);
  // for (auto &i : p) cout << i << ' ';
  // cout << endl;
  forsn(i,2,n + 1) pR[i] = (pR[i - 1] + (p[i - 1] == 1));
  // for (auto &i : pR) cout << i << ' ';
  // cout << endl;
  for (auto &i : q) {
    cout << (pR[i.se] - pR[i.fi]) + z << ln;
  }
  


}
