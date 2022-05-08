#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  string s;
  vector <char> p;
  while (cin >> s) {
    for (int i = 0; i < s.size(); i++) p.push_back(s[i]);
  } ll n = p.size();
  vector <map <char, pair <ll, ll>>> l(n, map <char, pair <ll, ll>> ());
  ll len = 0;
  map <char, pair <ll, ll>> prev;
  const string alphabet = "abcdefghijklmnopqrstuvwxyz";
  for (auto &i : alphabet) prev[i] = {0, 0};
  for (int i = n - 1;  i >= 0; i--) {
    l[i] = prev;
    for(auto &j : l[i]) j.second.first += j.second.second;
    l[i][p[i]].second++;
    prev = l[i];
  } ll ans = 0;

  // for (int i = 0; i < n; i++) {
  //   cout << "--------------" << i + 1 << endl;
  //   for (auto &j : l[i]) {
  //     cout << j.first << " - " << j.second.first << ' ' << j.second.second << endl;
  //   }
  // }

  for (int i = 0; i < n; i++) ans += l[i][p[i]].first - (l[i][p[i]].second - 1);
  cout << ans << endl;
}