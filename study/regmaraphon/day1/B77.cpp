#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector <vector <pair <ll, char>>> p;
vector <ll> used;
vector <ll> indAns;
string edgAns;
string m1 = "aa";
string m2 = "bb";
string m3 = "abab";


void dfs(ll v, vector <ll> ind, string edg) {

  // cout << edg << endl;
  // for (auto &i : ind) cout << i << ' ';
  // cout << endl;
  if (ind.size() > 2) {
    // cout << edg.substr(edg.size() - 2) << endl;
    if (edg.substr(edg.size() - 2) == m1) {
      indAns.clear();
      for(int i = ind.size() - 3; i < ind.size(); i++) indAns.push_back(ind[i]);
      // for (auto &i : indAns) cout << i << ' ';
      edgAns = edg;
    } if (edg.substr(edg.size() - 2) == m2) {
      indAns.clear();
      for(int i = ind.size() - 3; i < ind.size(); i++) indAns.push_back(ind[i]);
      edgAns = edg;
    }
  } if (ind.size() > 4) {
    if (edg == m3) {
      indAns.clear();
      // cout << "HI\n";
      for(int i = ind.size() - 5; i < ind.size(); i++) indAns.push_back(ind[i]);
      edgAns = edg;
    }
  }

  used[v] = 1;
  for(auto &i : p[v]) {
    ll u = i.first;
    char c = i.second;
    if (!used[u]) {
      // cout << "NOT USED" << endl;
      vector <ll> newInd = ind;
      string newEdg = edg;
      newInd.push_back(u);
      newEdg += c;
      vector <ll> rawInd;
      string rawEdg;
      if (newInd.size() > 5) for (int i = newInd.size() - 5; i < newInd.size(); i++) rawInd.push_back(newInd[i]);
      else rawInd = newInd;
      if (newEdg.size() > 4) rawEdg = newEdg.substr(newEdg.size() - 4);
      else rawEdg = newEdg;
      dfs(u, rawInd, rawEdg);
    }
  }
}

int main() {
  ll n, m;
  cin >> n >> m;
  p.resize(n, vector <pair <ll, char>> (0));
  used.resize(n, 0);
  for(int i = 0; i < m; i++) {
    ll x, y;
    char z;
    cin >> x >> y >> z;
    x--;
    y--;
    p[x].push_back({y, z});
    p[y].push_back({x, z});
  } for(int i = 0; i < n; i++) {
    if (edgAns.size() > 1) break;
    // cout << "DFS" << i << endl;
    for(int j = 0; j < n; j++) used[j] = 0;
    dfs(i, {i}, "");
  } if (edgAns.size() == 0) cout << -1 << endl;
  else {
    cout << indAns.size() << endl;
    for (auto &i : indAns) cout << i + 1 << ' ';
    cout << endl;
  }
}