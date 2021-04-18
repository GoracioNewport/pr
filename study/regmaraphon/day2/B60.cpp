#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  string s;
  vector <char> p;
  while (cin >> s) {
    for (int i = 0; i < s.size(); i++) p.push_back(s[i]);
  } ll ans = 0; 
  for (int i = 0; i < p.size(); i++) {
    for (int j = i + 1; j < p.size(); j++) {
      if (p[i] == p[j]) ans += j - i - 1;
    }
  } cout << ans << endl;
}