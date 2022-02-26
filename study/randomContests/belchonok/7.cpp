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

  ll n = 100;

  for (ll A = 4; A <= 100; A++) {
    for (ll B = 4; B <= 100; B++) {
      for (ll C = 5; C <= 100; C++) {
        if (A >= B || A >= C) continue;

        ll x = (ll)pow(A, 3) + 3 * (ll)pow(A, 2) + 2 * (ll)pow(A, 1) + 2;
        ll y = (ll)pow(B, 3) + (ll)pow(B, 2) + A * (ll)pow(B, 1) + 3;
        ll z = 4 * (ll)pow(C, 2) + 3 * (ll)pow(C, 1) + A * (ll)pow(C, 0);

        if (x + y == z) {
          cout << x << ' ' << y << ' ' << z << ln;
          cout << A << ' ' << B << ' ' << C << ln << ln;
        }
      }
    }
  }

}