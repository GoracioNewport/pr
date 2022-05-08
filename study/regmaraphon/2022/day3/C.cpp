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

struct r {
  ld x, y;
  r() {};
  r(ld x, ld y): x(x), y(y) {};
};

ld operator^(r a, r b) {  // Векторное произведение
  return a.x * b.y - a.y * b.x;
}

int main() {
  fast_cin();

  ll t;
  cin >> t;
  while(t--) {

    vector <r> triangle(3), column(3);

    for (auto& i : triangle) cin >> i.x >> i.y;
    for (auto& i : column) cin >> i.x >> i.y;

    triangle.pb(triangle[0]);

    v64 perm(3);
    iota(all(perm), 0);

    r r1(triangle[1].x - triangle[0].x, triangle[1].y - triangle[0].y);
    r r2(triangle[2].x - triangle[0].x, triangle[2].y - triangle[0].y);
    ld S = abs(r1 ^ r2) / 2;

    pair <ld, v64> ans = {-INF, {}};

    do {

      r ra1(triangle[perm[0]].x - column[0].x, triangle[perm[0]].y - column[0].y);
      r rb1(triangle[perm[0] + 1].x - column[0].x, triangle[perm[0] + 1].y - column[0].y);
      ld S1 = abs(ra1 ^ rb1) / 2;

      r ra2(triangle[perm[1]].x - column[1].x, triangle[perm[1]].y - column[1].y);
      r rb2(triangle[perm[1] + 1].x - column[1].x, triangle[perm[1] + 1].y - column[1].y);
      ld S2 = abs(ra2 ^ rb2) / 2;

      r ra3(triangle[perm[2]].x - column[2].x, triangle[perm[2]].y - column[2].y);
      r rb3(triangle[perm[2] + 1].x - column[2].x, triangle[perm[2] + 1].y - column[2].y);
      ld S3 = abs(ra3 ^ rb3) / 2;

      ans = max(ans, {S1 + S2 + S3, perm});

    } while(next_permutation(all(perm)));

    cout << ans.se[0] + 1 << ' ' << ans.se[1] + 1 << ' ' << ans.se[2] + 1 << ln;

  }

}