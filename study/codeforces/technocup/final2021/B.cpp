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


int main() {
  ll t;
  cin >> t;
  while(t--) {
    ll n;
    cin >> n;
    v64 a(n);
    for (auto &i : a) cin >> i;
    ll posC = -1;
    forsn(i,1,n) {
      if (a[i] > a[i - 1]) {
        posC = a[i] - a[i - 1];
        break;
      }
    } if (posC == -1) {
      ll x = a[0] - a[1];
      bool good = true;
      forsn(i,1,n) if (a[i - 1] - a[i] != x) good = false;
      cout << (good ? 0 : -1) << ln;
      continue;
    } ll posM = -1;
    forsn(i,1,n) {
      if (a[i] < a[i - 1]) {
        posM = a[i - 1] - a[i] + posC;
        break;
      }
    } if (posM == -1) {
      ll x = a[0] - a[1];
      bool good = true;
      forsn(i,1,n) if (a[i - 1] - a[i] != x) good = false;
      cout << (good ? 0 : -1) << ln;
      continue;
    } v64 newA = {a[0] % posM};
    forn(i,n - 1) newA.push_back((a[i] + posC) % posM);
    if (newA == a) cout << posM << ' ' << posC << ln;
    else cout << -1 << ln;
  }
}