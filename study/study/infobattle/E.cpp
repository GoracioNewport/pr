#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  ll n;
  cin >> n;
  vector <ll> a(n);
  for (auto &i : a) cin >> i;
  ll p = -1;
  ll cnt = 0;
  for (auto &i : a) {
    if (cnt == 0) {
      p = i;
      cnt++;
    } else {
      if (i == p) cnt++;
      else cnt--;
    }
  } cout << p << endl;
}