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

  ll n, k;
  cin >> n >> k;
  v64 a(n);
  for (auto& i : a) cin >> i;

  vector <bitset <32>> b(n);
  forn(i,n) b[i] = bitset <32> (a[i]);

  bitset <32> K(k);
  string s = K.to_string();

//  cout << s << ln;

  vector <bool> has(n);
  vector <bool> banned(n);

  unordered_map <ll, ll> z;

  ll ind;
  forn(i,32) {
    ind = i;
    if (s[i] == '1') break;
  } // cout << ind << ln;

  forn(i,n) {
    string q = b[i].to_string();
    ll x = b[i].to_ullong();
    forn(j,ind) {
      if (q[j] == '1') {
        if (z[x >> (32 - ind)] != 0) {
          banned[i] = true;
        } else z[x >> (32 - ind)] = i + 1;
      }
    }
  }

  for (auto& i : z) has[i.se - 1] = true;

  bool gotOne = false, gotZero = false;

  forn(i,n) {
    if (has[i] || banned[i]) continue;
    string q = b[i].to_string();
    if (q[ind] == '1' && !gotOne) {
      gotOne = true;
      has[i] = true;
    }  if (q[ind] == '0' && !gotZero) {
      gotZero = true;
      has[i] = true;
    }
  }

  ll ans = 0;
  forn(i,n) if (has[i]) ans++;

  if (ans < 2) {
    cout << -1 << ln;
    return 0;
  } cout << ans << ln;

  forn(i,n) if (has[i]) cout << i + 1 << ' ';

}