#include<bits/stdc++.h>
using namespace std;
#define ll long long 

int main() {
  ll n;
  cin >> n;
  for (int i = 0; i < (1 << n); i++) {
    for (int j = n - 1; j >= 0; j--) {
      if (i & (1 << j)) cout << 1;
      else cout << 0;
    } cout << endl;
  }
}