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

  ll t;
  cin >> t;
  while(t--) {
    string a, b;
    cin >> a >> b;
    reverse(all(a));
    reverse(all(b));

    bool can = true;
    string ans = "";


    ll ind = 0;
    for (ll i = 0; i < sz(a); i++) {
      if (ind >= sz(b)) {
        can = false;
        break;
      }

      ll x = (a[i] - '0');
      ll z = (b[ind] - '0');

      if (x <= z) {
        ll y = z - x;
        ans.pb(y + '0');
      } else {
        ll y = z + 10 - x;
        ans.pb(y + '0');
        ind++;

        if (ind >= sz(b) || b[ind] != '1') {
          can = false;
          break;
        }

      } ind++;
    } reverse(all(ans));

    if (can) {

      ll x = stoll(ans);
      ans = to_string(x);
      cout << ans << ln;
    } else cout << -1 << ln;


  }

}