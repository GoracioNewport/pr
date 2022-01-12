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


//p64 solve(v64& a, ll k) { // <sum, min>
//  multiset <ll> q;
//  for (auto& i : a) q.insert(i);
//
//  v64 inds;
//
//  while(!q.empty()) {
//    ll ind = 1;
//    ll elem = *q.begin();
//    for (auto &i: q) {
//      if (ind > k) break;
//      elem = i;
//      ind++;
//    } inds.pb(elem);
//    auto it = q.upper_bound(elem);
//    auto jt = it;
//    forn(i,k) {
//      if (jt == q.begin()) break;
//      jt = prev(jt);
//    }
//
//    q.erase(jt, it);
//  }
//
//  return {accumulate(all(inds), 0) * 2, (sz(inds) ? inds.back() : 0) };
//
//}

p64 solve(v64& a, ll k) { // <full, short>

  sort(all(a));
  reverse(all(a));
  ll s1 = 0;
  forn(i,sz(a)) if (i % k == 0) s1 += a[i] * 2;
  reverse(all(a));


  v64 aNew;
  forn(i,sz(a) - k) aNew.pb(a[i]);
  ll s = 0;
  reverse(all(aNew));
  forn(i,sz(aNew)) if (i % k == 0) s += aNew[i] * 2;

//  cout << s1 << ' ' << s << ' ' << (sz(a) ? a.back() : 0) << ln;

  return {s1, s + (sz(a) ? a.back() : 0)};

}

int main() {
  fast_cin();

  ll t;
  cin >> t;
  while(t--) {
    ll n, k;
    cin >> n >> k;
    v64 a, b;
    forn(i,n) {
      ll x;
      cin >> x;
      if (x > 0) a.pb(x);
      if (x < 0) b.pb(-x);
    } auto x = solve(a, k);
    auto y = solve(b, k);
    cout << min(x.fi + y.se, x.se + y.fi) << ln;

  }

}