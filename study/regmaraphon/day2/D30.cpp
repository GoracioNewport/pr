#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll n, m;
vector <vector <ll>> p;
vector <vector <ll>> used;
pair <ll,ll> curLords = {-1,-1};
 
void dfs(ll i, ll j, ll &cnt) {
  used[i][j] = 1;
  if (p[i][j] != curLords.first && p[i][j] != curLords.second) return;
  cnt++;
  if (i > 0 && !used[i - 1][j]) dfs(i - 1, j, cnt);
  if (i < n - 1 && !used[i + 1][j]) dfs(i + 1, j, cnt);
  if (j > 0 && !used[i][j - 1]) dfs(i, j - 1, cnt);
  if (j < m - 1 && !used[i][j + 1]) dfs(i, j + 1, cnt);
}

int main() {
  cin >> n >> m;
  p.resize(n, vector <ll> (m));
  vector <ll> lords;
  for(auto &i : p) {
    for(auto &j : i) {
      cin >> j;
      lords.push_back(j);
    }
  } sort(lords.begin(), lords.end());
  auto last = unique(lords.begin(), lords.end());
  lords.resize(last - lords.begin());
  used.resize(n, vector <ll> (m, 0));
  ll ans = 0;
  pair <ll, ll> lordsAns = {-1, -1};
  for(int i = 0; i < lords.size(); i++) {
    for (int j = i; j < lords.size(); j++) {
      // cout << lords[i] << ' ' << lords[j] << endl;
      for(int x = 0; x < n; x++) for(int y = 0; y < m; y++) used[x][y] = 0;
      curLords = {lords[i], lords[j]};
      for (int I = 0; I < n; I++) {
        for (int J = 0; J < m; J++) {
          ll cnt = 0;
          if (!used[I][J]) dfs(I, J, cnt);
          // cout << cnt << endl;
          if (cnt > ans) {
            ans = cnt;
            lordsAns = curLords;
          }
        }
      }
    }
  } cout << ans << endl;
  cout << lordsAns.first << ' ' << lordsAns.second << endl;

}