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

// mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
mt19937 rng(0);

ll n, m, c;
vv64 p;

void fill() {
  for (auto &i : p) for (auto &j : i) j = rng() % c;
}

bool check() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      v64 s;
      v64 r;
      // cout << i << ' ' << j << endl;
      for (int I = i + 1; I < n; I++) if (p[i][j] == p[I][j]) s.pb(I);
      for (int J = j + 1; J < m; J++) if (p[i][j] == p[i][J]) r.pb(J);
      // for (auto &i : s) cout << i << ' ';
      // cout << endl;
      // for (auto &i : r) cout << i << ' ';
      // cout << endl;
      for (auto &I : s) for (auto &J : r) if (p[i][j] == p[I][J]) return false;
    }
  } return true;
}

int main() {
  fast_cin();

  vector <vector <ll>> ans2 = {
    {1, 2, 1, 2},
    {2, 1, 2, 1},
    {1, 1, 2, 2},
    {2, 2, 1, 1},
    {2, 1, 1, 2},
    {1, 2, 2, 1}
  };

  vector <vector <ll>> ans3 = {
    {1, 1, 2, 2, 3, 3},
    {2, 2, 3, 3, 1, 1},
    {3, 3, 1, 1, 2, 2},
    {1, 2, 3, 1, 2, 3},
    {2, 3, 1, 2, 3, 1},
    {3, 1, 2, 3, 1, 2}
  };
  
  cin >> n >> m >> c;
  p.resize(n, v64 (m, 0));

  if (c == 2) {
    if (n <= 4 && m <= 6) {
      for (int j = 0; j < n; j++) {
        for (int i = 0; i < m; i++) {
          cout << ans2[i][j] << ' ';
        } cout << ln;
      } return(0);
    } else if (n <= 6 && m <= 4) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          cout << ans2[i][j] << ' ';
        } cout << ln;
      } return(0);
    } else if (n == 2 || m == 2) {
      if (n == 2) {
        for (int i = 0; i < m; i++) {
          if (i % 2) cout << 1 << ' ' << 2 << ln;
          else cout << 2 << ' ' << 1 << ln;
        }
      } else {
        for (int i = 0; i < n; i++) {
          if (i % 2) cout << 1 << ' ';
          else cout << 2 << ' ';
        } cout << ln;
        for (int i = 0; i < n; i++) {
          if (i % 2 == 0) cout << 1 << ' ';
          else cout << 2 << ' ';
        }
      } return(0);
    }
  } 
  // if (c == 3) {
  //   if (n <= 6 && m <= 6) {
  //     for (int i = 0; i < n; i++) {
  //       for (int j = 0; j < m; j++) {
  //         cout << ans3[i][j] << ' ';
  //       } cout << ln;
  //     } return(0);
  //   } else if (n == 3 || m == 3) {
  //     if (m == 3) {
  //       for (int i = 0; i < n; i++) {
  //         if (i % 2) cout << 1 << ' ' << 2 << ' ' << 3 << ln;
  //         else cout << 2 << ' ' << 3 << ' ' << 1 << ln;
  //       }
  //     } else {
  //       for (int i = 0; i < m; i++) {
  //         if (i % 3 == 0) cout << 1 << ' ';
  //         else if (i % 3 == 1) cout << 2 << ' ';
  //         else cout << 3 << ' ';
  //       } cout << endl;
  //       for (int i = 0; i < m; i++) {
  //         if (i % 3 == 0) cout << 2 << ' ';
  //         else if (i % 3 == 1) cout << 3 << ' ';
  //         else cout << 3 << ' ';
  //       } cout << endl;
  //       for (int i = 0; i < m; i++) {
  //         if (i % 3 == 0) cout << 3 << ' ';
  //         else if (i % 3 == 1) cout << 1 << ' ';
  //         else cout << 2 << ' ';
  //       } cout << endl;
  //     } return(0);
  //   }
  // }

  while (true) {
    fill();
    // cout << "AAA" << endl;
    if (check()) {
      for (auto &i : p) {
        for (auto &j : i) {
          cout << j + 1 << ' ';
        } cout << ln;
      } break;
    } 
  }


}
