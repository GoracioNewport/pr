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
const ll mod1 = 1000000087, k1 = 61;

ll n;
string s1;
string s2;
v64 ks;
v64 ks1;
v64 h1;
v64 h11;
v64 h2;
v64 h21;

ll subhash(v64 &h, ll l, ll r) {
  l++; r++;
  return ((h[r] - ((h[l - 1] * ks[r - l + 1]) % mod) + mod) % mod);
}

ll subhash1(v64 &h, ll l, ll r) {
  l++; r++;
  return ((h[r] - ((h[l - 1] * ks1[r - l + 1]) % mod1) + mod1) % mod1);
}


int main() {
  fast_cin();

  cin >> n >> s1 >> s2;
  ks.resize(n + 1, 1);
  h1.resize(n + 1, 0);
  h2.resize(n + 1, 0);
  ks1.resize(n + 1, 1);
  h11.resize(n + 1, 0);
  h21.resize(n + 1, 0);
  forn(i,n) {
    ks[i + 1] = (ks[i] * k) % mod;
    ks1[i + 1] = (ks1[i] * k1) % mod1;
    ll x = (s1[i] - 'a' + 1);
    ll y = (s2[i] - 'a' + 1);
    h1[i + 1] = (((h1[i] * k) % mod) + x) % mod;
    h2[i + 1] = (((h2[i] * k) % mod) + y) % mod;
    h11[i + 1] = (((h11[i] * k1) % mod1) + x) % mod1;
    h21[i + 1] = (((h21[i] * k1) % mod1) + y) % mod1;
  } ll l = 0;
  ll r = n + 1;
  p64 ans = {-1, -1};
  while(l + 1 < r) {
    ll len = (l + r) / 2;
    vp64 hs;
    forn(i,n - len + 1) hs.pb({subhash(h1, i, i + len - 1), subhash1(h11, i, i + len - 1)});
    sort(all(hs));
    bool good = false;
    forn(i,n - len + 1) {
      p64 hh2 = {subhash(h2, i, i + len - 1), subhash1(h21, i, i + len - 1)};
      if (binary_search(hs.begin(), hs.end(), hh2) && len > ans.fi) {
        good = true;
        ans.fi = len;
        ans.se = i;
      }
    } if (good) l = len;
    else r = len;
  } if (ans.fi != -1) forsn(i, ans.se, ans.se + l) cout << s2[i];
  cout << ln;


}