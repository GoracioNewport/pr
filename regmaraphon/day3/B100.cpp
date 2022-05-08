#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll n, m;

vector <vector <ll>> p;
vector <vector <ll>> used;
vector <vector <ll>> points;

ll dfs(ll x, ll y, ll len) {
  // cout << x << ' ' << y << endl;
  used[x][y] = ++len;
  // cout << used[x][y] << endl;;
  ll ans = len;
  if (x != 0 && p[x - 1][y] == p[x][y] + 1) {
    if (used[x - 1][y] < len) used[x - 1][y] = 0;
    if (!used[x - 1][y]) ans = max(ans, dfs(x - 1, y, len));
  } if (x != n - 1 && p[x + 1][y] == p[x][y] + 1) {
    if (used[x + 1][y] < len) used[x + 1][y] = 0;
    if (!used[x + 1][y]) ans = max(ans, dfs(x + 1, y, len));
  } if (y != 0 && p[x][y - 1] == p[x][y] + 1) {
    if (used[x][y - 1] < len) used[x][y - 1] = 0;
    if (!used[x][y - 1]) ans = max(ans, dfs(x, y - 1, len));
  } if (y != m - 1 && p[x][y + 1] == p[x][y] + 1) {
    if (used[x][y + 1] < len) used[x][y + 1] = 0;
    if (!used[x][y + 1]) ans = max(ans, dfs(x, y + 1, len));
  } return ans;
}

int main() {
  cin >> n >> m;
  p.resize(n, vector <ll> (m));
  used.resize(n, vector <ll> (m, 0));
  points.resize(n, vector <ll> (m, 0));
  for (auto &i : p) for (auto &j : i) cin >> j;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      bool left = (j == 0 || p[i][j - 1] != (p[i][j] - 1));
      bool right = (j == m - 1 || p[i][j + 1] != (p[i][j] - 1));
      bool up = (i == 0 || p[i - 1][j] != (p[i][j] - 1));
      bool down = (i == n - 1 || p[i + 1][j] != (p[i][j] - 1));
      if (left + right + up + down == 4) points[i][j] = true;
    }
  } ll ans = 0;
  // for (auto &i : points) {
  //   for (auto &j : i) cout << j << ' ';
  //   cout << endl;
  // }
  // cout << "HI" << endl;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      // cout << i << ' ' << j << endl;
      if (!points[i][j]) continue;
      for (int I = 0; I < n; I++) for (int J = 0; J < m; J++) used[I][J] = 0;
      // cout << i << ' ' << j << endl;
      ans = max(ans, dfs(i, j, 0));
    }
  } cout << ans << endl;

}