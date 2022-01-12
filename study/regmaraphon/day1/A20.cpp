#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF = 2e18;

int main() {
  ll a, b;
  cin >> a >> b;
  pair <ll, ll> ans = {INF, INF};
  for(ll x = 2; x <= 5000; x++) {
    for(ll y = 2; y <= 5000; y++) {
      if (y > x && y % x == 0 && (a % x == b % y)) {
        if (x < ans.first || (x == ans.first && y < ans.second)) {
          ans.first = x;
          ans.second = y;
        }
      }
    }
  } if (ans.first == INF) {
    ans.first = -1;
    ans.second = -1;
  } cout << ans.first << ' ' << ans.second << endl;
}