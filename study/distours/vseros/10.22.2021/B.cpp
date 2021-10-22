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

enum { LEFT, RIGHT };
struct event {
  ll x, color, dir;
};

int main() {
  fast_cin();

  ll n, k, l;
  cin >> n >> k >> l;
  vector <event> a(n), left;
  vp64 right;
  vector <ld> ans(k);

  for (auto& i : a) {
    cin >> i.x >> i.color;
    char c;
    cin >> c;
    if (c == 'L') {
      left.pb(i);
      i.dir = LEFT;
    } else {
      i.dir = RIGHT;
      ans[i.color] += l - i.x;
      right.pb({i.x, i.color});
    }
  }

  cout << fixed << setprecision(1);
//  reverse(all(left));
//  for (auto& i : left) {
//    if (sz(right)) {
//      auto it = prev(lower_bound(all(right), make_pair(i.x, (ll)0)));
//      if (it == prev(right.begin())) {
//        ans[i.color] += i.x;
//        continue;
//      }
//      ans[i.color] += ((ld)i.x - (ld)(*it).fi) / 2;
//      ll prevC = i.color;
//      for (ll j = it - right.begin(); j > 0; j--) {
//        ans[(prevC + right[j].se) % k] += ((ld)right[j].fi - (ld)right[j - 1].fi) / 2;
//        prevC = (prevC + right[j].se) % k;
//      } if (i.x > right[0].fi) ans[(prevC + right[0].se) % k] += ((ld)(i.x - right[0].fi) / 2) + (ld)right[0].fi;
//    } else ans[i.color] += i.x;
//  }

  reverse(all(a));
  for (ll c = 0; c < k; c++) {

    
    for (auto& i : a) {
      if (i.dir == RIGHT) {

      } else {

      }
    }
  }



  for (auto& i : ans) cout << i << ln;

}