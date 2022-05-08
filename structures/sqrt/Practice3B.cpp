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
  
  ll n;
  cin >> n;
  v64 a(n);
  for (auto &i : a) cin >> i;
  reverse(all(a));
  ll len = 1000;
  v64 v(n, 1);
  v64 d(n / len + 1, len);
  v64 ans;
  forn(z,n) {
    // cout << "ITER " << z << ln;
    ll k = a[z];
    // cout << k << ln;
    // for (auto &i : d) cout << i << ' ';
    // cout << ln;
    ll ind;
    forn(i,sz(d)) {
      if (k < d[i]) {
        ind = i;
        break;
      } else k -= d[i];
    } ll l = ind * len;
    ll r = min(l + len, n);
    // cout << l << ' ' << r << ln;
    forsn(i,l,r) {
      if (v[i] == 1) {
        if (k == 0) {
          v[i] = 0;
          d[i / len]--;
          ans.pb(i + 1);
          // cout << "ADD " << i + 1 << ln; 
          break;
        } else k--;
      }
    }
  } reverse(all(ans));
  for (auto &i : ans) cout << n - i + 1 << ' ';
  cout << ln;

}
