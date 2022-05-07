#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector <vector <ll>> p;
vector <vector <ll>> que;
vector <ll> used;

void dfs(ll v, ll color) {
  if (used[v] != 0) return;
  used[v] = color;
  for (auto &u : p[v]) {
    if (!used[u]) que[color - 1].push_back(u);
  }
}

int main() {
  ll n, q;
  cin >> n >> q;
  p.resize(n, vector <ll> (0));
  used.resize(n, 0);
  for(int i = 0; i < n - 1; i++) {
    ll x, y;
    cin >> x >> y;
    x--;
    y--;
    p[x].push_back(y);
    p[y].push_back(x);
  } for (int z = 0; z < q; z++) {
    ll k;
    cin >> k;
    vector <ll> startPos(k);
    que.clear();
    que.resize(k, vector <ll> (0));
    for (int i = 0; i < n; i++) used[i] = 0;
    for (int i = 0; i < k; i++) {
      ll a;
      cin >> a;
      a--;
      que[i].push_back(a);
    }

    ll cnt = 1;
    while (cnt > 0) {
      cnt = 0;
      for (auto &i : que) cnt += i.size();
      vector <vector <ll>> queCopy = que;
      que.clear();
      que.resize(k, vector <ll> (0));
      for (int i = 0; i < k; i++) {
        for (int j = 0; j < queCopy[i].size(); j++) {
          dfs(queCopy[i][j], i + 1);
        }
      } 
    } ll ans = 0;
    for (auto &i : used) {
      ans += (i == 1);
    } cout << ans << endl;
  }
}