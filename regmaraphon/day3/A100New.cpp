#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  ll n;
  cin >> n;
  vector <ll> a(n);
  for (auto &i : a) cin >> i;
  
  vector <ll> one(n + 1, 0);
  vector <ll> two(n + 1, 0);
  vector <ll> thr(n + 1, 0);
  vector <ll> mor(n + 1, 0);

  one[1] = (a[0] == 1 ? 1 : 0);
  two[1] = (a[0] == 2 ? 1 : 0);
  thr[1] = (a[0] > 2 ? 1 : 0);
  mor[1] = (a[0] > 1 ? 1 : 0);

  for (int i = 1; i < n; i++) {
    one[i + 1] = one[i];
    two[i + 1] = two[i];
    thr[i + 1] = thr[i];
    mor[i + 1] = mor[i];

    if (a[i] == 1) one[i + 1]++;
    if (a[i] == 2) two[i + 1]++;
    if (a[i] > 2) thr[i + 1]++;
    if (a[i] > 1) mor[i + 1]++;
  }

  ll q;
  cin >> q;
  while(q--) {
    ll l, r;
    cin >> l >> r;
    ll len = r - l + 1;
    l--;
    bool allMoreOne = (mor[r] - mor[l] == len);
    ll cntOne = (one[r] - one[l]);
    ll cntTwo = (two[r] - two[l]);
    ll cntMor = (thr[r] - thr[l]);
    if (allMoreOne || (cntOne > 0 && cntTwo > 0)) cout << 1 << '\n';
    else cout << 2 << '\n';
  }

}