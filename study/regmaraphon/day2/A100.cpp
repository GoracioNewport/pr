#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF = 2e18;


struct point {
  ll maxUp = 0;
  ll maxDown = 0;
  ll minLeft = 0;
  ll minRight = 0;
};

int main() {
  ll n, m;
  cin >> n >> m;
  vector <vector <char>> p;
  vector <vector <point>> ps;
  p.resize(n, vector <char> (m));
  ps.resize(n, vector <point> (m));
  for (auto &i : p) for (auto &j : i) cin >> j;

  // cout << "ROW, UP - DOWN" << endl;

  for (int j = 0; j < m; j++) {
    ps[0][j].maxUp = 0;
  }
  
  for (int j = 0; j < m; j++) {
    for (int i = 1; i < n; i++) {
      ll a = (p[i - 1][j] == '+' ? 1 : -1);
      ps[i][j].maxUp = ps[i - 1][j].maxUp + a;
    }
  }

  // cout << "ROW, DOWN - UP" << endl;

  for (int j = 0; j < m; j++) {
    ps[n - 1][j].maxDown = 0;
  }
  
  for (int j = 0; j < m; j++) {
    for (int i = n - 2; i >= 0; i--) {
      ll a = (p[i + 1][j] == '+' ? 1 : -1);
      ps[i][j].maxDown = ps[i + 1][j].maxDown + a;
    }
  }

  // cout << "LINE, LEFT - RIGHT" << endl;

  for (int i = 0; i < n; i++) {
    ps[i][0].minLeft = 0;
  }
  
  for (int i = 0; i < n; i++) {
    for (int j = 1; j < m; j++) {
      ll a = (p[i][j - 1] == '+' || p[i][j - 1] == '?' ? 1 : -1);
      ps[i][j].minLeft = ps[i][j - 1].minLeft + a;
    }
  }

  // cout << "LINE, RIGHT - LEFT" << endl;

  for (int i = 0; i < n; i++) {
    ps[i][m - 1].minRight = 0;
  }
  
  for (int i = 0; i < n; i++) {
    for (int j = m - 2; j >= 0; j--) {
      ll a = (p[i][j + 1] == '+' || p[i][j + 1] == '?' ? 1 : -1);
      ps[i][j].minRight = ps[i][j + 1].minRight + a;
    }
  } 


  ll ans = -INF;
  for (auto &i : ps) {
    for (auto &j : i) {
      ans = max(ans, ((j.minLeft + j.minRight) - (j.maxUp + j.maxDown)));
    }
  } cout << ans << endl;

  // for (auto &i : ps) {
  //   for (auto &j : i) {
  //     cout << j.maxUp << ' ';
  //   } cout << endl;
  // }
  
  // vector <ll> maxL;
  // vector <ll> maxR;
  // vector <ll> sumL(n);
  // vector <ll> sumR(m);
  // ll ma = -INF;
  // ll mi = INF;
  // for(int i = 0; i < n; i++) {
  //   ll s = 0;
  //   for(int j = 0; j < m; j++) {
  //     if (p[i][j] == '+' || p[i][j] == '?') s++;
  //     else s--;
  //   } ma = max(s, ma);
  //   sumL[i] = s;
  // } for (int i = 0; i < n; i++) if (sumL[i] == ma) maxL.push_back(i);
  // for(int j = 0; j < m; j++) {
  //   ll s = 0;
  //   for(int i = 0; i < n; i++) {
  //     if (p[i][j] == '-' || p[i][j] == '?') s--;
  //     else s++;
  //   } mi = min(s, mi);
  //   sumR[j] = s;
  // } for (int i = 0; i < m; i++) if (sumR[i] == mi) maxR.push_back(i);

  // ll ans = -INF;

  // for (auto &i : maxL) cout << i << ' ';
  // cout << endl;
  
  // for (auto &i : maxR) cout << i << ' ';
  // cout << endl;

  // for (auto &i : sumL) cout << i << ' ';
  // cout << endl;

  // for (auto &i : sumR) cout << i << ' ';
  // cout << endl;

  // for (int i = 0; i < maxL.size(); i++) {
  //   for (int j = i; j < maxR.size(); j++) {
  //     ll x = maxL[i];
  //     ll y = maxR[j];
  //     cout << x << ' ' << y << endl;
  //     cout << ps[x][y].maxUp << ' ' << ps[x][y].maxDown << ' ' << ps[x][y].minLeft << ' ' << ps[x][y].minRight << ' ' << endl;
  //     for (auto &i : ps) {
  //       for (auto &j : i) {
  //         cout << j.maxUp << ' ';
  //       } cout << endl;
  //     }
  //     ans = max(ans, ((ps[x][y].minLeft + ps[x][y].maxDown) - (ps[x][y].minLeft + ps[x][y].minRight)));
  //   }
  // } cout << ans << endl;
  

}