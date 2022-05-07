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

  ll cntA = 0, cntB = 0, cntC = 0;

  for (ll i = a; i <= b; i++) {
    string s = to_string(i);
    if (sz(s) < 3) ans++;
    else {
      ll d = (s[1] - s[0] + 10) % 10;
      bool good = true;
      forn(j,sz(s) - 1) {
        if ((s[j + 1] - s[j] + 10) % 10 != d) good = false;
      } if (good) {
        ans++;
        if (i < (ll)pow(10, sz(A))) {
//          cout << i << ln;
          cntA++;
        }
        else if (i >= (ll)pow(10, sz(B) - 1)) cntC++;
        else cntB++;
      }
    }
  }
  return ans;
}

ll cnt(string& A, string& B) {
  ll ans = 0;
  if (sz(A) == 1) ans = B[0] - A[0] + 1;
  else {
    for (ll a0 = A[0] - '0'; a0 <= B[0] - '0'; a0++) {
      if (a0 > (A[0] - '0') && a0 < (B[0] - '0')) {
        ans += 10;
        continue;
      } if (a0 < (A[0] - '0') || a0 > (B[0] - '0')) continue;
      if (a0 == (A[0] - '0') && A[0] == B[0]) {
        for (ll a1 = 0; a1 < 10; a1++) { // зайдем сюда, только если a0 == A[0] && a0 == B[0]
          ll d = (a1 + 10 - a0) % 10;


          ll type = 0;
          if (a1 > (A[1] - '0')) type = 1; // нужно чекать только Б
          else if (a1 < (B[1] - '0')) type = 2; // только А

          if (A[1] == B[1]) {
            if (a1 != (A[1] - '0')) continue;
            type = 0;
          }
//          cout << a0 << ' ' << a1 << ' ' << type << ln;


          if (type == 0) {
            if (a1 > (A[1] - '0') && a1 < (B[1] - '0')) {
              ans++;
              continue;
            } if (a1 < (A[1] - '0') || a1 > (B[1] - '0')) continue;
          } else if (type == 1) {
            if (a1 < (B[1] - '0')) {
              ans++;
              continue;
            } if (a1 > (B[1] - '0')) continue;
          } else {
            if (a1 > (A[1] - '0')) {
              ans++;
              continue;
            } if (a1 < (A[1] - '0')) continue;
          }

          ll prev = a1;
          bool good = true;

          for (ll i = 2; i < sz(A); i++) {
            ll cur = (prev + d + 10) % 10;
            if (type == 0) {
              if (cur > (A[i] - '0') && cur < (B[i] - '0')) break;
              if (cur < (A[i] - '0') || cur > (B[i] - '0')) good = false;
              if (a1 > (A[i] - '0')) type = 1; // нужно чекать только Б
              else if (a1 < (B[i] - '0')) type = 2; // только А
            } else if (type == 1) {
              if (cur < (B[i] - '0')) break;
              if (cur > (B[i] - '0')) good = false;
            } else {
              if (cur > (A[i] - '0')) break;
              if (cur < (A[i] - '0')) good = false;
            } prev = cur;
          } if (good) ans++;
        }
      } else if (a0 == (A[0] - '0')) {
        for (ll a1 = 0; a1 < 10; a1++) { //
          ll d = (a1 + 10 - a0) % 10;
          if (a1 > (A[1] - '0')) {
            ans++;
            continue;
          } if (a1 < (A[1] - '0')) continue;
          ll prev = a1;
          bool good = true;
          for (ll i = 2; i < sz(A); i++) {
            ll cur = (prev + d + 10) % 10;
            if (cur > (A[i] - '0')) break;
            if (cur < (A[i] - '0')) good = false;
            prev = cur;
          } if (good) ans++;
        }
      } else if (a0 == (B[0] - '0')) {
        for (ll a1 = 0; a1 < 10; a1++) { //
          ll d = (a1 + 10 - a0) % 10;
          if (a1 < (B[1] - '0')) {
            ans++;
            continue;
          } if (a1 > (B[1] - '0')) continue;
          ll prev = a1;
          bool good = true;
          for (ll i = 2; i < sz(A); i++) {
            ll cur = (prev + d + 10) % 10;
            if (cur < (B[i] - '0')) break;
            if (cur > (B[i] - '0')) good = false;
            prev = cur;
          } if (good) ans++;
        }
      }

    }
  }
  return ans;
}

mt19937_64 rng(chrono::high_resolution_clock().now().time_since_epoch().count());

int main() {
  fast_cin();

  string A, B;
  cin >> A >> B;


//  cout << solveStupid(A, B) << ln;
  ll ans;
  if (sz(A) == sz(B)) ans = cnt(A, B);
  else {
    string s1, s2 = "1";
    forn(i, sz(A)) s1 += '9';
    forn(i, sz(B) - 1) s2 += '0';
    ans = cnt(A, s1) + cnt(s2, B);
  }
  if (sz(B) - sz(A) > 1) ans += ((sz(B)) - (sz(A) + 1)) * 90;
  cout << ans << ln;

} // 46575 46811