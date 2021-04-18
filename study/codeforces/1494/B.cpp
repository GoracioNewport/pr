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

bool valid(ll a, ll b, ll c, ll d, ll n) {
  return ((a >= 0 && a <= n - 2) && (b >= 0 && b <= n - 2) && (c >= 0 && c <= n - 2) && (d >= 0 && d <= n - 2));
}

int main() {
  fast_cin();

  ll t;
  cin >> t;
  while(t--) {
    ll n, u, r, d, l;
    cin >> n >> u >> r >> d >> l;
    bool ans = false;
    for (ll i = 0; i < (1 << 4); i++) {
      v64 x(4);
      for (ll j = 0; j < 4; j++) if (i & (1 << j)) x[j] = 1;
      ll A = u - x[0] - x[1];
      ll B = r - x[1] - x[2];
      ll C = d - x[3] - x[2];
      ll D = l - x[0] - x[3];
      if (valid(A,B,C,D,n)) ans = true;
    } cout << (ans ? "yEs" : "nO") << ln;


  }
}