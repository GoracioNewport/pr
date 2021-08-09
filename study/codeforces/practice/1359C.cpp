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

bool DEBUG = false;

ld calcOddTemp(ld m, ld h, ld c) {
  ld M = 2 * m + 1;
  ld temp = (((ll)M / 2) * c + ((ll)M / 2 + 1) * h) / M;
  return temp;
}

ll calcOdd(ll h, ll c, ll t) {
  ll l = 0;
  ll r = 1e9;

  while(l + 1 < r) {
    ld m = (l + r) / 2;
    ld temp = calcOddTemp(m, h, c);
    if (temp > t) l = m;
    else r = m;
  } return 2 * l + 1;
}

int main() {
  fast_cin();

  ll t;
  cin >> t;
  while(t--) { // c < h
    if (DEBUG) cout << setprecision(5) << fixed << "-----------" << ln;
    ld h, c, t;
    cin >> h >> c >> t;

    ld evenAns = (h + c) / 2;
    ll oddCnt = calcOdd(h,c,t);
    ld oddAns1 = ((oddCnt / 2) * c + (oddCnt / 2 + 1) * h) / oddCnt;
    oddCnt += 2;
    ld oddAns2 = ((oddCnt / 2) * c + (oddCnt / 2 + 1) * h) / oddCnt;

    ll oddAns;
    if (abs(oddAns1 - t) > abs(oddAns2 - t)) oddAns = oddAns2;
    else {
      oddAns = oddAns1;
      oddCnt -= 2;
    }

    if (DEBUG) {
      ll MAX_TEST = 10;
      cout << "Odd Temp:" << ln;
      for(ll i = 0; i <= MAX_TEST; i++) {
        cout << i << " -> " << calcOddTemp(i, h, c) << endl;
      }
    }

    if (DEBUG) cout << evenAns << ' ' << oddCnt << ' ' << oddAns << ' ' << ln;

    if (DEBUG) {
      cout << "FINAL RESULT:" << ln;
      cout << oddCnt << ' ' << calcOddTemp(oddCnt / 2, h, c) << ln;
    }



    if (!(t <= ((h + c) / 2))) {
      cout << oddCnt << ln;
    } else cout << 2 << ln;


  }

}