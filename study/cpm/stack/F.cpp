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

  deque <ll> l, r;
  forn(i,5) {
    ll x;
    cin >> x;
    l.push_front(x);
  } forn(i,5) {
    ll x;
    cin >> x;
    r.push_front(x);
  }

  ll cnt = 0;
  ll MAX = 1e6;
  while(sz(l) && sz(r) && cnt < MAX) {
    ll x = l.back();
    ll y = r.back();
    l.pop_back();
    r.pop_back();
    if ((x > y && !(y == 0 && x == 9)) || (x == 0 && y == 9)) {
      r.push_front(x);
      r.push_front(y);
    } else {
      l.push_front(y);
      l.push_front(x);
    } cnt++;
//    for (auto& i : l) cout << i << ' ';
//    cout << ln;
//    for (auto& i : r) cout << i << ' ';
//    cout << ln;
  } if (cnt >= MAX) cout << "botva" << ln;
  else if (sz(l)) cout << "second " << cnt << ln;
  else cout << "first " << cnt << ln;

}