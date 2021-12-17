//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

// Author: @GoracioNewport

using namespace std;

typedef int ll;
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

  ll n, m;
  cin >> n >> m;
  v64 a(n), b(m), ans(n, -1);
  for (auto& i : a) cin >> i;
  for (auto& i : b) cin >> i;

  reverse(all(a));
  reverse(all(b));

  vv64 pos(2e5 + 1, v64());
  forn(i,n) pos[a[i]].pb(i);

  vp64 candidates; // < begin, end >;
  for (auto& i : pos[b[0]]) candidates.pb({i,i});


  forsn(i,1,m) {
    for(auto& j : candidates) {
      auto x = lower_bound(all(pos[b[i]]), j.se);
      if (x == pos[b[i]].end()) j.se = n;
      else j.se = *x;
    } while(!candidates.empty() && candidates.back().se == n) candidates.pop_back();
  } for (auto& i : candidates) {
    i.fi = n - i.fi - 1;
    i.se = n - i.se - 1;
    swap(i.fi, i.se);
  } sort(all(candidates));

  ll ind = 0;
  forn(i,n) {
    while(ind < sz(candidates) && candidates[ind].fi < i) ind++;
    if (ind == sz(candidates)) break;
    ans[i] = candidates[ind].se + 1;
  } for (auto& i : ans) cout << i << ' ';


}