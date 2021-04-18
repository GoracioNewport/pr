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
v64 ks;
v64 hs;
v64 hr;
ll n;

ll subhash(v64 &h, ll l, ll r) {
  l++; r++;
  return ((h[r] - ((h[l - 1] * ks[r - l + 1]) % mod) + mod) % mod);
}

int main() {
  fast_cin();

  string s;
  cin >> s;
  n = sz(s);
  ks.resize(n + 1, 1);
  hs.resize(n + 1, 0);
  hr.resize(n + 1, 0);
  forn(i,n) {
    ll x = (s[i] - 'a' + 1);
    ll y = (s[n - i - 1] - 'a' + 1);
    ks[i + 1] = (ks[i] * k) % mod;
    hs[i + 1] = (((hs[i] * k) % mod) + x) % mod;
    hr[i + 1] = (((hr[i] * k) % mod) + y) % mod;
  } ll q;
  cin >> q;
  while(q--) {
    ll l1, r1, l2, r2;
    cin >> l1 >> r1 >> l2 >> r2;
    l1--; r1--; l2--; r2--;
    ll n1 = (r1 - l1) + 1;
    ll n2 = (r2 - l2) + 1;
    ll l = 0;
    ll r = min(n1, n2) + 1;
    while (l + 1 < r) {
      ll m = (l + r) / 2;
//      cout << l << ' ' << r << ' ' << m << ln;
//      cout << l1 << ' ' << l1 + m << ln;
//      cout << l2 << ' ' << l2 + m << ln;
      if (subhash(hs, l1, l1 + m - 1) == subhash(hs, l2, l2 + m - 1)) l = m;
      else r = m;
    }

//    cout << r << ln;

    if (r > min(n1, n2)) {
      if (n1 == n2) cout << "=" << ln;
      else if (n1 > n2) cout << '>' << ln;
      else cout << '<' << ln;
    } else {
      if (s[l1 + r - 1] > s[l2 + r - 1]) cout << '>' << ln;
      else cout << '<' << ln;
    }
  }


}