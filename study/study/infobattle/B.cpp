#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  ll n;
  cin >> n;
  vector <ll> a(2*n);

  for (ll i = 0; i < n; i++) {
    cin >> a[i];
    a[i + n] = a[i];
  }

  ll leftSize = n / 2;
  ll rightSize = n - leftSize;

  vector <ll> prefSum(2 * n + 1);

  for (ll i = 0; i < 2 * n; i++) {
    prefSum[i + 1] = prefSum[i] + a[i];
  }

  ll left = 0, right = 0;

  for (ll i = 0; i < leftSize; i++) {
    left += (prefSum[i + 1] - prefSum[0]);
  }

  for (ll i = n - 1; i > leftSize; i--) {
    right += (prefSum[n] - prefSum[i]);
  }

  ll ans = left + right;

  for (ll i = leftSize; i < n + leftSize; i++) {

    left += (prefSum[i + 1] - prefSum[i - leftSize]);
    left -= a[i - leftSize] * (leftSize + 1);

    right += a[i + rightSize] * rightSize;
    right -= (prefSum[i + rightSize + 1] - prefSum[i + 1]);


    ans = min(ans, left + right);
  }

  cout << ans << endl;

}