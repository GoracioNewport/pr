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

  ll t;
  cin >> t;
  while(t--) {
    ll n;
    cin >> n;
    v64 b(n);
    for (auto& i : b) cin >> i;
    bool good = true;

    if (n == 1) {
      cout << "YES" << ln;
      cout << b[0] << ln;
      continue;
    }

    ll sumB = 0;
    for (auto& i : b) sumB += i;
    ll sumA = sumB / ((n + 1) * n / 2);
    if (sumB % ((n + 1) * n / 2) != 0) good = false;
    if (sumA < 1) good = false;

    v64 ans(n);

    for(ll i = n - 1; i > 0; i--) {
      ans[i] = (b[i - 1] + sumA - b[i]) / n;
      if ((b[i - 1] + sumA - b[i]) % n != 0) good = false;
    }

    ans[0] = (b.back() + sumA - b[0]) / n;
    if (((b.back() + sumA - b[0]) % n != 0)) good = false;


    ll mi = ans[0];
    for (auto& i : ans) mi = min(mi, i);
    if (mi < 1) good = false;

    if (!good) cout << "NO" << ln;
    else {
      cout << "YES" << ln;
      for (auto& i : ans) cout << i << ' ';
      cout << ln;
    }

  }

}
