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

ll gcd (ll a, ll b) {
  if (b == 0) return a;
  else return gcd(b, a % b);
}

int main() {
  fast_cin();

  ll n;
  cin >> n;
  ll s = 1;
  v64 divs(n, 0);
  divs[1] = 1;
  ll x = n * n;
  forsn(i,2,n) {
    if (gcd(n,i) == 1) {
      divs[i] = 1;
      s = (s * i) % x;
   }
  } if (s % n != 1) {
    divs[s % n] = 0;
    s /= (s % n);
  }
  ll ind = 0;
  v64 Ans;
  for (auto &i : divs) {
    if (i) Ans.pb(ind);
    ind++;
  } cout << sz(Ans) << ln;
  for (auto &i : Ans) cout << i << ' ';

}