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

  ll n, m;
  cin >> n >> m;
  vector <bool> a(n);
  string s;
  cin >> s;
  forn(i,n) a[i] = (s[i] == 'W');

  ll ans = 0;
  for (ll i = 0; i < n; i++) { // вершина р/б треугольника
    for (ll d = 1; d < n; d++) {
      if ((i - d + n) % n == (i + d + n) % n) continue;
      if (a[i] == a[(i - d + n) % n] && a[i] == a[(i + d + n) % n]) ans++;
    }
  }
  if (n % 3 == 0) {
    for (ll i = 0; i < n / 3; i++) {
      if (a[i] == a[i + (n / 3)] && a[i + (n / 3)] == a[i + 2 * (n / 3)]) ans -= 4;
    }
  }

  while(m--) {
    ll i;
    cin >> i; i--;

    for (ll d = 1; d < n; d++) {
      if ((i - d + n) % n == (i + d + n) % n) continue;
      if (a[i] == a[(i - d + n) % n] && a[i] == a[(i + d + n) % n]) ans--;
    } for (ll v = 0; v < n; v++) {
      ll d = abs(i - v);
      if ((v - d + n) % n == (v + d + n) % n) continue;
      if (a[v] == a[(v - d + n) % n] && a[v] == a[(v + d + n) % n]) ans -= 2;
    } if ((n % 3 == 0) && (a[i] == a[(i + (n / 3)) % n]) && (a[(i + (n / 3)) % n] == a[(i + 2 * (n / 3)) % n])) ans += 4;

    a[i] = !a[i];

    for (ll d = 1; d < n; d++) {
      if ((i - d + n) % n == (i + d + n) % n) continue;
      if (a[i] == a[(i - d + n) % n] && a[i] == a[(i + d + n) % n]) ans++;
    } for (ll v = 0; v < n; v++) {
      ll d = abs(i - v);
      if ((v - d + n) % n == (v + d + n) % n) continue;
      if (a[v] == a[(v - d + n) % n] && a[v] == a[(v + d + n) % n]) ans += 2;
    } if ((n % 3 == 0) && a[i] == a[(i + (n / 3)) % n] && a[(i + (n / 3)) % n] == a[(i + 2 * (n / 3)) % n]) ans -= 4;
    cout << ans / 2 << ln;
  }

}