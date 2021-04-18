#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  ll n, k;
  cin >> n >> k;
  vector <ll> nums(n);
  vector <ll> queries(k);
  for (auto &i : nums) cin >> i;
  for (ll i = 0; i < k; i++) {
    ll m;
    cin >> m;
    if (binary_search(nums.begin(), nums.end(), m)) cout << "YES\n";
    else cout << "NO\n";
  }
}
