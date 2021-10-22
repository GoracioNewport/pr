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
  vector <event> a(n);
  vector <event> left;
  vector <ld> ans(k);
  for (auto& i : a) {
    cin >> i.x >> i.color;
    i.x = l - i.x;
    char c;
    cin >> c;
    if (c == 'L') i.dir = RIGHT;
    else {
      ans[i.color - 1] += i.x;
      left.pb(i);
      i.dir = LEFT;
    }
  }

  v64 buf(k); ll prev = 0;
  for(ll i = 0; i < sz(left) - 1; i++) {
    buf[(left[i].color + prev) % k] += left[i + 1].x - left[i].x;
    prev += left[i + 1].color;
  } if (sz(left)) buf[(left.back().color + prev) % k] += l - left.back().x;

  for (auto& i : a) {
    if (i.dir == LEFT) {

    }
  }

  for (auto&i : ans) cout << fixed << setprecision(1) << i << ln;
}