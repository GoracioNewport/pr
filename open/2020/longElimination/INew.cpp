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
typedef vector<vector<p32> > vvp32;
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

int gcd(int a, int b) {
  if (b == 0) return a;
  else return gcd(b, a % b);
}

ll ans = 0;
v64 used;
vvp64 p;
ll last;

void dfs(ll v, ll d, ll o) {
  if (d == 1) return;
  ans += d;
  last--;
  used[v] = o;
  for (auto &i : p[v]) if (used[i.fi] != o) dfs(i.fi, gcd(d, i.se), o);
}

bool prime (ll n) {
  if (n == 1) return false;
  for (ll i = 2; i * i <= n; i++) if (n % i == 0) return false;
  return true;
}


int main() {
  fast_cin();
  
  int n;
  cin >> n;
  p.resize(n, vp64());
  used.resize(n, -1);
  bool allPrime = true;
  ll totalSum = 0;
  forn(i,n - 1) {
    ll x, y, w;
    cin >> x >> y >> w;
    if (!prime(w)) allPrime = false;
    totalSum += w;
    x--;
    y--;
    p[x].pb({y,w});
    p[y].pb({x,w});
  } last = n * n;
  // if (allPrime) cout << (totalSum * 2) + ((n - 2) * (n - 1)) << ln;
  // else {
    forn(i,n) dfs(i,0,i);
    cout << ans + last << ln;
  // }
}
