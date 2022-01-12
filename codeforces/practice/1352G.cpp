//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
//#pragma GCC optimize("unroll-loops")
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

  ll t;
  cin >> t;
  while(t--) {
    ll n;
    cin >> n;

    if (n <= 3) cout << -1 << ln;
    else {
      for (ll i = 1; i < (n / 4) * 4 - 4; i += 4) {
        cout << i + 1 << ' ' << i + 3 << ' ' << i << ' ' << i + 2 << ' ';
      } if (n % 4 == 0) cout << n - 2 << ' ' << n << ' ' << n - 3 << ' ' << n - 1 << ' ';
      else if (n % 4 == 1) cout << n - 3 << ' ' << n - 1 << ' ' << n - 4 << ' ' << n - 2 << ' ' << n << ' ';
      else if (n % 4 == 2) cout << n - 5 << ' ' << n - 3 << ' ' << n - 1 << ' ' << n - 4 << ' ' << n - 2 << ' ' << n << ' ';
      else cout << n - 5 << ' ' << n - 2 << ' ' << n - 6 << ' ' << n - 4 << ' ' << n - 1 << ' ' << n - 3 << ' ' << n << ' ';
      cout << ln;
    }
  }

}