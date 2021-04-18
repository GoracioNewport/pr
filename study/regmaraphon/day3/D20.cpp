#include <bits/stdc++.h>
using namespace std;
#define ll long long

enum { END, BEGIN };

int main() {
  ll n, k;
  cin >> n;
  vector <pair <ll, ll>> lines(n);
  for(auto &i : lines) cin >> i.first >> i.second;
  // sort(lines.begin(), lines.end());
  cin >> k;
  for(int z = 0; z < k; z++) {
    ll ans = 1;
    ll x;
    cin >> x;
    x--;
    for(int i = 0; i < (1 << n); i++) {
      vector <ll> used(n, 0);
      for(int j = 0; j < n; j++) {
        if ((1 << j) & i) used[j] = 1;
      } used[x] = 1;
      // for (auto &i : used) cout << i << ' ';
      // cout << endl;
      vector <pair <ll, ll>> curCords;
      vector <pair <ll, ll>> curLines;
      for (int j = 0; j < n; j++) {
        if (used[j]) {
          curLines.push_back(lines[j]);
          curCords.push_back({lines[j].first, BEGIN});
          curCords.push_back({lines[j].second, END});
        }
      } bool f = false;
      for (int i = 0; i < curLines.size(); i++) {
        for (int j = i; j < curLines.size(); j++) {
          ll x1 = curLines[i].first;
          ll y1 = curLines[i].second;
          ll x2 = curLines[j].first;
          ll y2 = curLines[j].second;
          // cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl;
          if ((x1 < x2 && y1 > y2) || (x1 > x2 && y1 < y2)) f = true;
        }
      } // cout << f << endl; 
      sort(curCords.begin(), curCords.end());
      // ll balance = 0;
      for (int i = 0; i < (curCords.size() / 2); i++) {
        if (curCords[i].second == END) f = true;
      } 

      if (!f) {
        // cout << "Found answer\n";
        // for (auto &j : curLines) cout << j.first << ' ' << j.second << endl;
        ans = max(ans, (ll)curLines.size());
      }
    } cout << ans << endl;
  }
}