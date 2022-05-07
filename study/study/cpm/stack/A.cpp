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

  ll n;
  cin >> n;
  stack <p64> numbers;
  numbers.push({0, 1});
  ll M = ((ll)1 << 32) - 1;
  bool overflow = false;
//  cout << M << ln << INT_MAX << ln;
  forn(z,n) {
    string s;
    cin >> s;
    if (s[0] == 'f') {
      ll x; cin >> x;
      numbers.push({0, x});
    } else if (s[0] == 'e') {
      auto q = numbers.top();
      numbers.pop();
      auto p = numbers.top();
      numbers.pop();
      p.fi += q.fi * q.se;
      numbers.push(p);
    } else {
      auto q = numbers.top();
      numbers.pop();
      q.fi++;
      numbers.push(q);
    } if (numbers.top().fi > M) overflow = true;
  } ll ans = numbers.top().fi;
  if (overflow) cout << "OVERFLOW!!!" << ln;
  else cout << ans << ln;


}