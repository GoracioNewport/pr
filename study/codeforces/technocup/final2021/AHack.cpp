#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector <ll> v64;
typedef vector <v64> vv64;

#define INF 2e18(ll)
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define ln '\n'
#define sz(a) (a).size()

ll solveMy(ll a, ll b) {
  return a * b;
}

ll solveHack(ll a, ll b) {
  return 3 * a * b + 2 * a - 1;
}

int main() {
  forsn(i,1,10001) {
    forsn(j,1,10001) {
      if (solveMy(i,j) != solveHack(i,j)) {
        cout << "Countertest found" << ln;
        cout << i << ' ' << j << ln;
        cout << solveMy(i,j) << ln;
        cout << solveHack(i,j) << ln;
        exit(0);
      }
    }
  } cout << "Countertest not found" << ln;
}