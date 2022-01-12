#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {

  freopen("circle.in", "r", stdin);
  freopen("circle.out", "w", stdout);

  ll n;
  cin >> n;
  ll x = n * (n - 1);
  if (n % 2 == 0) x -= n;
  cout << x << '\n';
}