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

ll gcd(ll a, ll b) {
  if (b == 0) return a;
  else return gcd(b, a % b);
}

int main() {
  fast_cin();

  ll a, b;
  cin >> a >> b;
  if (a == b && a != 1) {
    cout << -1 << ln;
    return 0;
  }

  if (b >= a * 2) {
    cout << a << ln;
    return 0;
  }

  set <ll> pos;
  v64 can(a * a + 1, false);
  for(ll i = a; i <= min(sz(can) - 1, b); i++) {
    pos.insert(i);
    can[i] = true;
  } for(ll i = a; i < sz(can); i++) {
    for(auto& j : pos) {
      if (i + j < sz(can)) {
        can[i + j] = true;
        pos.insert(i + j);
      } else break;
    }
  } for (ll i = sz(can) - 1; i >= 0; i--) {
    if (!can[i]) {
      cout << i + 1 << ln;
//      return 0;
      break;
    }
  } // for (auto& i : can) {
//    if (i) cout << 1 << ' ';
//    else cout << 0 << ' ';
//  }


}