#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  ios::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll n, m;
  cin >> n >> m;
  vector <vector <char>> p;
  p.resize(n, vector <char> (m));
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for(int j = 0; j < m; j++) p[i][j] = s[j];
  }
  vector <ll> maxL;
  vector <ll> maxR;
  vector <ll> sumL(n);
  vector <ll> sumR(m);
  ll ma = -m - 1;
  ll mi = n + 1;
  for(int i = 0; i < n; i++) {
    ll s = 0;
    for(int j = 0; j < m; j++) {
      if (p[i][j] == '+' || p[i][j] == '?') s++;
      else s--;
    } ma = max(s, ma);
    sumL[i] = s;
  } for (int i = 0; i < n; i++) if (sumL[i] == ma) maxL.push_back(i);
  for(int j = 0; j < m; j++) {
    ll s = 0;
    for(int i = 0; i < n; i++) {
      if (p[i][j] == '-' || p[i][j] == '?') s--;
      else s++;
    } mi = min(s, mi);
    sumR[j] = s;
  } for (int i = 0; i < m; i++) if (sumR[i] == mi) maxR.push_back(i);
  ll ans = 0;
  
  // for (auto &i : maxL) cout << i << ' ';
  // cout << endl;
  
  // for (auto &i : maxR) cout << i << ' ';
  // cout << endl;

  // for (auto &i : sumL) cout << i << ' ';
  // cout << endl;

  // for (auto &i : sumR) cout << i << ' ';
  // cout << endl;
  
  for (int i = 0; i < maxL.size(); i++) {
    for (int j = i; j < maxR.size(); j++) {
      if (p[maxL[i]][maxR[j]] == '?') {
        ans = max(ans, (sumL[maxL[i]] - sumR[maxR[j]]) - 2);
        // cout << sumL[maxL[i]] << ' ' << sum;
      } else ans = max(ans, sumL[maxL[i]] - sumR[maxR[j]]);
    }
  } cout << ans << endl;
}