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

int main() {
  fast_cin();
  ll t;
  cin >> t;
  for (ll k = 0; k < t; k++) {
    ll n;
    cin >> n;

    vector <ll> div;
    map <ll, ll> d;

    for (ll i = 2; (i * i) <= n; i++) {
      // cout << i << " " << n << endl;
      while (n % i == 0) {
        // cout << i << endl;
        div.pb(i);
        n /= i;
      }
    } if (n > 1) div.pb(n);
    for (auto &i : div) {
      d[i]++;
    } ll prev = INF;
    ll f = false;
    for (auto &i : d) {
      if (i.se > prev) f = true;
      prev = i.se;
    } if (!f) {
      vector <ll> ans;
      prev = INF;
      ll mul = 1;
      for (auto &i : d) {
        if (prev != INF) {
          mul *= i.se;
          for (ll j = 0; j < (d[prev] - i.se); j++) {
            ans.pb(mul);
          }
        }
        prev = i.fi;
      } for (auto &j : ans) cout << j << ' ';
      cout << endl;
    } else {
      cout << n << endl;
    }
  }
}