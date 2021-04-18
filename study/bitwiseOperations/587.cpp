#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  ll n, m;
  cin >> n >> m;
  ll ans = (1 << (n * m));
  for (int i = 0; i < (1 << (n * m)); i++) {
    vector <vector <ll>> p(n, vector <ll> (m, 0));
    for (int j = 0; j < (n * m); j++) {
      if (i & (1 << j)) p[j % n][j / n] = 1;
    }

    // for (auto &i : p) {
    //   for (auto &j : i) {
    //     cout << j << ' ';
    //   } cout << endl;
    // }

    for (int x = 0; x < n - 1; x++) {
      for (int y = 0; y < m - 1; y++) {
        if (((p[x][y] == p[x + 1][y]) && (p[x + 1][y] == p[x][y + 1]) && (p[x][y + 1] == p[x + 1][y + 1]))) { 
          ans--;
          x = n;
          break;
        }
      }
    }
  } cout << ans << endl; 
}