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

//ll gcd(ll a, ll b) {
//  if (b == 0) return a;
//  else return gcd(b, a % b);
//}

ll x;
bool good;
void f(ll a, ll b) {

  if (good || a == 0 || b == 0) return;

//  if (min(a, b) == 1) {
//    if (x <= max(a, b)) good = true;
//    return;
//  }

  ll y = max(a, b) % min(a, b);
//  cout << a << ' ' << b << ' ' << y << ln;
  if (y == 0) {
    if (x % min(a, b) == 0 && x <= max(a, b)) good = true;
    return;
  }
  if ((x - y) % min(a, b) == 0 && x <= max(a, b)) good = true;

  f(min(a, b), y);
}

int main() {
  fast_cin();

  ll t;
  cin >> t;
  while(t--) {
    ll a, b;
    cin >> a >> b >> x;
    good = false;
    f(a, b);
    cout << (good ? "YES" : "NO") << ln;
  }
}