 #pragma GCC optimize("Ofast")
 #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
 #pragma GCC optimize("unroll-loops")
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

struct block {
  ll sum;
  ll id;
  bool operator< (const block &o) const {
    return sum < o.sum;
  }
};

int main() {
  fast_cin();

  ll t;
  cin >> t;
  while(t--) {
    ll n, m, x;
    cin >> n >> m >> x;
    v64 a(n);
    for (auto &i : a) cin >> i;
    vv64 inds(m, v64());
    multiset <block> s;
    forn(i,m) {
      block b;
      b.sum = a[i];
      b.id = i;
      s.insert(b);
      inds[i].pb(i);
    } forsn(i,m,n) {
      block b = *s.begin();
      s.erase(s.begin());
      b.sum += a[i];
      inds[b.id].pb(i);
      s.insert(b);
    } v64 ans(n, 0);
    ll ind = 1;
    for (auto &i : inds) {
      for (auto &j : i) ans[j] = ind;
      ind++;
    }
    ll maxSum = -INF;
    ll minSum = INF;
    for (auto &i : s) {
      maxSum = max(maxSum, i.sum);
      minSum = min(minSum, i.sum);
    } if (maxSum - minSum > x) cout << "NO" << ln;
    else {
      cout << "YES" << ln;
      for (auto &i : ans) cout << i << ' ';
      cout << ln;
    }
  }


}