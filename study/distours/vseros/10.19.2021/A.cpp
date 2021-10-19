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

ll solveStupid(string A, string B) {
  ll a = stoll(A), b = stoll(B);
  ll ans = 0;
  for (ll i = a; i <= b; i++) {
    string s = to_string(i);
    if (sz(s) < 3) ans++;
    else {
      ll d = (s[1] - s[0] + 10) % 10;
      bool good = true;
      forn(j,sz(s) - 1) {
        if ((s[j + 1] - s[j] + 10) % 10 != d) good = false;
      } if (good) ans++;
    }
  } return ans;
}

int main() {
  fast_cin();

  string A, B;
  cin >> A >> B;

  ll ans = 0;

  // [a; 10^(sz(a) - 1)
  for (ll a0 = 1; a0 <= 9; a0++) {
    if (sz(A) == 1) {
      ans += 10 - (A[0] - '0');
      cout << ans << ln;
      break;
    }


    if (a0 < (A[0] - '0') || (sz(A) == sz(B) && a0 > (B[0] - '0'))) continue;
    for (ll d = 0; d <= 9; d++) {
      ll prev = a0;
      bool good = true;
      for (ll i = 1; i < sz(A); i++) {
        ll cur = (prev + d + 10) % 10;
        if (cur < (A[i] - '0') || (sz(A) == sz(B) && cur > (B[i] - '0'))) {
          good = false;
          break;
        } prev = cur;
      } if (good) ans++;
    }
  } // sz(A) + 1, sz(B)

  cout << ans << ln;

//  if (sz(B) - (sz(A) + 1) == 0) ans++;
  if (sz(B) - (sz(A) + 1) > 0) ans += ((sz(B)) - (sz(A) + 1)) * 90 - 1;

  cout << ans << ln;

  for (ll a0 = 1; a0 <= (B[0] - '0'); a0++) {
    if (sz(A) == sz(B)) break;
    for (ll d = 0; d <= 9; d++) {
      ll prev = a0;
      bool good = true;
      for (ll i = 1; i < sz(B); i++) {
        ll cur = (prev + d + 10) % 10;
        if (cur > (B[i] - '0')) {
          good = false;
          break;
        } prev = cur;
      } if (good) ans++;
    }
  } cout << ans << ln;


}