#include<bits/stdc++.h>
using namespace std;
#define ll long long 

int main() {
  ll n;
  cin >> n;
  string ans;
  for (int i = 7; i >= 0; i--) {
    // cout << n / pow(2, i) << endl; 
    if ((n >= pow(2, i))) {
      ans += '1';
      n -= pow(2, i);
    } else ans += '0';
  } cout << ans << endl;
}