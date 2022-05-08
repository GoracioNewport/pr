// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
// #pragma GCC optimize("unroll-loops")
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

ll ans = -1;

bool gans(ll n) {
  for (ll i = 2; i * i <= n; i++) {
    if (n % i == 0) return true;
  } return false;
}

void f(string& s, string& q) {
  if (sz(q) == sz(s)) {
    ll x = stoll(q);
    if (gans(x)) ans = x;
    return;
  } if (s[sz(q)] == '*') {
    for (char c = (sz(q) == 0 ? '1' : '0'); c <= '9'; c++) {
      q.pb(c);
      f(s, q);
      if (ans != -1) return;
      q.pop_back();
    }
  } else {
    q.pb(s[sz(q)]);
    f(s, q);
    if (ans != -1) return;
    q.pop_back();
  }
}

int main() {
  fast_cin();

  string s, q;
  cin >> s;
  f(s, q);
  cout << ans << ln;

}