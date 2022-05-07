#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ln '\n'

int main() {
  ll n;
  cin >> n;
  vector <ll> a(n);
  for (auto &i : a) cin >> i;
  ll q;
  cin >> q;

  vector <ll> dp(n + 1, 0);
  vector <ll> dpT(n + 1, 0);
  vector <ll> dpW(n + 1, 0);
  dp[1] = (a[0] == 1 ? 1 : 0);
  dpW[1] = (a[0] == 2 ? 1 : 0);
  dpT[1] = (a[0] > 2 ? 1 : 0);
  for(int i = 1; i <= n; i++) {
    dp[i] = dp[i - 1];
    dpW[i] = dpW[i - 1];
    dpT[i] = dpT[i - 1];
    if (a[i - 1] == 1) dp[i]++;
    if (a[i - 1] == 2) dpW[i]++;
    if (a[i - 1] > 2) dpT[i]++;
  } 
 
  // for (auto &i : dp) cout << i << ' ';
  // cout << endl;

  // for (auto &i : dpW) cout << i << ' ';
  // cout << endl;

  // for (auto &i : dpT) cout << i << ' ';
  // cout << endl;

  for(int z = 0; z < q; z++) {
    ll l, r;
    cin >> l >> r;
    ll len = r - l + 1;
    l--;
    bool allTwo = (dpW[r] - dpW[l] == len);
    bool allGr = (dpT[r] - dpT[l] == len);
    bool all = (((dp[r] - dp[l]) > 0 && (dpW[r] - dpW[l]) > 0 && (dpT[r] - dpT[l]) > 0));
    // cout << l << ' ' << r << ' ' << len << endl;
    // cout << allTwo << ' ' << allGr << ' ' << all << endl;

    if (allTwo || allGr || all) cout << 1 << ln;
    else cout << 2 << ln;
  }
}