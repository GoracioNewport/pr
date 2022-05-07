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

const ll mod = 1791791791, k = 239;

ll n;
string s;
v64 ks;
v64 h;

ll subhash(ll l, ll r) {
  l++;r++;
  return ((h[r] - ((h[l - 1] * ks[r - l + 1]) % mod) + mod) % mod);
}

bool suffComp(ll a, ll b) { // a < b - true, else false
  ll n1 = n - a;
  ll n2 = n - b;
  ll l = 0;
  ll r = min(n1, n2) + 1;
  while(l + 1 < r) {
    ll m = (l + r) / 2;
    if (subhash(a, a + m - 1) == subhash(b, b + m - 1)) l = m;
    else r = m;
  } if (r > min(n1, n2)) {
    if (n1 < n2) return true;
    else return false;
  } else {
    if (s[a + r - 1] < s[b + r - 1]) return true;
    else return false;
  }
}

int main() {
  fast_cin();

  cin >> n >> s;
  ks.resize(n + 1, 1);
  h.resize(n + 1, 0);
  forn(i,n) {
    ks[i + 1] = (ks[i] * k) % mod;
    ll x = (s[i] - 'a' + 1);
    h[i + 1] = (((h[i] * k) % mod) + x) % mod;
  } v64 ans(n);
  iota(ans.begin(), ans.end(), 0);
  sort(ans.begin(), ans.end(), suffComp);
  for (auto &i : ans) cout << i + 1 << ' ';
  cout << ln;
}