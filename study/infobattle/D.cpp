#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  ll n, m, k;
  cin >> n >> m >> k;
  vector <vector <ll>> a(n, vector <ll> (m));
  for (ll i = 0; i < n; i++) {
    for (ll j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }

  ll x = n - 1;
  ll y = 0;

  pair <ll, ll> ans = {-1, -1};

  while (x >= 0 || y < m) {
    if (x < 0 || y >= m) break;
    if (a[y][x] == k) {
      ans = {x + 1,y + 1};
      break;
    } else if (a[y][x] > k) x--;
    else if (a[y][x] < k) y++;
  }

  if (ans.first == -1) {
    cout << "Not Found!" << endl;
  } else cout << ans.first << ' ' << ans.second << endl;


}