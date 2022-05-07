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
    ll first = lower_bound(nums.begin(), nums.end(), m) - nums.begin();
    ll last = first;
    if (first != n) {
      while (nums[first] != nums[last + 1] && last < (n - 1)) last++;
      cout << first + 1 << " " << last + 1 << "\n";
    } else {
      cout << "0\n";
    }
  }
}
